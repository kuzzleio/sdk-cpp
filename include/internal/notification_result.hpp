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

#ifndef _NOTIFICATION_RESULT_HPP
#define _NOTIFICATION_RESULT_HPP

#include <string>
#include "notification_content.hpp"

namespace kuzzleio {
  class NotificationResult {
    private:
      notification_result* _nr = nullptr;
      NotificationContent* _result = nullptr;

    public:
      NotificationResult(notification_result* src);

      const char* requestId() const;

      NotificationContent* result() const;

      const char* volatiles() const;

      const char* index() const;

      const char* collection() const;

      const char* controller() const;

      const char* action() const;

      const char* protocol() const;

      const char* scope() const;

      const char* state() const;

      const char* user() const;

      const char* nType() const;

      const char* roomId() const;

      const uint64_t timestamp() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;
  };
}

#endif