#include "kuzzle.hpp"
#include "internal/notification_result.hpp"

const std::string &kuzzleio::NotificationResult::getRequest_id() const {
    return request_id;
}

const kuzzleio::NotificationContent &kuzzleio::NotificationResult::getResult() const {
    return result;
}

const std::string &kuzzleio::NotificationResult::getVolatiles() const {
    return volatiles;
}

const std::string &kuzzleio::NotificationResult::getIndex() const {
    return index;
}

const std::string &kuzzleio::NotificationResult::getCollection() const {
    return collection;
}

const std::string &kuzzleio::NotificationResult::getController() const {
    return controller;
}

const std::string &kuzzleio::NotificationResult::getAction() const {
    return action;
}

const std::string &kuzzleio::NotificationResult::getProtocol() const {
    return protocol;
}

const std::string &kuzzleio::NotificationResult::getScope() const {
    return scope;
}

const std::string &kuzzleio::NotificationResult::getState() const {
    return state;
}

const std::string &kuzzleio::NotificationResult::getUser() const {
    return user;
}

const std::string &kuzzleio::NotificationResult::getN_type() const {
    return n_type;
}

const std::string &kuzzleio::NotificationResult::getRoom_id() const {
    return room_id;
}

const uint64_t kuzzleio::NotificationResult::getTimestamp() const {
    return timestamp;
}

const int kuzzleio::NotificationResult::getStatus() const {
    return status;
}

const std::string &kuzzleio::NotificationResult::getError() const {
    return error;
}

const std::string &kuzzleio::NotificationResult::getStack() const {
    return stack;
}
