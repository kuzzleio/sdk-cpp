#include "kuzzle.hpp"
#include "internal/token_validity.hpp"

namespace kuzzleio {

    const bool TokenValidity::valid() const {
        return _valid;
    }

    const std::string& TokenValidity::state() const {
        return _state;
    }

    const unsigned long long int TokenValidity::expiresAt() const {
        return _expiresAt;
    }

    const int TokenValidity::status() const {
        return _status;
    }

    const std::string& TokenValidity::error() const {
        return _error;
    }

    const std::string& TokenValidity::stack() const {
        return _stack;
    }
}