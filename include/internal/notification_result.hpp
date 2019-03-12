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
      NotificationResult(const notification_result* r) :
        _requestId(r->request_id),
        _result(NotificationContent(r->result)),
        _volatiles(r->volatiles),
        _index(r->index),
        _collection(r->collection),
        _controller(r->controller),
        _action(r->action),
        _protocol(r->protocol),
        _scope(r->scope),
        _state(r->state),
        _user(r->user),
        _nType(r->n_type),
        _roomId(r->room_id),
        _timestamp(r->timestamp),
        _status(r->status),
        _error(r->error ? r->error : ""),
        _stack(r->stack ? r->stack : "")
        {}

      NotificationResult(const NotificationResult& r) :
        _requestId(r._requestId),
        _result(NotificationContent(r._result)),
        _volatiles(r._volatiles),
        _index(r._index),
        _collection(r._collection),
        _controller(r._controller),
        _action(r._action),
        _protocol(r._protocol),
        _scope(r._scope),
        _state(r._state),
        _user(r._user),
        _nType(r._nType),
        _roomId(r._roomId),
        _timestamp(r._timestamp),
        _status(r._status),
        _error(r._error),
        _stack(r._stack)
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