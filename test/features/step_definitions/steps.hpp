#ifndef _STEPS_HPP_
#define _STEPS_HPP_

#include <boost/test/unit_test.hpp>
#define EXPECT_EQ BOOST_CHECK_EQUAL
#include <cucumber-cpp/autodetect.hpp>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <memory>

#include "kuzzle.hpp"
#include "websocket.hpp"

#include "kuzzle_utils.h"

#include "json_spirit/json_spirit.h"

using cucumber::ScenarioScope;
using namespace std;


struct KuzzleCtx {
  kuzzleio::Kuzzle* kuzzle = nullptr;
  kuzzleio::Protocol* protocol = nullptr;
  kuzzleio::Options kuzzle_options;

  string user_id;
  string index;
  string collection;
  string jwt;
  string document_id;
  kuzzleio::SearchResult *search_result = nullptr;
  std::vector<std::shared_ptr<kuzzleio::UserRight>> user_rights;


  std::string room_id;

  kuzzleio::User currentUser;
  json_spirit::Value_type customUserDataType = json_spirit::null_type;

  // 1 mean success, 0 failure and -1 is base state
  int success = -1;
  std::string error_message;
  int hits = -1;
  std::string content;
  // 1 mean yes, 0 no and -1 is base state
  int partial_exception = -1;
  std::vector<std::string> string_array;

  kuzzleio::NotificationResult *notif_result = nullptr;

};

class CustomNotificationListener {
  private:
    CustomNotificationListener() {
      listener = [](const kuzzleio::NotificationResult& res) {
        ScenarioScope<KuzzleCtx> ctx;
        std::cout << "received a notification: " << res.result()->content() << std::endl;
        ctx->notif_result = new kuzzleio::NotificationResult(res);
      };
    };
  public:
    kuzzleio::NotificationListener listener;
    static CustomNotificationListener* getSingleton() {
      static CustomNotificationListener* instance =
        new CustomNotificationListener();

      return instance;
    }
};

#endif
