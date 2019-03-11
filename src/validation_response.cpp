#include "kuzzle.hpp"
#include "internal/validation_response.hpp"

namespace kuzzleio {

    const bool ValidationResponse::getValid() const {
        return valid;
    }

    const std::vector<std::string>& ValidationResponse::getDetails() const {
        return details;
    }

    const std::string& ValidationResponse::getDescription() const {
        return description;
    }

    const int ValidationResponse::getStatus() const {
        return status;
    }

    const std::string& ValidationResponse::getError() const {
        return error;
    }

    const std::string& ValidationResponse::getStack() const {
        return stack;
    }

}