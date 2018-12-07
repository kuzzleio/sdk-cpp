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
#include "internal/user.hpp"

namespace kuzzleio {
  User::User() {}

  User::User(kuzzle_user* u) {
    id = u->id;
    content = u->content;

    for(size_t i = 0; i < u->profile_ids_length; i++) {
      profile_ids.push_back(u->profile_ids[i]);
    }
  }
}
