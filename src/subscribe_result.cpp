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
#include "internal/subscribe_result.hpp"

namespace kuzzleio {

    SubscribeResult::SubscribeResult(subscribe_result *src) {
        _sr = (subscribe_result*)malloc(sizeof(subscribe_result));
        _sr->room = toC::dupstring(src->room);
        _sr->channel = toC::dupstring(src->channel);
        _sr->status = src->status;
        _sr->error = toC::dupstring(src->error);
        _sr->stack = toC::dupstring(src->stack);
    }

    const char* SubscribeResult::room() const {
        return _sr->room;
    }

    const char* SubscribeResult::channel() const {
        return _sr->channel;
    }

    const int SubscribeResult::status() const {
        return _sr->status;
    }

    const char* SubscribeResult::error() const {
        return _sr->error;
    }

    const char* SubscribeResult::stack() const {
        return _sr->stack;
    }
}