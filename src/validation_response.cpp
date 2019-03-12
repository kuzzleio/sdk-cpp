#include "kuzzle.hpp"
#include "internal/validation_response.hpp"

namespace kuzzleio {

    const bool ValidationResponse::valid() const {
        return _valid;
    }

    const std::vector<std::string>& ValidationResponse::details() const {
        return _details;
    }

    const std::string& ValidationResponse::description() const {
        return _description;
    }

    const int ValidationResponse::status() const {
        return _status;
    }

    const std::string& ValidationResponse::error() const {
        return _error;
    }

    const std::string& ValidationResponse::stack() const {
        return _stack;
    }

}