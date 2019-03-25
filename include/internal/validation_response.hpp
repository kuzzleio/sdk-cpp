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

#ifndef _VALIDATION_RESPONSE_HPP
#define _VALIDATION_RESPONSE_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class ValidationResponse {
    private:
        validation_response* _vr = nullptr;
        std::vector<std::string> _details;

    public:
      ValidationResponse(validation_response* src);

      virtual inline ~ValidationResponse() { kuzzle_free_validation_response(_vr); };

      const bool valid() const;

      const std::vector<std::string> &details() const;

      const char* description() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;;
  };
}

#endif