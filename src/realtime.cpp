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

#include "kuzzle.hpp"
#include "internal/realtime.hpp"

namespace kuzzleio {
  Realtime::Realtime(kuzzle *kuzzle) {
    _realtime = kuzzle_get_realtime_controller(kuzzle);
    kuzzle_new_realtime(_realtime, kuzzle);
  }

  Realtime::~Realtime() {
    unregisterRealtime(_realtime);

    // do not use "delete":
    // _realtime is allocated in the cgo world, using calloc
    free(_realtime);
  }

  // Internal use only
  NotificationListener* Realtime::getListener(const std::string& room_id) {
    return _listener_instances[room_id];
  }

  // Internal use only
  void call_subscribe_cb(notification_result* res, void* realtime_controller) {
    if (realtime_controller) {
      NotificationListener* listener = 
        static_cast<Realtime*>(realtime_controller)->getListener(res->room_id);

      if (listener) {
        (*listener)(res);
      }
    }
  }


  int Realtime::count(const std::string& room_id) {
    return this->count(room_id, query_options());
  }

  int Realtime::count(
      const std::string& room_id, 
      const query_options& options) {
    KUZZLE_API(int_result, r, kuzzle_realtime_count(
      _realtime,
      const_cast<char*>(room_id.c_str()),
      const_cast<query_options*>(&options)))

    int ret = r->result;
    kuzzle_free_int_result(r);

    return ret;
  }


  void Realtime::publish(const std::string& index, const std::string& collection, const std::string& message) {
    this->publish(index, collection, message, query_options());
  }

  void call_subscribe_cb(notification_result* res, void* data) {
    if (data) {
      std::cout << "CALL SUBSCRIBE CB" << std::endl;
      NotificationListener* listener =
        static_cast<Realtime*>(data)->getListener(res->room_id);

      if (listener) {
        (*listener)(res);
      }

      kuzzle_free_notification_result(res);
    }
  }

  void Realtime::publish(
      const std::string& index, 
      const std::string& collection, 
      const std::string& message) {
    this->publish(index, collection, message, query_options());
  }

  void Realtime::publish(const std::string& index, const std::string& collection, const std::string& body, query_options *options) {
    KUZZLE_API(
      error_result,
      r,
      kuzzle_realtime_publish(
        _realtime, 
        const_cast<char*>(index.c_str()), 
        const_cast<char*>(collection.c_str()), 
        const_cast<char*>(body.c_str()), options))

    kuzzle_free_error_result(r);
  }

  std::string Realtime::subscribe(
      const std::string& index, 
      const std::string& collection, 
      const std::string& filters, 
      NotificationListener* listener) {
    return this->subscribe(index, collection, filters, listener, room_options());
  }

  std::string Realtime::subscribe(
      const std::string& index,
      const std::string& collection,
      const std::string& filters,
      NotificationListener* listener,
      const room_options& options) {
    KUZZLE_API(
      subscribe_result,
      r,
      kuzzle_realtime_subscribe(_realtime, const_cast<char*>(index.c_str()),
                                const_cast<char*>(collection.c_str()),
                                const_cast<char*>(filters.c_str()),
                                call_subscribe_cb, this, 
                                const_cast<room_options*>(&options)))

    std::string room_id = r->room;
    _listener_instances[r->channel] = listener;
    kuzzle_free_subscribe_result(r);

    return room_id;
  }

  void Realtime::unsubscribe(const std::string& room_id) {
    return this->unsubscribe(room_id, query_options());
  }

  void Realtime::unsubscribe(
      const std::string& room_id, 
      const query_options& options) {
    KUZZLE_API(
      error_result,
      r,
      kuzzle_realtime_unsubscribe(_realtime, const_cast<char*>(roomId.c_str()),
                                  const_cast<options*>(&options)))

    _listener_instances[room_id] = nullptr;
    kuzzle_free_error_result(r);
  }
}
