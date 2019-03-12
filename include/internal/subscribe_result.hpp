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
      SubscribeResult(const subscribe_result* u) :
        _room(u->room),
        _channel(u->channel),
        _status(u->status),
        _error(u->error ? u->error : ""),
        _stack(u->stack ? u->stack : "")
        {};
      SubscribeResult(const SubscribeResult& u) :
        _room(u._room),
        _channel(u._channel),
        _status(u._status),
        _error(u._error),
        _stack(u._stack)
        {}

      const std::string &room() const;

      const std::string &channel() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif