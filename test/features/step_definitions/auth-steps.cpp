#include "steps.hpp"

// Anonymous namespace to handle a linker error
// see https://stackoverflow.com/questions/14320148/linker-error-on-cucumber-cpp-when-dealing-with-multiple-feature-files
namespace {
  BEFORE() { kuz_log_sep(); }

  GIVEN("^I create a user 'useradmin' with password 'testpwd' with id 'useradmin-id'$") { pending(); }

  GIVEN("^there is an user with id '([\\w\\-]+)'$")
  {
    REGEX_PARAM(std::string, user_id);
    ScenarioScope<KuzzleCtx> ctx;
    ctx->user_id = user_id;
  }

  GIVEN("^the user has 'local' credentials with name '([\\w\\-]+)' and password "
        "'([\\w\\-]+)'$")
  {
    REGEX_PARAM(std::string, username);
    REGEX_PARAM(std::string, password);
    ScenarioScope<KuzzleCtx> ctx;

    kuzzle_user_create(ctx->kuzzle, ctx->user_id, username, password);
  }

  WHEN("^I log in as '([\\w\\-]+)':'([\\w\\-]+)'$")
  {
    REGEX_PARAM(std::string, username);
    REGEX_PARAM(std::string, password);
    ScenarioScope<KuzzleCtx> ctx;

    ctx->jwt = ctx->kuzzle->auth->login("local", get_login_creds(username, password));
    K_LOG_D("Logged in as '%s'", username.c_str());
    K_LOG_D("JWT is: %s", ctx->jwt.c_str());
  }

  THEN("^the JWT is valid$")
  {
    ScenarioScope<KuzzleCtx> ctx;
    kuzzleio::token_validity* v = ctx->kuzzle->auth->checkToken(ctx->jwt);
    BOOST_CHECK(v->valid);
  }

  THEN("^the JWT is invalid$")
  {
    ScenarioScope<KuzzleCtx> ctx;
    kuzzleio::token_validity* v = ctx->kuzzle->auth->checkToken(ctx->jwt);
    BOOST_CHECK(!v->valid);
  }
  WHEN("^I logout$") {
      ScenarioScope<KuzzleCtx> ctx;
      ctx->kuzzle->auth->logout();
  }

  WHEN("^I get my user info$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    try {
      ctx->currentUser = ctx->kuzzle->auth->getCurrentUser();
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }

    K_LOG_D("current user = 0x%p", &(ctx->currentUser));
    K_LOG_D("Current user content: %s", ctx->currentUser.content().c_str());
  }

  GIVEN("^I get my rights$") {
    ScenarioScope<KuzzleCtx> ctx;

    try {
      ctx->user_rights = ctx->kuzzle->auth->getMyRights();
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      ctx->success = 0;
      K_LOG_E(e.what());
    }
  }

  THEN("^I have a vector with (.+) rights$") {
    REGEX_PARAM(int, right_count);

    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 1);
    BOOST_CHECK(ctx->user_rights.size() == right_count);
  }
}
