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

#ifndef _TOKEN_VALIDITY_HPP
#define _TOKEN_VALIDITY_HPP

#include <string>
#include <vector>
#include "utils.hpp"
#include "core.hpp"

namespace kuzzleio {
  class TokenValidity {
    private:
      bool _valid;
      const std::string _state;
      unsigned long long _expiresAt;
      int _status;
      const std::string _error;
      const std::string _stack;

    public:
      TokenValidity(token_validity* src) :
        _valid(src->valid),
        _state(src->state),
        _expiresAt(src->expires_at),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        { kuzzle_free_token_validity(src); };

      bool valid() const;

      const std::string &state() const;

      unsigned long long int expiresAt() const;

      int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif