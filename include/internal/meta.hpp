#ifndef _META_HPP
#define _META_HPP

#include <string>

namespace kuzzleio {
  class Meta {
     private:
      const std::string _author;
      const uint64_t _createdAt;
      const uint64_t _updatedAt;
      const std::string _updater;
      const bool _active;
      const uint64_t _deletedAt;
     public:
      Meta(const meta* src) :
        _author(src->author),
        _createdAt(src->created_at),
        _updatedAt(src->updated_at),
        _updater(src->updater),
        _active(src->active),
        _deletedAt(src->deleted_at)
        {};
      Meta(const Meta& src) :
        _author(src._author),
        _createdAt(src._createdAt),
        _updatedAt(src._updatedAt),
        _updater(src._updater),
        _active(src._active),
        _deletedAt(src._deletedAt)
        {}

      const std::string &author() const;

      const uint64_t createdAt() const;

      const uint64_t updatedAt() const;

      const std::string &updater() const;

      const bool active() const;

      const uint64_t deletedAt() const;;
  };
}

#endif