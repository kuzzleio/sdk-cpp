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

#ifndef _EVENT_EMITTER_HPP_
#define _EVENT_EMITTER_HPP_

#include <functional>
#include <memory>
#include <unordered_map>
#include <set>
#include "internal/core.hpp"

namespace kuzzleio {
  typedef std::function<void(const std::string&)> EventListener;
  typedef std::shared_ptr<EventListener> SharedEventListener;

  // standard bridge triggering a KuzzleEventEmitter event
  void _c_emit_event(int, char*, void*);

  class KuzzleEventEmitter {
    private:
      virtual void emitEventOnce(Event, const std::string& payload) noexcept;

    protected:
      std::unordered_map<Event, std::set<SharedEventListener>> listeners;
      std::unordered_map<Event, std::set<SharedEventListener>> onceListeners;

    public:
      KuzzleEventEmitter() = default;
      virtual ~KuzzleEventEmitter() = default;

      virtual void emitEvent(Event, const std::string& payload) noexcept;
      virtual KuzzleEventEmitter* addListener(
          Event,
          SharedEventListener) noexcept;
      virtual KuzzleEventEmitter* removeListener(
          Event,
          SharedEventListener) noexcept;
      virtual KuzzleEventEmitter* removeAllListeners(Event) noexcept;
      virtual KuzzleEventEmitter* once(Event, SharedEventListener) noexcept;
      virtual int listenerCount(Event) noexcept;
  };
}

#endif
