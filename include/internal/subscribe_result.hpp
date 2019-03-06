#ifndef _SUBSCRIBE_RESULT_HPP
#define _SUBSCRIBE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class SubscribeResult {
    public:
      const std::string room;
      const std::string channel;
      const int status;
      const std::string error;
      const std::string stack;

      SubscribeResult(const subscribe_result* u) :
        room(u->room),
        channel(u->channel),
        status(u->status),
        error(u->error ? u->error : ""),
        stack(u->stack ? u->stack : "")
        {};
      SubscribeResult(SubscribeResult* u) :
        room(u->room),
        channel(u->channel),
        status(u->status),
        error(u->error),
        stack(u->stack)
        {}

      const std::string &getRoom() const;

      const std::string &getChannel() const;

      const int getStatus() const;

      const std::string &getError() const;

      const std::string &getStack() const;;
  };
}

#endif