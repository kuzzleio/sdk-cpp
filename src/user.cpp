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
  User& User::operator=(const kuzzle_user* u) {
    _id = u->id;
    _content = u->content;
    _profile_ids = std::vector<std::string>(u->profile_ids, u->profile_ids + u->profile_ids_length);

    return *this;
  }

  std::string const& User::id() const {
    return _id;
  }

  std::string const& User::content() const {
    return _content;
  }

  std::vector<std::string> const& User::profile_ids() const {
    return _profile_ids;
  }
}
