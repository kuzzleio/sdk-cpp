#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {

    const std::string& UserRight::getController() const {
        return controller;
    }

    const std::string& UserRight::getAction() const {
        return action;
    }

    const std::string& UserRight::getIndex() const {
        return index;
    }

    const std::string& UserRight::getCollection() const {
        return collection;
    }

    const std::string& UserRight::getValue() const {
        return value;
    }
}