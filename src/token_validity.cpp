#include "kuzzle.hpp"
#include "internal/token_validity.hpp"

namespace kuzzleio {

    const bool kuzzleio::TokenValidity::getValid() const {
        return valid;
    }

    const std::string &kuzzleio::TokenValidity::getState() const {
        return state;
    }

    const unsigned long long int kuzzleio::TokenValidity::getExpires_at() const {
        return expires_at;
    }

    const int kuzzleio::TokenValidity::getStatus() const {
        return status;
    }

    const std::string &kuzzleio::TokenValidity::getError() const {
        return error;
    }

    const std::string &kuzzleio::TokenValidity::getStack() const {
        return stack;
    }
}