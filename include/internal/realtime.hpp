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

#ifndef _KUZZLE_REALTIME_HPP
#define _KUZZLE_REALTIME_HPP

#include <map>
#include <functional>
#include <memory>

#include "exceptions.hpp"
#include "core.hpp"
#include "internal/notification_result.hpp"

namespace kuzzleio {
  typedef std::function<void(const NotificationResult&)>
    NotificationListener;

  class Kuzzle;
  class QueryOptions;
  class Realtime {
    private:
      realtime *_realtime;
      std::map<std::string, NotificationListener*> _listener_instances;

    public:
      Realtime(kuzzle* kuzzle);
      virtual ~Realtime();

      int count(const std::string& room_id);
      int count(const std::string& room_id, const QueryOptions& options);

      void publish(const std::string& index, const std::string& collection,
          const std::string& message);
      void publish(const std::string& index, const std::string& collection,
          const std::string& message, const QueryOptions& options);

      std::string subscribe(const std::string& index,
          const std::string& collection, const std::string& filters,
          NotificationListener* listener);
      std::string subscribe(const std::string& index,
          const std::string& collection, const std::string& filters,
          NotificationListener* listener, const room_options& options);

      void unsubscribe(const std::string& room_id);
      void unsubscribe(const std::string& room_id,
          const QueryOptions& options);

      // Internal usage only
      NotificationListener* getListener(const std::string& room_id);
  };
}

#endif
