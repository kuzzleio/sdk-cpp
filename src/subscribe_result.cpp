#include "kuzzle.hpp"
#include "internal/subscribe_result.hpp"

namespace kuzzleio {

    const char* SubscribeResult::room() const {
        return _sr->room;
    }

    const char* SubscribeResult::channel() const {
        return _sr->channel;
    }

    const int SubscribeResult::status() const {
        return _sr->status;
    }

    const char* SubscribeResult::error() const {
        return _sr->error;
    }

    const char* SubscribeResult::stack() const {
        return _sr->stack;
    }
}