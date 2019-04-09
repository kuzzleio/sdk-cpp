// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "kuzzle.hpp"
#include "internal/auth.hpp"

namespace kuzzleio
{
Auth::Auth(kuzzle *kuzzle)
{
  _kuzzle = kuzzle;
  _auth = kuzzle_get_auth_controller(_kuzzle);
  kuzzle_new_auth(_auth, _kuzzle);
}

Auth::~Auth()
{
  unregisterAuth(_auth);

  // do not use "delete":
  // _auth is allocated in the cgo world, using calloc
  free(_auth);
}

token_validity *Auth::checkToken(const std::string &token)
{
  return kuzzle_check_token(_auth, const_cast<char *>(token.c_str()));
}

std::string Auth::createMyCredentials(const std::string &strategy, const std::string &credentials)
{
  return this->createMyCredentials(strategy, credentials, query_options());
}

std::string Auth::createMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_create_my_credentials(_auth, const_cast<char *>(strategy.c_str()), const_cast<char *>(credentials.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;

  kuzzle_free_string_result(r);
  return ret;
}

bool Auth::credentialsExist(const std::string &strategy)
{
  return this->credentialsExist(strategy, query_options());
}

bool Auth::credentialsExist(const std::string &strategy, const query_options &options)
{
  KUZZLE_API(bool_result, r, kuzzle_credentials_exist(_auth, const_cast<char *>(strategy.c_str()), const_cast<query_options *>(&options)))

  bool ret = r->result;
  kuzzle_free_bool_result(r);
  return ret;
}

void Auth::deleteMyCredentials(const std::string &strategy)
{
  this->deleteMyCredentials(strategy, query_options());
}

void Auth::deleteMyCredentials(const std::string &strategy, const query_options &options)
{
  KUZZLE_API(error_result, r, kuzzle_delete_my_credentials(_auth, const_cast<char *>(strategy.c_str()), const_cast<query_options *>(&options)))
  kuzzle_free_error_result(r);
}

User Auth::currentUser()
{
  KUZZLE_API(user_result, r, kuzzle_get_current_user(_auth))

  User u = r->result;
  kuzzle_free_user_result(r);
  return u;
}

std::string Auth::myCredentials(const std::string &strategy)
{
  return this->myCredentials(strategy, query_options());
}

std::string Auth::myCredentials(const std::string &strategy, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_get_my_credentials(_auth, const_cast<char *>(strategy.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);
  return ret;
}

std::vector<std::shared_ptr<UserRight>> Auth::myRights()
{
  return this->myRights(query_options());
}

std::vector<std::shared_ptr<UserRight>> Auth::myRights(const query_options &options)
{
  KUZZLE_API(user_rights_result, r, kuzzle_get_my_rights(_auth, const_cast<query_options *>(&options)))

  std::vector<std::shared_ptr<UserRight>> user_rights;
  user_rights.reserve(r->rights_length);

  for (size_t i = 0; i < r->rights_length; ++i)
  {
    std::shared_ptr<UserRight> right(new UserRight(r->rights[i]));
    user_rights.push_back(std::move(right));
  }

  kuzzle_free_user_rights_result(r);
  return user_rights;
}

std::vector<std::string> Auth::strategies()
{
  return this->strategies(query_options());
}

std::vector<std::string> Auth::strategies(const query_options &options)
{
  KUZZLE_API(string_array_result, r, kuzzle_get_strategies(_auth, const_cast<query_options *>(&options)))

  std::vector<std::string> strategies = std::vector<std::string>(r->result, r->result + r->result_length);

  kuzzle_free_string_array_result(r);
  return strategies;
}

std::string Auth::login(const std::string &strategy, const std::string &credentials)
{
  KUZZLE_API(string_result, r, kuzzle_login(_auth, const_cast<char *>(strategy.c_str()), const_cast<char *>(credentials.c_str()), nullptr))

  std::string ret = r->result;
  kuzzle_free_string_result(r);
  return ret;
}

std::string Auth::login(const std::string &strategy, const std::string &credentials, int expires_in)
{
  KUZZLE_API(string_result, r, kuzzle_login(_auth, const_cast<char *>(strategy.c_str()), const_cast<char *>(credentials.c_str()), &expires_in))

  std::string ret = r->result;
  kuzzle_free_string_result(r);
  return ret;
}

void Auth::logout() noexcept
{
  kuzzle_logout(_auth);
}

void Auth::setJwt(const std::string &jwt) noexcept
{
  kuzzle_set_jwt(_kuzzle, const_cast<char *>(jwt.c_str()));
}

std::string Auth::updateMyCredentials(const std::string &strategy, const std::string &credentials)
{
  return this->updateMyCredentials(strategy, credentials, query_options());
}

std::string Auth::updateMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_update_my_credentials(_auth, const_cast<char *>(strategy.c_str()), const_cast<char *>(credentials.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);
  return ret;
}

User Auth::updateSelf(const std::string &content)
{
  return this->updateSelf(content, query_options());
}

User Auth::updateSelf(const std::string &content, const query_options &options)
{
  KUZZLE_API(user_result, r, kuzzle_update_self(_auth, const_cast<char *>(content.c_str()), const_cast<query_options *>(&options)))

  User ret = r->result;
  kuzzle_free_user_result(r);
  return ret;
}

bool Auth::validateMyCredentials(const std::string &strategy, const std::string &credentials)
{
  return this->validateMyCredentials(strategy, credentials, query_options());
}

bool Auth::validateMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options)
{
  KUZZLE_API(bool_result, r, kuzzle_validate_my_credentials(_auth, const_cast<char *>(strategy.c_str()), const_cast<char *>(credentials.c_str()), const_cast<query_options *>(&options)))

  bool ret = r->result;
  kuzzle_free_bool_result(r);
  return ret;
}
} // namespace kuzzleio
