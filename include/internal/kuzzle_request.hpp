#ifndef _KUZZLE_REQUEST_HPP
#define _KUZZLE_REQUEST_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleRequest {
    private:

      kuzzle_request* _kr = nullptr;
      //vector or const char* const* ???
      std::vector<std::string> _members;
      std::vector<std::string> _options;
      std::vector<std::string> _keys;
      std::vector<std::string> _fields;

  public:
      KuzzleRequest();
      KuzzleRequest(const kuzzle_request* src);
      KuzzleRequest(KuzzleRequest& src) : KuzzleRequest(src.toC()) {};

      char* const* vectorToC(const std::vector<std::string> &vec) noexcept;

      const char* const* strtabdup(const char* const* s, size_t len);

      char* strdup(const char* s);

      virtual inline ~KuzzleRequest() {};

      const char* requestId() const;

      void requestId(const char* requestId);

      const char* controller() const;

      void controller(const char* controller);

      const char* action() const;

      void action(const char* action);

      const char* index() const;

      void index(const char* index);

      const char* collection() const;

      void collection(const char* collection);

      const char* body() const;

      void body(const char* body);

      const char* id() const;

      void id(const char* id);

      long from() const;

      void from(long from);

      long size() const;

      void size(long size);

      const char* scroll() const;

      void scroll(const char* scroll);

      const char* scrollId() const;

      void scrollId(const char* scrollId);

      const char* strategy() const;

      void strategy(const char* strategy);

      unsigned long long int expiresIn() const;

      void expiresIn(unsigned long long int expiresIn);

      const char* volatiles() const;

      void volatiles(const char* volatiles);

      const char* scope() const;

      void scope(const char* scope);

      const char* state() const;

      void state(const char* state);

      const char* users() const;

      void users(const char* users);

      long start() const;

      void start(long start);

      long stop() const;

      void stop(long stop);

      long end() const;

      void end(long end);

      unsigned char bit() const;

      void bit(unsigned char bit);

      const char* member() const;

      void member(const char* member);

      const char* member1() const;

      void member1(const char* member1);

      const char* member2() const;

      void member2(const char* member2);

      const std::vector<std::string> &members() const;

      void members(const std::vector<std::string> &members);

      double lon() const;

      void lon(double lon);

      double lat() const;

      void lat(double lat);

      double distance() const;

      void distance(double distance);

      const char* unit() const;

      void unit(const char* unit);

      const std::vector<std::string> &options() const;

      void options(const std::vector<std::string> &options);

      const std::vector<std::string> &keys() const;

      void keys(const std::vector<std::string> &keys);

      long cursor() const;

      void cursor(long cursor);

      long offset() const;

      void offset(long offset);

      const char* field() const;

      void field(const char* field);

      const std::vector<std::string> &fields() const;

      void fields(const std::vector<std::string> &fields);

      const char* subcommand() const;

      void subcommand(const char* subcommand);

      const char* pattern() const;

      void pattern(const char* pattern);

      long idx() const;

      void idx(long idx);

      const char* min() const;

      void min(const char* min);

      const char* max() const;

      void max(const char* max);

      const char* limit() const;

      void limit(const char* limit);

      unsigned long count() const;

      void count(unsigned long count);

      const char* match() const;

      void match(const char* match);

      bool reset() const;

      void reset(bool reset);

      bool includeTrash() const;

      void includeTrash(bool includeTrash);

      kuzzle_request* toC();
  };
}

#endif