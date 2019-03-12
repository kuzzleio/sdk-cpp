#ifndef _KUZZLE_RESULT_HPP
#define _KUZZLE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleResponse {
    private:
      const std::string _requestId;
      const std::string _result;
      const std::string _volatiles;
      const std::string _index;
      const std::string _collection;
      const std::string _controller;
      const std::string _action;
      const std::string _roomId;
      const std::string _channel;
      const int _status;
      const std::string _error;
      const std::string _stack;

    public:
      KuzzleResponse(const kuzzle_response* u) :
        _requestId(u->request_id),
        _result(u->result),
        _volatiles(u->volatiles),
        _index(u->index),
        _collection(u->collection),
        _controller(u->controller),
        _action(u->action),
        _roomId(u->room_id),
        _channel(u->channel),
        _status(u->status),
        _error(u->error ? u->error : ""),
        _stack(u->stack ? u->stack : "")
        {};
      KuzzleResponse(const KuzzleResponse& u) :
        _requestId(u._requestId),
        _result(u._result),
        _volatiles(u._volatiles),
        _index(u._index),
        _collection(u._collection),
        _controller(u._controller),
        _action(u._action),
        _roomId(u._roomId),
        _channel(u._channel),
        _status(u._status),
        _error(u._error),
        _stack(u._stack)
        {}

      const std::string &requestId() const;

      const std::string &result() const;

      const std::string &volatiles() const;

      const std::string &index() const;

      const std::string &collection() const;

      const std::string &controller() const;

      const std::string &action() const;

      const std::string &roomId() const;

      const std::string &channel() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif