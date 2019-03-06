#include "kuzzle.hpp"
#include "internal/notification_content.hpp"

const std::string &kuzzleio::NotificationContent::getId() const {
    return id;
}

const kuzzleio::Meta *kuzzleio::NotificationContent::getMeta() const {
    return meta;
}

const std::string &kuzzleio::NotificationContent::getContent() const {
    return content;
}

const int kuzzleio::NotificationContent::getCount() const {
    return count;
}
