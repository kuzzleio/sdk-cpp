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
#include "internal/meta.hpp"

namespace kuzzleio {

    Meta::Meta(meta *src) {
        _m = (meta*)malloc(sizeof(meta));
        _m->author = toC::dupstring(src->author);
        _m->created_at = src->created_at;
        _m->updated_at = src->updated_at;
        _m->updater = toC::dupstring(src->updater);
        _m->active = src->active;
        _m->deleted_at = src->deleted_at;
    }

    meta* Meta::m() const {
        return _m;
    }

    const char * Meta::author() const {
        return _m->author;
    }

    const uint64_t Meta::createdAt() const {
        return _m->created_at;
    }

    const uint64_t Meta::updatedAt() const {
        return _m->updated_at;
    }

    const char * Meta::updater() const {
        return _m->updater;
    }

    const bool Meta::active() const {
        return _m->active;
    }

    const uint64_t Meta::deletedAt() const {
        return _m->deleted_at;
    }
}