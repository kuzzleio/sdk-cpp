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
      KuzzleResponse(const kuzzle_response* src) :
        _requestId(src->request_id),
        _result(src->result),
        _volatiles(src->volatiles),
        _index(src->index),
        _collection(src->collection),
        _controller(src->controller),
        _action(src->action),
        _roomId(src->room_id),
        _channel(src->channel),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        {};
      KuzzleResponse(const KuzzleResponse& src) :
        _requestId(src._requestId),
        _result(src._result),
        _volatiles(src._volatiles),
        _index(src._index),
        _collection(src._collection),
        _controller(src._controller),
        _action(src._action),
        _roomId(src._roomId),
        _channel(src._channel),
        _status(src._status),
        _error(src._error),
        _stack(src._stack)
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