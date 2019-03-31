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

#ifndef _META_HPP
#define _META_HPP

#include <string>
#include "utils.hpp"

namespace kuzzleio {
  class Meta {
    private:
      meta* _m = nullptr;

    public:
      Meta(meta* src) : _m(src) {};

      virtual inline ~Meta() { kuzzle_free_meta(_m); };

      const char * author() const;

      const uint64_t createdAt() const;

      const uint64_t updatedAt() const;

      const char * updater() const;

      const bool active() const;

      const uint64_t deletedAt() const;

  };
}

#endif