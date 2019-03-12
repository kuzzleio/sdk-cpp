#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "core.hpp"
#include "meta.hpp"

namespace kuzzleio {
  class NotificationContent {
    private:
      const std::string _id;
      const Meta* _meta;
      const std::string _content;
      const int _count;

    public:
      NotificationContent(const notification_content* c) :
        _id(c->id),
        _meta(c->m ? new Meta(c->m) : nullptr),
        _content(c->content),
        _count(c->count)
        {};
      NotificationContent(const NotificationContent& c) :
        _id(c._id),
        _meta(c._meta),
        _content(c._content),
        _count(c._count)
        {}

      const std::string &id() const;

      const Meta *meta() const;

      const std::string &content() const;

      const int count() const;;
  };
}

#endif