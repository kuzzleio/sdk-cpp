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

#include <algorithm>
#include "protocol.hpp"

namespace kuzzleio {
  // bridge functions
  static void bridge_cpp_remove_listener(
      int event,
      kuzzle_event_listener listener,
      void* _p) {

    static_cast<Protocol*>(_p)->removeListener(event, listener);
  }

  void bridge_cpp_add_listener(
      int event,
      kuzzle_event_listener listener,
      void* _p) {
    static_cast<Protocol*>(_p)->addListener(event, listener);
  }

  void bridge_cpp_once(int event, kuzzle_event_listener listener, void* _p) {
    static_cast<Protocol*>(_p)->addListener(event, listener);
  }

  static void bridge_cpp_emit_event(int event, void* payload, void* _p) {
    static_cast<Protocol*>(_p)->emitEvent(
        static_cast<Event>(event), static_cast<char*>(payload));
  }

  char* bridge_cpp_connect(void* _p) {
    try {
      static_cast<Protocol*>(_p)->connect();
    } catch (std::exception& e) {
      return const_cast<char*>(e.what());
    }
    return nullptr;
  }

  int bridge_cpp_get_state(void* _p) {
    return static_cast<Protocol*>(_p)->getState();
  }

  kuzzle_response* bridge_cpp_send(
      const char* query,
      query_options* options,
      char* request_id,
      void* _p) {
    return static_cast<Protocol*>(_p)->send(query, options, request_id);
  }

  int bridge_cpp_listener_count(int event, void* _p) {
    return static_cast<Protocol*>(_p)->listenerCount(static_cast<Event>(event));
  }

  const char* bridge_cpp_close(void* _p) {
    try {
      static_cast<Protocol*>(_p)->close();
    } catch (std::exception& e) {
      return e.what();
    }
    return nullptr;
  }

  void bridge_cpp_register_sub(
      const char* channel,
      const char* room_id,
      const char* filters,
      bool subscribe_to_self,
      kuzzle_notification_listener listener,
      void* _p) {

    static_cast<Protocol*>(_p)->registerSub(channel, room_id, filters,
                                            subscribe_to_self, listener);
  }

  void bridge_cpp_unregister_sub(const char* channel, void* _p) {
    static_cast<Protocol*>(_p)->unregisterSub(channel);
  }

  void bridge_cpp_cancel_subs(void* _p) {
    static_cast<Protocol*>(_p)->cancelSubs();
  }

  void bridge_cpp_start_queuing(void* _p) {
    static_cast<Protocol*>(_p)->startQueuing();
  }

  void bridge_cpp_stop_queuing(void* _p) {
    static_cast<Protocol*>(_p)->stopQueuing();
  }

  void bridge_cpp_play_queue(void* _p) {
    static_cast<Protocol*>(_p)->playQueue();
  }

  void bridge_cpp_clear_queue(void* _p) {
    static_cast<Protocol*>(_p)->clearQueue();
  }

  void bridge_cpp_remove_all_listeners(int event, void* _p) {
    static_cast<Protocol*>(_p)->removeAllListeners(static_cast<Event>(event));
  }

  const char* bridge_cpp_get_host(void* _p) {
    return static_cast<Protocol*>(_p)->getHost().c_str();
  }

  protocol* new_protocol_bridge(Protocol * cppProtocol) {
    protocol *p = new protocol();

    p->instance = cppProtocol;
    p->add_listener = bridge_cpp_add_listener;
    p->once = bridge_cpp_once;
    p->remove_listener = bridge_cpp_remove_listener;
    p->emit_event = bridge_cpp_emit_event;
    p->connect = bridge_cpp_connect;
    p->send = bridge_cpp_send;
    p->get_state = bridge_cpp_get_state;
    p->listener_count = bridge_cpp_listener_count;
    p->close = bridge_cpp_close;
    p->register_sub = bridge_cpp_register_sub;
    p->unregister_sub = bridge_cpp_unregister_sub;
    p->cancel_subs = bridge_cpp_cancel_subs;
    p->start_queuing = bridge_cpp_start_queuing;
    p->stop_queuing = bridge_cpp_stop_queuing;
    p->play_queue = bridge_cpp_play_queue;
    p->clear_queue = bridge_cpp_clear_queue;
    p->remove_all_listeners = bridge_cpp_remove_all_listeners;
    p->get_host = bridge_cpp_get_host;

