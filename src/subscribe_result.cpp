#include "kuzzle.hpp"
#include "internal/subscribe_result.hpp"

namespace kuzzleio {

    const std::string &kuzzleio::SubscribeResult::getRoom() const {
        return room;
    }

    const std::string &kuzzleio::SubscribeResult::getChannel() const {
        return channel;
    }

    const int kuzzleio::SubscribeResult::getStatus() const {
        return status;
    }

    const std::string &kuzzleio::SubscribeResult::getError() const {
        return error;
    }

    const std::string &kuzzleio::SubscribeResult::getStack() const {
        return stack;
    }
}