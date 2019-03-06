#ifndef _META_HPP
#define _META_HPP

#include <string>

namespace kuzzleio {
  class Meta {
     public:
      const std::string author;
      const uint64_t created_at;
      const uint64_t updated_at;
      const std::string updater;
      const bool active;
      const uint64_t deleted_at;

      Meta(const meta* m) :
        author(m->author),
        created_at(m->created_at),
        updated_at(m->updated_at),
        updater(m->updater),
        active(m->active),
        deleted_at(m->deleted_at)
        {};
      Meta(Meta* m) :
        author(m->author),
        created_at(m->created_at),
        updated_at(m->updated_at),
        updater(m->updater),
        active(m->active),
        deleted_at(m->deleted_at)
        {}

      const std::string &getAuthor() const;

      const uint64_t getCreated_at() const;

      const uint64_t getUpdated_at() const;

      const std::string &getUpdater() const;

      const bool getActive() const;

      const uint64_t getDeleted_at() const;;
  };
}

#endif