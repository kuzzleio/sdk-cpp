#ifndef _META_HPP
#define _META_HPP

#include <string>

namespace kuzzleio {
  class Meta {
     private:
      const std::string author;
      const uint64_t createdAt;
      const uint64_t updatedAt;
      const std::string updater;
      const bool active;
      const uint64_t deletedAt;
     public:
      Meta(const meta* m) :
        author(m->author),
        createdAt(m->created_at),
        updatedAt(m->updated_at),
        updater(m->updater),
        active(m->active),
        deletedAt(m->deleted_at)
        {};
      Meta(const Meta& m) :
        author(m.author),
        createdAt(m.createdAt),
        updatedAt(m.updatedAt),
        updater(m.updater),
        active(m.active),
        deletedAt(m.deletedAt)
        {}

      const std::string &getAuthor() const;

      const uint64_t getCreatedAt() const;

      const uint64_t getUpdatedAt() const;

      const std::string &getUpdater() const;

      const bool getActive() const;

      const uint64_t getDeletedAt() const;;
  };
}

#endif