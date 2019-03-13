#include "kuzzle.hpp"
#include "internal/kuzzle_response.hpp"

namespace kuzzleio {

    const char* KuzzleResponse::requestId() const {
        return _kr->request_id;
    }

    const char* KuzzleResponse::result() const {
        return _kr->result;
    }

    const char* KuzzleResponse::volatiles() const {
        return _kr->volatiles;
    }

    const char* KuzzleResponse::index() const {
        return _kr->index;
    }

    const char* KuzzleResponse::collection() const {
        return _kr->collection;
    }

    const char* KuzzleResponse::controller() const {
        return _kr->controller;
    }

    const char* KuzzleResponse::action() const {
        return _kr->action;
    }

    const char* KuzzleResponse::roomId() const {
        return _kr->room_id;
    }

    const char* KuzzleResponse::channel() const {
        return _kr->channel;
    }

    const int  KuzzleResponse::status() const {
        return _kr->status;
    }

    const char* KuzzleResponse::error() const {
        return _kr->error;
    }

    const char* KuzzleResponse::stack() const {
        return _kr->stack;
    }

}