#include "kuzzle.hpp"
#include "internal/kuzzle_response.hpp"

namespace kuzzleio {

    const std::string & KuzzleResponse::requestId() const {
        return _requestId;
    }

    const std::string & KuzzleResponse::result() const {
        return _result;
    }

    const std::string & KuzzleResponse::volatiles() const {
        return _volatiles;
    }

    const std::string & KuzzleResponse::index() const {
        return _index;
    }

    const std::string & KuzzleResponse::collection() const {
        return _collection;
    }

    const std::string & KuzzleResponse::controller() const {
        return _controller;
    }

    const std::string & KuzzleResponse::action() const {
        return _action;
    }

    const std::string & KuzzleResponse::roomId() const {
        return _roomId;
    }

    const std::string & KuzzleResponse::channel() const {
        return _channel;
    }

    const int  KuzzleResponse::status() const {
        return _status;
    }

    const std::string & KuzzleResponse::error() const {
        return _error;
    }

    const std::string & KuzzleResponse::stack() const {
        return _stack;
    }
}