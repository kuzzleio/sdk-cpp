#include "kuzzle.hpp"
#include "internal/token_validity.hpp"

namespace kuzzleio {

    const bool TokenValidity::getValid() const {
        return valid;
    }

    const std::string& TokenValidity::getState() const {
        return state;
    }

    const unsigned long long int TokenValidity::getExpiresAt() const {
        return expiresAt;
    }

    const int TokenValidity::getStatus() const {
        return status;
    }

    const std::string& TokenValidity::getError() const {
        return error;
    }

    const std::string& TokenValidity::getStack() const {
        return stack;
    }
}