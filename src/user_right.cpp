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
#include "internal/user_right.hpp"

namespace kuzzleio {

    UserRight::UserRight(user_right *src) {
        _ur = static_cast<user_right*>(calloc(1, sizeof(user_right)));
        _ur->controller = toC::dupstring(src->controller);
        _ur->action = toC::dupstring(src->action);
        _ur->index = toC::dupstring(src->index);
        _ur->collection = toC::dupstring(src->collection);
        _ur->value = toC::dupstring(src->value);
    }

    UserRight::UserRight(const UserRight &src) {
        _ur = static_cast<user_right*>(calloc(1, sizeof(user_right)));
        _ur->controller = toC::dupstring(src._ur->controller);
        _ur->action = toC::dupstring(src._ur->action);
        _ur->index = toC::dupstring(src._ur->index);
        _ur->collection = toC::dupstring(src._ur->collection);
        _ur->value = toC::dupstring(src._ur->value);
    }

    const char* UserRight::controller() const {
        return _ur->controller;
    }

    const char* UserRight::action() const {
        return _ur->action;
    }

    const char* UserRight::index() const {
        return _ur->index;
    }

    const char* UserRight::collection() const {
        return _ur->collection;
    }

    const char* UserRight::value() const {
        return _ur->value;
    }
}