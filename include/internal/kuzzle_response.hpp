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

#ifndef _KUZZLE_RESULT_HPP
#define _KUZZLE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleResponse {
    private:
      kuzzle_response* _kr = nullptr;

    public:
      KuzzleResponse(const kuzzle_response* src);

      virtual inline ~KuzzleResponse() { kuzzle_free_kuzzle_response(_kr); };

      const char* requestId() const;

      const char* result() const;

      const char* volatiles() const;

      const char* index() const;

      const char* collection() const;

      const char* controller() const;

      const char* action() const;

      const char* roomId() const;

      const char* channel() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;;
  };
}

#endif