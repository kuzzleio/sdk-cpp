#include "kuzzle.hpp"
#include "internal/token_validity.hpp"

namespace kuzzleio {

    bool TokenValidity::valid() const {
        return _valid;
    }

    const std::string& TokenValidity::state() const {
        return _state;
    }

    unsigned long long int TokenValidity::expiresAt() const {
        return _expiresAt;
    }

    int TokenValidity::status() const {
        return _status;
    }

    const std::string& TokenValidity::error() const {
        return _error;
    }

    const std::string& TokenValidity::stack() const {
        return _stack;
    }
}