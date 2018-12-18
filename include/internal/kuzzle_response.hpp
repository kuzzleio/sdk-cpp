#ifndef _KUZZLE_RESULT_HPP
#define _KUZZLE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleResponse {
    public:
      const std::string request_id;
      const std::string result;
      const std::string volatiles;
      const std::string index;
      const std::string collection;
      const std::string controller;
      const std::string action;
      const std::string room_id;
      const std::string channel;
      const int status;
      const std::string error;
      const std::string stack;

      KuzzleResponse(const kuzzle_response* u) :
        request_id(u->request_id),
        result(u->result),
        volatiles(u->volatiles),
        index(u->index),
        collection(u->collection),
        controller(u->controller),
        action(u->action),
        room_id(u->room_id),
        channel(u->channel),
        status(u->status),
        error(u->error ? u->error : ""),
        stack(u->stack ? u->stack : "")
        {};
      KuzzleResponse(KuzzleResponse* u) :
        request_id(u->request_id),
        result(u->result),
        volatiles(u->volatiles),
        index(u->index),
        collection(u->collection),
        controller(u->controller),
        action(u->action),
        room_id(u->room_id),
        channel(u->channel),
        status(u->status),
        error(u->error),
        stack(u->stack)
        {};
  };
}

#endif