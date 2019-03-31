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

#include <internal/utils.hpp>
#include "kuzzle.hpp"
#include "internal/notification_result.hpp"

namespace kuzzleio {

    NotificationResult::NotificationResult(notification_result *src) : _nr(src) {
        _result = src->result ? new NotificationContent(src->result) : nullptr;
    }


    const char* NotificationResult::requestId() const {
        return _nr->request_id;
    }

    NotificationContent* NotificationResult::result() const {
        return _result ? _result : nullptr;
    }

    const char* NotificationResult::volatiles() const {
        return _nr->volatiles;
    }

    const char* NotificationResult::index() const {
        return _nr->index;
    }

    const char* NotificationResult::collection() const {
        return _nr->collection;
    }

    const char* NotificationResult::controller() const {
        return _nr->controller;
    }

    const char* NotificationResult::action() const {
        return _nr->action;
    }

    const char* NotificationResult::protocol() const {
        return _nr->protocol;
    }

    const char* NotificationResult::scope() const {
        return _nr->scope;
    }

    const char* NotificationResult::state() const {
        return _nr->state;
    }

    const char* NotificationResult::user() const {
        return _nr->user;
    }

    const char* NotificationResult::nType() const {
        return _nr->n_type;
    }

    const char* NotificationResult::roomId() const {
        return _nr->room_id;
    }

    const uint64_t NotificationResult::timestamp() const {
        return _nr->timestamp;
    }

    const int NotificationResult::status() const {
        return _nr->status;
    }

    const char* NotificationResult::error() const {
        return _nr->error;
    }

    const char* NotificationResult::stack() const {
        return _nr->stack;
    }
}