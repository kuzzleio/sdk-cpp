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

#ifndef _USER_RIGHT_HPP_
#define _USER_RIGHT_HPP_

#include "core.hpp"
#include <string>

namespace kuzzleio {
  class UserRight {
    private:
      user_right* _ur = nullptr;

    public:
      UserRight(user_right* src);

      UserRight(const UserRight& src);

      virtual inline ~UserRight() { kuzzle_free_user_right(_ur); };

      const char* controller() const;

      const char* action() const;

      const char* index() const;

      const char* collection() const;

      const char* value() const;;
  };
}

#endif
