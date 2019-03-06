#include "kuzzle.hpp"
#include "internal/kuzzle_response.hpp"

namespace kuzzleio {

    const std::string &kuzzleio::KuzzleResponse::getRequest_id() const {
        return request_id;
    }

    const std::string &kuzzleio::KuzzleResponse::getResult() const {
        return result;
    }

    const std::string &kuzzleio::KuzzleResponse::getVolatiles() const {
        return volatiles;
    }

    const std::string &kuzzleio::KuzzleResponse::getIndex() const {
        return index;
    }

    const std::string &kuzzleio::KuzzleResponse::getCollection() const {
        return collection;
    }

    const std::string &kuzzleio::KuzzleResponse::getController() const {
        return controller;
    }

    const std::string &kuzzleio::KuzzleResponse::getAction() const {
        return action;
    }

    const std::string &kuzzleio::KuzzleResponse::getRoom_id() const {
        return room_id;
    }

    const std::string &kuzzleio::KuzzleResponse::getChannel() const {
        return channel;
    }

    const int kuzzleio::KuzzleResponse::getStatus() const {
        return status;
    }

    const std::string &kuzzleio::KuzzleResponse::getError() const {
        return error;
    }

    const std::string &kuzzleio::KuzzleResponse::getStack() const {
        return stack;
    }
}