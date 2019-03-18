#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <json_spirit/json_spirit_reader.h>
#include <json_spirit/json_spirit_writer.h>
#include <map>
#include <sstream>

#include "kuzzle.hpp"
#include "kuzzle_utils.h"

std::string get_login_creds(const std::string &username,
                            const std::string &password)
{
  // Write json.
  boost::property_tree::ptree pt;
  pt.put("username", username);
  pt.put("password", password);
  std::ostringstream buf;
  boost::property_tree::write_json(buf, pt, false);
  return buf.str();
}

std::string get_createUser_body(const std::string &username,
                                const std::string &password) {
  using json_spirit::Object;
  using json_spirit::Pair;
  using json_spirit::Value;

  Object body, content, creds, local;

  local.push_back(Pair("username", Value(username)));
  local.push_back(Pair("password", Value(password)));

  creds.push_back(Pair("local", Value(local)));

  json_spirit::Array profileIds;
  profileIds.push_back("default");

  content.push_back(Pair("profileIds", Value(profileIds)));
  content.push_back(Pair("name", Value(username)));

  body.push_back(Pair("content", Value(content)));
  body.push_back(Pair("credentials", Value(creds)));

  std::ostringstream buf;
  json_spirit::write_formatted(body, buf);

  return buf.str();
}

bool kuzzle_user_exists(kuzzleio::Kuzzle *kuzzle, const std::string &user_id) {
  bool user_exists = false;
  try {
    kuzzleio::kuzzle_request req = {0};
    req.controller = "security";
    req.action = "getUser";
    req.id = user_id.c_str();
    KuzzleRequest n(&req);

    kuzzle->query(n);
    user_exists = true;
  }
  catch (kuzzleio::NotFoundException e) {
    user_exists = false;
  }
  catch (kuzzleio::KuzzleException e) {
    K_LOG_W(e.what());
  }
  return user_exists;
}

void kuzzle_user_delete(kuzzleio::Kuzzle *kuzzle, const std::string &user_id)
{
  K_LOG_D("Deleting user with ID: '%s'", user_id.c_str());
  try
  {
    kuzzleio::kuzzle_request req = {0};
    req.controller = "security";
    req.action = "deleteUser";
    req.id = user_id.c_str();

    kuzzleio::query_options options;
    options.refresh = const_cast<char*>("wait_for");
    options.volatiles = const_cast<char*>("{}");
    kuzzle->query(KuzzleRequest(&req), QueryOptions(&options));  // TODO: test if we can delete with options

    K_LOG_D("Deleted user \"%s\"", user_id.c_str());
  }
  catch (kuzzleio::KuzzleException e) {
    K_LOG_E("Failed to delete user \"%s\"", user_id.c_str());
  }
}

void kuzzle_credentials_delete(
    kuzzleio::Kuzzle *kuzzle,
    const std::string &strategy,
    const std::string &user_id) {
  try {
    kuzzleio::kuzzle_request req = {0};
    req.controller = "security";
    req.action = "deleteCredentials";
    req.strategy = "local";
    req.id = user_id.c_str();

    kuzzle->query(KuzzleRequest(&req));
    //kuzzle->query(req);

    K_LOG_D("Deleted '%s' credentials for userId '%s'", strategy.c_str(),
            user_id.c_str());
  }
  catch (kuzzleio::KuzzleException e) {
    K_LOG_E("Failed to delete '%s' credentials for userId '%s'",
            strategy.c_str(), user_id.c_str());
    K_LOG_E(e.what());
  }
}

void kuzzle_user_create(kuzzleio::Kuzzle *kuzzle, const std::string &user_id,
                        const std::string &username,
                        const std::string &password) {
  kuzzleio::kuzzle_request req = {0};
  req.controller = "security";
  req.action = "createUser";
  req.strategy = "local";
  req.id = user_id.c_str();
  std::string body = get_createUser_body(username, password);
  req.body = body.c_str();

 // if (kuzzle_user_exists(kuzzle, user_id.c_str()))
  {
    K_LOG_W("An user with id: '%s' already exists, deleting it...",
            user_id.c_str());
    kuzzle_credentials_delete(kuzzle, "local", user_id);
    kuzzle_user_delete(kuzzle, user_id);
  }

    // kuzzle_credentials_delete(kuzzle, "local", user_id);

  K_LOG_D("Creating user with id: '%s' and 'local' creds: %s:%s",
          user_id.c_str(), username.c_str(), password.c_str());
  K_LOG_D("Req body: %s", req.body);
  try
  {
    KuzzleResponse resp = kuzzle->query(&req);
    K_LOG_D("createUser ended with status: %d", resp.status());
  }
  catch (kuzzleio::KuzzleException e)
  {
    K_LOG_E("Status (%d): %s", e.status(), e.what());
    if (kuzzle_user_exists(kuzzle, user_id.c_str())) {
      K_LOG_W("But user seems to exist anyway?????");
    }
  }
}

void kuz_log_sep()
{
  std::cout << "\x1b(0\x6c\x1b(B";
  for (int i = 0; i < 79; i++)
  {
    std::cout << "\x1b(0\x71\x1b(B";
  }
  std::cout << std::endl;
}

void kuz_log_e(const char *filename, int linenumber, const char *fmt...)
{
  va_list args;
  va_start(args, fmt);

  std::cerr << "\x1b(0\x78\x1b(B" << TXT_COLOR_RED << "E:";
  std::cerr << basename(filename) << ":" << linenumber << ":";
  vprintf(fmt, args);
  std::cerr << TXT_COLOR_RESET << std::endl;

  va_end(args);
}

void kuz_log_w(const char *filename, int linenumber, const char *fmt...)
{
  va_list args;
  va_start(args, fmt);
  std::cout << "\x1b(0\x78\x1b(B" << TXT_COLOR_YELLOW << "W:";
  std::cout << basename(filename) << ":" << linenumber << ":";
  vprintf(fmt, args);
  std::cout << TXT_COLOR_RESET << std::endl;

  va_end(args);
}

void kuz_log_d(const char *filename, int linenumber, const char *fmt...)
{
  va_list args;
  va_start(args, fmt);

  std::cout << "\x1b(0\x78\x1b(B" << TXT_COLOR_DEFAULT << "D:";
  std::cout << basename(filename) << ":" << linenumber << ":";
  vprintf(fmt, args);
  std::cout << TXT_COLOR_RESET << std::endl;

  va_end(args);
}

void kuz_log_i(const char *filename, int linenumber, const char *fmt...)
{
  va_list args;
  va_start(args, fmt);

  std::cout << "\x1b(0\x78\x1b(B" << TXT_COLOR_BLUE << "I:";
  std::cout << basename(filename) << ":" << linenumber << ":";
  vprintf(fmt, args);
  std::cout << TXT_COLOR_RESET << std::endl;

  va_end(args);
}
