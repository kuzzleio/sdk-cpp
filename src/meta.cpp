#include "kuzzle.hpp"
#include "internal/meta.hpp"

namespace kuzzleio {

    const std::string &kuzzleio::Meta::getAuthor() const {
        return author;
    }

    const uint64_t kuzzleio::Meta::getCreated_at() const {
        return created_at;
    }

    const uint64_t kuzzleio::Meta::getUpdated_at() const {
        return updated_at;
    }

    const std::string &kuzzleio::Meta::getUpdater() const {
        return updater;
    }

    const bool kuzzleio::Meta::getActive() const {
        return active;
    }

    const uint64_t kuzzleio::Meta::getDeleted_at() const {
        return deleted_at;
    }
}