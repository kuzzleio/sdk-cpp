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

    NotificationResult::NotificationResult(notification_result *src) {
        _nr = (notification_result*)malloc(sizeof(notification_result));
        _nr->request_id = toC::dupstring(src->request_id);
        _nr->result = NULL;
        _result = src->result ? new NotificationContent(src->result) : nullptr;
        _nr->volatiles = toC::dupstring(src->volatiles);
        _nr->index = toC::dupstring(src->index);
        _nr->collection = toC::dupstring(src->collection);
        _nr->controller = toC::dupstring(src->controller);
        _nr->action = toC::dupstring(src->action);
        _nr->protocol = toC::dupstring(src->protocol);
        _nr->scope = toC::dupstring(src->scope);
        _nr->state = toC::dupstring(src->state);
        _nr->user = toC::dupstring(src->user);
        _nr->n_type = toC::dupstring(src->n_type);
        _nr->room_id = toC::dupstring(src->room_id);
        _nr->timestamp = src->timestamp;
        _nr->status = src->status;
        _nr->error = toC::dupstring(src->error);
        _nr->stack = toC::dupstring(src->stack);
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