    return p;
  }

  // Protocol class implementation
  void Protocol::addListener(int event, kuzzle_event_listener listener) {
    auto bl = this->bridgeListeners.find(listener);

    if (bl == this->bridgeListeners.end()) {
      auto bridge = std::make_shared<EventListener>(
          [=](const std::string& payload) {
        if (payload != "null") {
          (*listener)(event, const_cast<char*>(payload.c_str()), this);
        } else {
          (*listener)(event, nullptr, this);
        }
      });

      this->bridgeListeners[listener] = bridge;
      this->addListener(static_cast<Event>(event), bridge);
    }
  }

  void Protocol::once(int event, kuzzle_event_listener listener) {
    auto bl = bridgeListeners.find(listener);

    // do not add a "once" listener if a permanent one is already registered
    if (bl == bridgeListeners.end()) {
      auto bridge = std::make_shared<EventListener>(
          [=](const std::string& payload) {
        this->bridgeListeners.erase(listener);

        if (payload != "null") {
          (*listener)(event, const_cast<char*>(payload.c_str()), this);
        } else {
          (*listener)(event, nullptr, this);
        }
      });

      bridgeListeners[listener] = bridge;
      this->once(static_cast<Event>(event), bridge);
    }
  }

  void Protocol::removeListener(int event, kuzzle_event_listener listener) {
    auto l = this->bridgeListeners.find(listener);

    if (l != this->bridgeListeners.end()) {
      this->removeListener(static_cast<Event>(event), l->second);

      if (l->second.use_count() == 1) {
        this->bridgeListeners.erase(listener);
      }
    }
  }

  void Protocol::cancelSubs() {
    this->bridgeSubs.clear();
    this->notificationListeners.clear();
  }

  void Protocol::registerSub(
        const std::string& channel,
        const std::string& roomId,
        const std::string& filters, bool subscribetoSelf,
        kuzzle_notification_listener listener) {
    auto chan = this->bridgeSubs[channel];
    // do not create a new shared pointer on a already existing listener
    if (chan.find(listener) == chan.end()) {
      auto nl = std::make_shared<NotificationListener>(
          [listener, this](std::shared_ptr<notification_result> notification) {
        (*listener)(notification.get(), this);
      });

      chan[listener] = nl;
      this->registerSub(channel, roomId, filters, subscribetoSelf, nl);
    }
  }

  void Protocol::registerSub(
      const std::string& channel,
      const std::string& roomId,
      const std::string& filters,
      bool subscribetoSelf,
      std::shared_ptr<NotificationListener> listener) {
    this->notificationListeners[channel].insert(listener);
  }

  void Protocol::unregisterSub(std::string const& channel) {
    auto channelListeners = bridgeSubs.find(channel);

    if (channelListeners != bridgeSubs.end()) {
      // TODO remove only 1 listener once the go sdk is able to handle
      // multiple subscriptions
      // see https://github.com/kuzzleio/sdk-go/issues/232
      bridgeSubs.erase(channel);
      this->notificationListeners.erase(channel);
    }
  }

  KuzzleEventEmitter* Protocol::removeAllListeners(Event event) noexcept {
    // For each EventListener registered, we need to verify if there is a ref
    // in the bridgeListeners map
    // Highly inefficient, but there should only be a few listeners on each
    // event. To make this better, a reverse map is needed.
    auto elisteners = this->listeners.find(event);

    if (elisteners != this->listeners.end()) {
      for (auto elistener : elisteners->second) {
        auto bridge = std::find_if(
            this->bridgeListeners.begin(), this->bridgeListeners.end(),
            [=](std::pair<kuzzle_event_listener, SharedEventListener> vt)
            { return vt.second == elistener; });

        if (bridge != bridgeListeners.end()) {
          this->bridgeListeners.erase(bridge->first);
        }
      }
    }

    return KuzzleEventEmitter::removeAllListeners(event);
  }

  void Protocol::notify(NotificationResult* payload) noexcept {
    auto l = this->notificationListeners.find(payload->room_id);

    if (l != this->notificationListeners.end()) {
      std::shared_ptr<notification_result> notification(
        (notification_result*)payload,
        kuzzle_free_notification_result);

      for (auto sub : l->second) {
        (*sub)(notification);
      }
    } else {
      kuzzle_free_notification_result((notification_result*)payload);
    }
  }
}
