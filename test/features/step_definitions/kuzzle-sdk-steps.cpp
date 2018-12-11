#include "steps.hpp"

// Anonymous namespace to handle a linker error
// see https://stackoverflow.com/questions/14320148/linker-error-on-cucumber-cpp-when-dealing-with-multiple-feature-files
namespace {
  BEFORE() { kuz_log_sep(); }

  GIVEN("^I update my user custom data with the pair '(.+)':'(.+)'$")
  {
    REGEX_PARAM(std::string, fieldname);
    REGEX_PARAM(std::string, fieldvalue);

    ScenarioScope<KuzzleCtx> ctx;

    string data = "{\"" + fieldname + "\":\"" + fieldvalue + "\"}";

    K_LOG_D("Updating user data with : %s", data.c_str());

    try {
      ctx->kuzzle->auth->updateSelf(data);
    } catch (KuzzleException e) {
      K_LOG_E(e.getMessage().c_str());
    }
  }

  THEN("^the response 'content' field contains the pair '(.+)':'(.+)'$")
  {
    K_LOG_I("Checking user content field");
    REGEX_PARAM(std::string, fieldname);
    REGEX_PARAM(std::string, expected_fieldvalue);

    ScenarioScope<KuzzleCtx> ctx;

    json_spirit::Value userContentValue;
    json_spirit::read(ctx->currentUser.content(), userContentValue);

    json_spirit::write_formatted(userContentValue);

    json_spirit::Value fieldvalue = json_spirit::find_value(userContentValue.get_obj(), fieldname);
    switch (fieldvalue.type()) {
      case json_spirit::str_type: {
        std::string s = fieldvalue.get_str();
        K_LOG_D("Field value: \"%s\" of type string", s.c_str());
        BOOST_CHECK(s == expected_fieldvalue);
        break;
      }
      case json_spirit::bool_type: {
        auto   b = fieldvalue.get_bool();
        string s = b ? "true" : "false";
        K_LOG_D("Field value: \"%s\" of type bool", b ? "true" : "false");
        BOOST_CHECK(s == expected_fieldvalue);
        break;
      }
      case json_spirit::int_type: {
        auto i = fieldvalue.get_int();
        K_LOG_D("Field value: %d of type int", i);
        string s = std::to_string(i);
        BOOST_CHECK(s == expected_fieldvalue);
        break;
      }
      case json_spirit::real_type: {
        float f = fieldvalue.get_real();
        K_LOG_D("Field value: %f of type real", f);
        float e = std::stof(expected_fieldvalue);
        K_LOG_D("Expected value: %f", e);
        BOOST_CHECK(f == std::stof(expected_fieldvalue));
        break;
      }
        // TODO: Add obj test case...
    }

    ctx->customUserDataType = fieldvalue.type();
  }

  THEN("^is a string$")
  {
    ScenarioScope<KuzzleCtx> ctx;
    BOOST_CHECK(ctx->customUserDataType == json_spirit::str_type);
  }

  THEN("^is a number$")
  {
    ScenarioScope<KuzzleCtx> ctx;
    BOOST_CHECK(ctx->customUserDataType == json_spirit::int_type || ctx->customUserDataType == json_spirit::real_type);
  }

  THEN("^is a bool$")
  {
    ScenarioScope<KuzzleCtx> ctx;
    BOOST_CHECK(ctx->customUserDataType == json_spirit::bool_type);
  }

  GIVEN("^Kuzzle Server is running$")
  {
    K_LOG_I("Connecting to Kuzzle on 'localhost:7512'");
    ScenarioScope<KuzzleCtx> ctx;
    std::string hostname = "localhost";

    if (std::getenv("KUZZLE_HOST") != NULL) {
      hostname = std::getenv("KUZZLE_HOST");
    }

    try {
      ctx->protocol = new WebSocket(hostname);
      ctx->kuzzle = new Kuzzle(ctx->protocol, &ctx->kuzzle_options);
    } catch (KuzzleException e) {
      K_LOG_E(e.getMessage().c_str());
    }

    // throws if it fails to connect
    try {
      ctx->kuzzle->connect();
    } catch(KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^I get an error$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 0);
  }

  THEN("^(the result contains|I shall receive) (\\d+)( hits)?$")
  {
    REGEX_PARAM(string, unused);
    REGEX_PARAM(unsigned int, hits);

    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(hits == ctx->hits);
  }

  THEN("^the content should not be null$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->content != "");
  }

  THEN("^I (should have|get) (a|no) partial error$") {
    REGEX_PARAM(string, unused);
    REGEX_PARAM(string, error_presence);

    ScenarioScope<KuzzleCtx> ctx;

    if (error_presence == "no")
      BOOST_CHECK(ctx->partial_exception == 0);
    else
      BOOST_CHECK(ctx->partial_exception == 1);
  }
}
