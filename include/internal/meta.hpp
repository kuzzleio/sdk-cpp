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
      Meta(const meta* m) :
        _author(m->author),
        _createdAt(m->created_at),
        _updatedAt(m->updated_at),
        _updater(m->updater),
        _active(m->active),
        _deletedAt(m->deleted_at)
        {};
      Meta(const Meta& m) :
        _author(m._author),
        _createdAt(m._createdAt),
        _updatedAt(m._updatedAt),
        _updater(m._updater),
        _active(m._active),
        _deletedAt(m._deletedAt)
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