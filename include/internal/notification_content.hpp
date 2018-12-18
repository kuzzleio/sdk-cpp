#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "core.hpp"

namespace kuzzleio {
  class NotificationContent {
    public:
      const std::string id;
      const Meta meta;
      const std::string content;
      const int count;

      NotificationContent(const notification_content* c) :
        id(c->id),
        meta(new Meta(c->m),
        content(c->content),
        count(c->count)
      NotificationContent(NotificationContent* c) :
        id(c->id),
        meta(new Meta(c->meta),
        content(c->content),
        count(c->count)
  };
}

#endif