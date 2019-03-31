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

#ifndef _NOTIFICATION_CONTENT_HPP
#define _NOTIFICATION_CONTENT_HPP

#include <string>
#include "meta.hpp"
#include "core.hpp"
#include "utils.hpp"

namespace kuzzleio {
    class NotificationContent {
      private:
        notification_content* _nc = nullptr;
        Meta* _meta = nullptr;

      public:
        NotificationContent(notification_content* src);

        virtual inline ~NotificationContent() { delete _meta; kuzzle_free_notification_content(_nc); };

        const char* id() const;

        const Meta* m() const;

        const char* content() const;

        const int count() const;;
  };
}

#endif