#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "core.hpp"
#include "meta.hpp"

namespace kuzzleio {
  class NotificationContent {
    private:
      const std::string id;
      const Meta* meta;
      const std::string content;
      const int count;

    public:
      NotificationContent(const notification_content* c) :
        id(c->id),
        meta(c->m ? new Meta(c->m) : nullptr),
        content(c->content),
        count(c->count)
        {};
      NotificationContent(const NotificationContent& c) :
        id(c.id),
        meta(c.meta),
        content(c.content),
        count(c.count)
        {}

      const std::string &getId() const;

      const Meta *getMeta() const;

      const std::string &getContent() const;

      const int getCount() const;;
  };
}

#endif