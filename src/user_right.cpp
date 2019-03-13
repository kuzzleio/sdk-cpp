#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {

    const char* UserRight::controller() const {
        return _ur->controller;
    }

    const char* UserRight::action() const {
        return _ur->action;
    }

    const char* UserRight::index() const {
        return _ur->index;
    }

    const char* UserRight::collection() const {
        return _ur->collection;
    }

    const char* UserRight::value() const {
        return _ur->value;
    }
}