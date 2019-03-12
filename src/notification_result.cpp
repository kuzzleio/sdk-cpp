#include "kuzzle.hpp"
#include "internal/notification_result.hpp"

namespace kuzzleio {

    const std::string & NotificationResult::requestId() const {
        return _requestId;
    }

    const NotificationContent & NotificationResult::result() const {
        return _result;
    }

    const std::string & NotificationResult::volatiles() const {
        return _volatiles;
    }

    const std::string & NotificationResult::index() const {
        return _index;
    }

    const std::string & NotificationResult::collection() const {
        return _collection;
    }

    const std::string & NotificationResult::controller() const {
        return _controller;
    }

    const std::string & NotificationResult::action() const {
        return _action;
    }

    const std::string & NotificationResult::protocol() const {
        return _protocol;
    }

    const std::string & NotificationResult::scope() const {
        return _scope;
    }

    const std::string & NotificationResult::state() const {
        return _state;
    }

    const std::string & NotificationResult::user() const {
        return _user;
    }

    const std::string & NotificationResult::nType() const {
        return _nType;
    }

    const std::string & NotificationResult::roomId() const {
        return _roomId;
    }

    const uint64_t NotificationResult::timestamp() const {
        return _timestamp;
    }

    const int NotificationResult::status() const {
        return _status;
    }

    const std::string & NotificationResult::error() const {
        return _error;
    }

    const std::string & NotificationResult::stack() const {
        return _stack;
    }
}