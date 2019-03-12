#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "core.hpp"
#include "meta.hpp"

namespace kuzzleio {
  class NotificationContent {
    private:
      const std::string _id;
      const Meta* _meta = nullptr;
      const std::string _content;
      const int _count;

    public:
      NotificationContent(const notification_content* src) :
        _id(src->id),
        _meta(src->m ? new Meta(src->m) : nullptr),
        _content(src->content),
        _count(src->count)
        {};
      NotificationContent(const NotificationContent& src) :
        _id(src._id),
        _meta(src._meta),
        _content(src._content),
        _count(src._count)
        {};

      virtual inline ~NotificationContent() { if (_meta != nullptr) delete(_meta); };
      
      const std::string &id() const;

      const Meta *meta() const;

      const std::string &content() const;

      const int count() const;;
  };
}

#endif