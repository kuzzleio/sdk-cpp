#include "kuzzle.hpp"
#include "internal/validation_response.hpp"

namespace kuzzleio {

    const bool ValidationResponse::valid() const {
        return _vr->valid;
    }

    const std::vector<std::string>& ValidationResponse::details() const {
        return _details;
    }

    const char* ValidationResponse::description() const {
        return _vr->description;
    }

    const int ValidationResponse::status() const {
        return _vr->status;
    }

    const char* ValidationResponse::error() const {
        return _vr->error;
    }

    const char* ValidationResponse::stack() const {
        return _vr->stack;
    }

}