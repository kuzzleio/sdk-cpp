// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "kuzzle.hpp"
#include "internal/kuzzle_response.hpp"
#include "internal/utils.hpp"

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