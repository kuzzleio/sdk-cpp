//
// Created by yoann on 06/03/19.
//

#include "kuzzle.hpp"
#include "internal/validation_response.hpp"

namespace kuzzleio {

    const bool kuzzleio::ValidationResponse::getValid() const {
        return valid;
    }

    const std::vector<std::string> &kuzzleio::ValidationResponse::getDetails() const {
        return details;
    }

    const std::string &kuzzleio::ValidationResponse::getDescription() const {
        return description;
    }

    const int kuzzleio::ValidationResponse::getStatus() const {
        return status;
    }

    const std::string &kuzzleio::ValidationResponse::getError() const {
        return error;
    }

    const std::string &kuzzleio::ValidationResponse::getStack() const {
        return stack;
    }

}