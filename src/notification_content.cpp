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
#include "internal/notification_content.hpp"

namespace kuzzleio {

    NotificationContent::NotificationContent(notification_content *src) {
        _nc = (notification_content*)malloc(sizeof(notification_content));
        _nc->id = toC::dupstring(src->id);
        if (src->m != nullptr) {
            _meta = new Meta(src->m);
            _meta->m()->author = toC::dupstring(src->m->author);
            _meta->m()->created_at = src->m->created_at;
            _meta->m()->updated_at = src->m->updated_at;
            _meta->m()->updater = toC::dupstring(src->m->updater);
            _meta->m()->active = src->m->active;
            _meta->m()->deleted_at = src->m->deleted_at;
        }
        _nc->m = nullptr;
        _nc->content = toC::dupstring(src->content);
        _nc->count = src->count;
    }

    const char* NotificationContent::id() const {
        return _nc->id;
    }

    const Meta* NotificationContent::m() const {

        return _meta ? _meta : nullptr;
    }

    const char* NotificationContent::content() const {
        return _nc->content;
    }

    const int NotificationContent::count() const {
        return _nc->count;
    }
}