#ifndef _SUBSCRIBE_RESULT_HPP
#define _SUBSCRIBE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class SubscribeResult {
    private:
      subscribe_result* _sr = nullptr;

    public:
      SubscribeResult(subscribe_result* src) :
        _sr(src)
        {};
      SubscribeResult(const SubscribeResult& src) :
        _sr(src._sr)
        {};

      virtual inline ~SubscribeResult() { if (_sr != nullptr) kuzzle_free_subscribe_result(_sr);};

      const char* room() const;

      const char* channel() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;;
  };
}

#endif