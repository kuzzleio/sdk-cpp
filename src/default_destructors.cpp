// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "internal/core.hpp"

namespace kuzzleio {
  s_token_validity::~s_token_validity() {
    kuzzle_free_token_validity(this);
  }

  s_kuzzle_user::~s_kuzzle_user() {
    kuzzle_free_kuzzle_user(this);
  }

  s_user_right::~s_user_right() {
    kuzzle_free_user_right(this);
  }

  s_validation_response::~s_validation_response() {
    kuzzle_free_validation_response(this);
  }

  s_kuzzle_response::~s_kuzzle_response() {
    kuzzle_free_kuzzle_response(this);
  }
}
