#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "core.hpp"
#include "meta.hpp"

namespace kuzzleio {
  class NotificationContent {
    private:
      notification_content* _nc = nullptr;

    public:
      NotificationContent(notification_content* src) :
        _nc(src)
        {};
      NotificationContent(const NotificationContent& src) :
        _nc(src._nc)
        {};

      virtual inline ~NotificationContent() { if (_nc != nullptr) kuzzle_free_notification_content(_nc); };
      
      const char* id() const;

      const Meta meta() const;

      const char* content() const;

      const int count() const;;
  };
}

#endif