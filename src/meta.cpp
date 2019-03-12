#include "kuzzle.hpp"
#include "internal/meta.hpp"

namespace kuzzleio {

    const std::string & Meta::author() const {
        return _author;
    }

    const uint64_t Meta::createdAt() const {
        return _createdAt;
    }

    const uint64_t Meta::updatedAt() const {
        return _updatedAt;
    }

    const std::string & Meta::updater() const {
        return _updater;
    }

    const bool Meta::active() const {
        return _active;
    }

    const uint64_t Meta::deletedAt() const {
        return _deletedAt;
    }
}