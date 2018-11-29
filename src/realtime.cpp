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
  Realtime::Realtime(Kuzzle *kuzzle) {
    _realtime = new realtime();
    kuzzle_new_realtime(_realtime, kuzzle->_kuzzle);
  }

  Realtime::Realtime(Kuzzle *kuzzle, realtime *realtime) {
    _realtime = realtime;
    kuzzle_new_realtime(_realtime, kuzzle->_kuzzle);
  }

  Realtime::~Realtime() {
    unregisterRealtime(_realtime);
    delete(_realtime);
  }

  int Realtime::count(const std::string& roomId, query_options *options) {
    int_result *r = kuzzle_realtime_count(_realtime, const_cast<char*>(roomId.c_str()), options);
    if (r->error != nullptr)
        throwExceptionFromStatus(r);
    int ret = r->result;
    kuzzle_free_int_result(r);
    return ret;
  }

  NotificationListener* Realtime::getListener(const std::string& roomId) {
    return _listener_instances[roomId];
  }

  void call_subscribe_cb(notification_result* res, void* data) {
    if (data) {
      NotificationListener* listener = static_cast<Realtime*>(data)->getListener(res->room_id);

      if (listener) {
        (*listener)(res);
      }
    }
  }

  void Realtime::publish(const std::string& index, const std::string& collection, const std::string& body, query_options *options) {
    error_result *r = kuzzle_realtime_publish(_realtime, const_cast<char*>(index.c_str()), const_cast<char*>(collection.c_str()), const_cast<char*>(body.c_str()), options);
    if (r != nullptr)
        throwExceptionFromStatus(r);
    kuzzle_free_error_result(r);
  }

  std::string Realtime::subscribe(const std::string& index, const std::string& collection, const std::string& body, NotificationListener* cb, room_options* options) {
    subscribe_result *r = kuzzle_realtime_subscribe(_realtime, const_cast<char*>(index.c_str()), const_cast<char*>(collection.c_str()),  const_cast<char*>(body.c_str()), call_subscribe_cb, this, options);
    if (r->error != nullptr)
        throwExceptionFromStatus(r);

    std::string roomId = r->room;
    std::string channel = r->channel;

    _listener_instances[channel] = cb;
    kuzzle_free_subscribe_result(r);
    return roomId;
  }

  void Realtime::unsubscribe(const std::string& roomId, query_options *options) {
    error_result *r = kuzzle_realtime_unsubscribe(_realtime, const_cast<char*>(roomId.c_str()), options);
    if (r != nullptr)
        throwExceptionFromStatus(r);

    _listener_instances[roomId] = nullptr;
    kuzzle_free_error_result(r);
  }
}
