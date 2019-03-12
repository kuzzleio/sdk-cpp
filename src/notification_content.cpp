#include "kuzzle.hpp"
#include "internal/notification_content.hpp"

namespace kuzzleio {

    const std::string &NotificationContent::id() const {
        return _id;
    }

    const Meta *NotificationContent::meta() const {
        return _meta;
    }

    const std::string &NotificationContent::content() const {
        return _content;
    }

    const int NotificationContent::count() const {
        return _count;
    }
}