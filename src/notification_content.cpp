#include "kuzzle.hpp"
#include "internal/notification_content.hpp"

namespace kuzzleio {

    const char* NotificationContent::id() const {
        return _nc->id;
    }

    const Meta NotificationContent::meta() const {

        return _nc->m ? Meta(_nc->m) : nullptr;
    }

    const char* NotificationContent::content() const {
        return _nc->content;
    }

    const int NotificationContent::count() const {
        return _nc->count;
    }
}