#ifndef _SUBSCRIBE_RESULT_HPP
#define _SUBSCRIBE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class SubscribeResult {
    private:
      const std::string _room;
      const std::string _channel;
      const int _status;
      const std::string _error;
      const std::string _stack;

    public:
      SubscribeResult(const subscribe_result* src) :
        _room(src->room),
        _channel(src->channel),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        {};
      SubscribeResult(const SubscribeResult& src) :
        _room(src._room),
        _channel(src._channel),
        _status(src._status),
        _error(src._error),
        _stack(src._stack)
        {};

      const std::string &room() const;

      const std::string &channel() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif