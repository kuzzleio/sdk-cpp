#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {

    const std::string& UserRight::controller() const {
        return _controller;
    }

    const std::string& UserRight::action() const {
        return _action;
    }

    const std::string& UserRight::index() const {
        return _index;
    }

    const std::string& UserRight::collection() const {
        return _collection;
    }

    const std::string& UserRight::value() const {
        return _value;
    }
}