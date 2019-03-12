#include "kuzzle.hpp"
#include "internal/subscribe_result.hpp"

namespace kuzzleio {

    const std::string &SubscribeResult::room() const {
        return _room;
    }

    const std::string &SubscribeResult::channel() const {
        return _channel;
    }

    const int SubscribeResult::status() const {
        return _status;
    }

    const std::string &SubscribeResult::error() const {
        return _error;
    }

    const std::string &SubscribeResult::stack() const {
        return _stack;
    }
}