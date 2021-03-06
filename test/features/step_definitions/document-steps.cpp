#include "steps.hpp"

// Anonymous namespace to handle a linker error
// see https://stackoverflow.com/questions/14320148/linker-error-on-cucumber-cpp-when-dealing-with-multiple-feature-files
namespace {
  WHEN("^I create a document with id \'([^\"]*)\'$") {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      ctx->kuzzle->document->create(
          ctx->index, ctx->collection, document_id, R"%({"a":"document"})%",
          options);
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      ctx->success = 0;
      ctx->error_message = e.what();
    }
  }

  THEN("^I get an error with message \'([^\"]*)\'$") {
    REGEX_PARAM(std::string, error_message);

    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 0);
    BOOST_CHECK(ctx->error_message == error_message);
  }

  THEN("^the document is successfully created$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 1);
  }

  GIVEN("^the collection doesn't have a document with id \'([^\"]*)\'$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      ctx->kuzzle->document->delete_(
          ctx->index, ctx->collection, document_id, options);
    } catch (kuzzleio::KuzzleException e) {
      ctx->error_message = e.what();
      ctx->success = 0;
    }
  }

  WHEN("^I createOrReplace a document with id \'([^\"]*)\'$") {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      ctx->kuzzle->document->createOrReplace(
          ctx->index, ctx->collection, document_id,
          R"%({"a":"replaced document"})%", options);
      ctx->document_id = document_id;
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document is successfully replaced$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    std::string document = ctx->kuzzle->document->get(
        ctx->index, ctx->collection, ctx->document_id);

    BOOST_CHECK(ctx->success == 1);
    BOOST_CHECK(document.find("replaced document") != std::string::npos);
  }

  WHEN("^I replace a document with id \'([^\"]*)\'$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      ctx->kuzzle->document->replace(
          ctx->index, ctx->collection, document_id,
          R"%({"a":"replaced document"})%", options);
      ctx->document_id = document_id;
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document is successfully deleted$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 1);
  }

  WHEN("^I update a document with id \'([^\"]*)\'$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      ctx->kuzzle->document->update(
          ctx->index, ctx->collection, document_id,
          R"%({"a":"updated document"})%", options);
      ctx->document_id = document_id;
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document is successfully updated$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    std::string document = ctx->kuzzle->document->get(
        ctx->index, ctx->collection, ctx->document_id);

    BOOST_CHECK(ctx->success == 1);
    BOOST_CHECK(document.find("updated document") != std::string::npos);
  }

  WHEN("^I search a document with id \'([^\"]*)\'$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;
    std::string squery = R"%({"query":{"bool":{"should":[{"match":{"_id": ")%"
        + document_id + R"%("}}]}}})%";

    try {
      ctx->search_result = ctx->kuzzle->document->search(
          ctx->index, ctx->collection, squery);
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  WHEN(R"(^I search documents matching '([^']+)' with from (\d+) and size (\d+)$)")
  {
    REGEX_PARAM(std::string, query);
    REGEX_PARAM(unsigned, from);
    REGEX_PARAM(unsigned, size);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options = {};
      options.from = from;
      options.size = size;

      ctx->search_result = ctx->kuzzle->document->search(
          ctx->index, ctx->collection, query, options);
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  WHEN("^I search the next documents$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    try {
      ctx->search_result = ctx->search_result->next();
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document is (successfully|not) found$")
  {
    REGEX_PARAM(std::string, search_status);

    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 1);

    if (search_status == "successfully")
      BOOST_CHECK(ctx->search_result->total() == 1);
    else
      BOOST_CHECK(ctx->search_result->total() == 0);
  }

  WHEN("^I count how many documents there is in the collection$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    try {
      ctx->hits = ctx->kuzzle->document->count(
          ctx->index, ctx->collection, "{}");
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  WHEN("^I delete the documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      std::vector<std::string> document_ids;
      document_ids.push_back(document1_id);
      document_ids.push_back(document2_id);

      ctx->kuzzle->document->mDelete(
          ctx->index, ctx->collection, document_ids, options);
      ctx->success = 1;
      ctx->partial_exception = 0;
    } catch (kuzzleio::PartialException e) {
      ctx->partial_exception = 1;
      ctx->success = 0;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^I must have (\\d+) documents in the collection$")
  {
    REGEX_PARAM(unsigned int, documents_count);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      unsigned int res = ctx->kuzzle->document->count(
          ctx->index, ctx->collection, "{}");
      BOOST_CHECK(res == documents_count);
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  WHEN("^I create the documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      std::string documents = R"([{"_id":")" + document1_id
          + R"(", "body":{}}, {"_id":")" + document2_id + R"(", "body":{}}])";
      ctx->kuzzle->document->mCreate(
          ctx->index, ctx->collection, documents, options);
      ctx->success = 1;
      ctx->partial_exception = 0;
    } catch (kuzzleio::PartialException e) {
      ctx->partial_exception = 1;
      ctx->success = 0;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  WHEN("^I replace the documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      std::string documents = R"([{"_id":")" + document1_id
          + R"(", "body":{"a":"replaced document"}}, {"_id":")" + document2_id
          + R"(", "body":{"a":"replaced document"}}])";
      ctx->kuzzle->document->mReplace(
          ctx->index, ctx->collection, documents, options);
      ctx->success = 1;
      ctx->partial_exception = 0;
    } catch (kuzzleio::PartialException e) {
      ctx->partial_exception = 1;
      ctx->success = 0;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document \'([^\"]*)\' should be replaced$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    std::string document = ctx->kuzzle->document->get(
        ctx->index, ctx->collection, document_id);

    BOOST_CHECK(document.find("replaced document") != std::string::npos);
  }

  WHEN("^I update the documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      std::string documents = R"([{"_id":")" + document1_id
          + R"(", "body":{"a":"replaced document"}}, {"_id":")" + document2_id
          + R"(", "body":{"a":"replaced document"}}])";
      ctx->kuzzle->document->mUpdate(
          ctx->index, ctx->collection, documents, options);
      ctx->success = 1;
      ctx->partial_exception = 0;
    } catch (kuzzleio::PartialException e) {
      ctx->partial_exception = 1;
      ctx->success = 0;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document \'([^\"]*)\' should be updated$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    std::string document = ctx->kuzzle->document->get(
        ctx->index, ctx->collection, document_id);

    BOOST_CHECK(document.find("replaced document") != std::string::npos);
  }

  WHEN("^I createOrReplace the documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      kuzzleio::query_options options;
      options.refresh = const_cast<char*>("wait_for");

      std::string documents = R"([{"_id":")" + document1_id
          + R"(", "body":{"a":"replaced document"}}, {"_id":")" + document2_id
          + R"(", "body":{"a":"replaced document"}}])";
      ctx->kuzzle->document->mCreateOrReplace(
          ctx->index, ctx->collection, documents, options);
      ctx->success = 1;
      ctx->partial_exception = 0;
    } catch (kuzzleio::PartialException e) {
      ctx->partial_exception = 1;
      ctx->success = 0;
    } catch (kuzzleio::KuzzleException e) {
      BOOST_FAIL(e.what());
    }
  }

  THEN("^the document \'([^\"]*)\' should be created$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    std::string document = ctx->kuzzle->document->get(
        ctx->index, ctx->collection, document_id);

    BOOST_CHECK(document.find("replaced document") != std::string::npos);
  }

  WHEN("^I check if \'([^\"]*)\' exists$")
  {
    REGEX_PARAM(std::string, document_id);

    ScenarioScope<KuzzleCtx> ctx;

    ctx->success = ctx->kuzzle->document->exists(
        ctx->index, ctx->collection, document_id) ? 1 : 0;
  }

  THEN("^the document should (not )?exist(s)?$")
  {
    REGEX_PARAM(std::string, existence);

    ScenarioScope<KuzzleCtx> ctx;

    if (existence == "not ")
      BOOST_CHECK(ctx->success == 0);
    else
      BOOST_CHECK(ctx->success == 1);
  }

  WHEN("^I get documents \\[\'(.*)\', \'(.*)\'\\]$")
  {
    REGEX_PARAM(std::string, document1_id);
    REGEX_PARAM(std::string, document2_id);

    ScenarioScope<KuzzleCtx> ctx;

    try {
      std::vector<std::string> document_ids;
      document_ids.push_back(document1_id);
      document_ids.push_back(document2_id);

      ctx->content = ctx->kuzzle->document->mGet(
          ctx->index, ctx->collection, document_ids);
      ctx->success = 1;
    } catch (kuzzleio::KuzzleException e) {
      ctx->success = 0;
    }
  }

  THEN("^the documents should be retrieved$")
  {
    ScenarioScope<KuzzleCtx> ctx;

    BOOST_CHECK(ctx->success == 1);
    BOOST_CHECK(ctx->content != "");
  }

  THEN(R"(^The search result should have (a total of|fetched) (\d+) documents$)")
  {
    REGEX_PARAM(std::string, field);
    REGEX_PARAM(size_t, number);

    ScenarioScope<KuzzleCtx> ctx;

    if (field == "a total of") {
      BOOST_CHECK(ctx->search_result->total() == number);
    }
    else if (field == "fetched") {
      BOOST_CHECK(ctx->search_result->fetched() == number);
    }
  }
}
