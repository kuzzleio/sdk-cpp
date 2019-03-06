#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {

    const std::string &kuzzleio::UserRight::getController() const {
        return controller;
    }

    const std::string &kuzzleio::UserRight::getAction() const {
        return action;
    }

    const std::string &kuzzleio::UserRight::getIndex() const {
        return index;
    }

    const std::string &kuzzleio::UserRight::getCollection() const {
        return collection;
    }

    const std::string &kuzzleio::UserRight::getValue() const {
        return value;
    }
}