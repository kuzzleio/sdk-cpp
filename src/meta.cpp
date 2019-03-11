#include "kuzzle.hpp"
#include "internal/meta.hpp"

namespace kuzzleio {

    const std::string &kuzzleio::Meta::getAuthor() const {
        return author;
    }

    const uint64_t kuzzleio::Meta::getCreatedAt() const {
        return createdAt;
    }

    const uint64_t kuzzleio::Meta::getUpdatedAt() const {
        return updatedAt;
    }

    const std::string &kuzzleio::Meta::getUpdater() const {
        return updater;
    }

    const bool kuzzleio::Meta::getActive() const {
        return active;
    }

    const uint64_t kuzzleio::Meta::getDeletedAt() const {
        return deletedAt;
    }
}