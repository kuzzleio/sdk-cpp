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

using namespace kuzzleio;
using std::cout;
using std::endl;
using std::string;

struct KuzzleCtx {
  Kuzzle* kuzzle = nullptr;
  Protocol* protocol = nullptr;
  Options kuzzle_options;

  string user_id;
  string index;
  string collection;
  string jwt;
  string document_id;
  std::shared_ptr<SearchResult> search_result;
  std::vector<std::shared_ptr<UserRight>> user_rights;

  string room_id;

  User currentUser;
  json_spirit::Value_type customUserDataType = json_spirit::null_type;

  // 1 mean success, 0 failure and -1 is base state
  int success = -1;
  string error_message;
  int hits = -1;
  string content;
  // 1 mean yes, 0 no and -1 is base state
  int partial_exception = -1;
  std::vector<string> string_array;

<<<<<<< HEAD
  NotificationResult *notif_result = nullptr;
=======
  std::shared_ptr<notification_result> notif_result = nullptr;
>>>>>>> origin/1-dev
};

class CustomNotificationListener {
  private:
    CustomNotificationListener() {
<<<<<<< HEAD
      listener = [](const kuzzleio::NotificationResult* res) {
        ScenarioScope<KuzzleCtx> ctx;
        ctx->notif_result = const_cast<NotificationResult*>(res);
=======
      listener = [](std::shared_ptr<kuzzleio::notification_result> res) {
        ScenarioScope<KuzzleCtx> ctx;
        std::cout << "received a notification: " << res->result->content << std::endl;
        ctx->notif_result = res;
>>>>>>> origin/1-dev
      };
    };
  public:
    NotificationListener listener;
    static CustomNotificationListener* getSingleton() {
      static CustomNotificationListener* instance =
        new CustomNotificationListener();

      return instance;
    }
};

#endif
