#ifndef _NOTIFICATION_RESULT_HPP
#define _NOTIFICATION_RESULT_HPP

#include <string>
#include "notification_content.hpp"

namespace kuzzleio {
  class NotificationResult {
    private:
      const std::string _requestId;
      const NotificationContent _result;
      const std::string _volatiles;
      const std::string _index;
      const std::string _collection;
      const std::string _controller;
      const std::string _action;
      const std::string _protocol;
      const std::string _scope;
      const std::string _state;
      const std::string _user;
      const std::string _nType;
      const std::string _roomId;
      const uint64_t _timestamp;
      const int _status;
      const std::string _error;
      const std::string _stack;

    public:
      NotificationResult(const notification_result* src) :
        _requestId(src->request_id),
        _result(NotificationContent(src->result)),
        _volatiles(src->volatiles),
        _index(src->index),
        _collection(src->collection),
        _controller(src->controller),
        _action(src->action),
        _protocol(src->protocol),
        _scope(src->scope),
        _state(src->state),
        _user(src->user),
        _nType(src->n_type),
        _roomId(src->room_id),
        _timestamp(src->timestamp),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        {}

      NotificationResult(const NotificationResult& src) :
        _requestId(src._requestId),
        _result(NotificationContent(src._result)),
        _volatiles(src._volatiles),
        _index(src._index),
        _collection(src._collection),
        _controller(src._controller),
        _action(src._action),
        _protocol(src._protocol),
        _scope(src._scope),
        _state(src._state),
        _user(src._user),
        _nType(src._nType),
        _roomId(src._roomId),
        _timestamp(src._timestamp),
        _status(src._status),
        _error(src._error),
        _stack(src._stack)
        {}

      const std::string &requestId() const;

      const NotificationContent &result() const;

      const std::string &volatiles() const;

      const std::string &index() const;

      const std::string &collection() const;

      const std::string &controller() const;

      const std::string &action() const;

      const std::string &protocol() const;

      const std::string &scope() const;

      const std::string &state() const;

      const std::string &user() const;

      const std::string &nType() const;

      const std::string &roomId() const;

      const uint64_t timestamp() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;
  };
}

#endif