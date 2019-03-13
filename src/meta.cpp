#include "kuzzle.hpp"
#include "internal/meta.hpp"

namespace kuzzleio {

    const char * Meta::author() const {
        return _m->author;
    }

    const uint64_t Meta::createdAt() const {
        return _m->created_at;
    }

    const uint64_t Meta::updatedAt() const {
        return _m->updated_at;
    }

    const char * Meta::updater() const {
        return _m->updater;
    }

    const bool Meta::active() const {
        return _m->active;
    }

    const uint64_t Meta::deletedAt() const {
        return _m->deleted_at;
    }
}