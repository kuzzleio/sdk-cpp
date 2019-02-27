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

#include <exception>
#include <stdexcept>
#include <cstdlib>

#include "kuzzle.hpp"
#include "internal/event_emitter.hpp"

namespace kuzzleio {
  Kuzzle::Kuzzle(Protocol* proto) : Kuzzle(proto, Options()) {}

<<<<<<< HEAD
  // Bridges for protocol
  void bridge_cpp_add_listener(int event, kuzzle_event_listener* listener, void* protocol_instance) {
    EventListener *l = new std::function<void(const std::string)>([=](const std::string& res) {
      if (res != "null") {
        (*listener)(event, const_cast<char*>(res.c_str()), protocol_instance);
      } else {
        (*listener)(event, nullptr, protocol_instance);
      }
    });

    static_cast<Protocol*>(protocol_instance)->listener_instances[event].insert(std::make_pair(listener, l));
    static_cast<Protocol*>(protocol_instance)->addListener(static_cast<Event>(event), l);
  }

  void bridge_cpp_once(int event, kuzzle_event_listener* listener, void* data) {
    EventListener *l = new std::function<void(const std::string)>([=](const std::string& res) {
      if (res != "null") {
        (*listener)(event, const_cast<char*>(res.c_str()), data);
      } else {
        (*listener)(event, nullptr, data);
      }
      static_cast<Protocol*>(data)->listener_once_instances[event].erase(listener);
    });

    static_cast<Protocol*>(data)->listener_once_instances[event].insert(std::make_pair(listener, l));
    static_cast<Protocol*>(data)->once(static_cast<Event>(event), l);
  }

  static void bridge_cpp_remove_listener(int event, kuzzle_event_listener* listener, void* data) {
    static_cast<Protocol*>(data)->removeListener(static_cast<Event>(event), static_cast<Protocol*>(data)->listener_instances[event][listener]);
    delete static_cast<Protocol*>(data)->listener_instances[event][listener];
  }

  static void bridge_cpp_emit_event(int event, void* res, void* data) {
    static_cast<Protocol*>(data)->emitEvent((Event)event);
  }

  char* bridge_cpp_connect(void* data) {
    try {
      static_cast<Protocol*>(data)->connect();
    } catch (KuzzleException& e) {
      return const_cast<char*>(e.what());
    }
    return nullptr;
  }

  int bridge_cpp_get_state(void* data) {
    return static_cast<Protocol*>(data)->getState();
  }

  kuzzle_response* bridge_cpp_send(const char* query, query_options* options, char* request_id, void* data) {
    return static_cast<Protocol*>(data)->send(std::string(query), options, std::string(request_id));
  }

  int bridge_cpp_listener_count(int event, void* data) {
    return static_cast<Protocol*>(data)->listenerCount(static_cast<Event>(event));
  }

  const char* bridge_cpp_close(void* data) {
    try {
      static_cast<Protocol*>(data)->close();
    } catch (KuzzleException& e) {
      return e.what();
    }
    return nullptr;
  }

  void bridge_cpp_register_sub(const char* channel, const char* room_id, const char* filters, bool subscribe_to_self, kuzzle_notification_listener* listener, void* data) {
    NotificationListener *nl = new std::function<void(kuzzleio::NotificationResult*)>([=](kuzzleio::NotificationResult* res) {
      notification_result nr;
      notification_content nc;

      if (res->result.meta) {
        meta m;

        m.author = res->result.meta->author.c_str();
        m.created_at = res->result.meta->created_at;
        m.updated_at = res->result.meta->updated_at;
        m.updater = res->result.meta->updater.c_str();
        m.active = res->result.meta->active;
        m.deleted_at = res->result.meta->deleted_at;
        nc.m = &m;

        nc.content = res->result.content.c_str();
        nc.count = res->result.count;
        nc.id = res->result.id.c_str();
      }

      nr.request_id = res->request_id.c_str();
      nr.result = &nc;
      nr.volatiles = res->volatiles.c_str();
      nr.index = res->index.c_str();
      nr.collection = res->collection.c_str();
      nr.controller = res->controller.c_str();
      nr.action = res->action.c_str();
      nr.protocol = res->protocol.c_str();
      nr.scope = res->scope.c_str();
      nr.state = res->state.c_str();
      nr.user = res->user.c_str();
      nr.n_type = res->n_type.c_str();
      nr.room_id = res->room_id.c_str();
      nr.timestamp = res->timestamp;
      nr.status = res->status;
      nr.error = res->error.c_str();
      nr.stack = res->stack.c_str();

      (*listener)(&nr, data);
    });

    static_cast<Protocol*>(data)->notification_listener_instances[channel] = nl;
    static_cast<Protocol*>(data)->registerSub(std::string(channel), std::string(room_id), std::string(filters), subscribe_to_self, nl);
  }

  void bridge_cpp_unregister_sub(const char* id, void* data) {
    static_cast<Protocol*>(data)->unregisterSub(std::string(id));
    static_cast<Protocol*>(data)->notification_listener_instances[id] = nullptr;
  }

  void bridge_cpp_cancel_subs(void* data) {
    static_cast<Protocol*>(data)->cancelSubs();
  }

  void bridge_cpp_start_queuing(void* data) {
    static_cast<Protocol*>(data)->startQueuing();
  }

  void bridge_cpp_stop_queuing(void* data) {
    static_cast<Protocol*>(data)->stopQueuing();
  }

  void bridge_cpp_play_queue(void* data) {
    static_cast<Protocol*>(data)->playQueue();
  }

  void bridge_cpp_clear_queue(void* data) {
    static_cast<Protocol*>(data)->clearQueue();
  }

  void bridge_cpp_remove_all_listeners(int event, void* data) {
    static_cast<Protocol*>(data)->removeAllListeners(static_cast<Event>(event));
  }

  const char* bridge_cpp_get_host(void* data) {
    return static_cast<Protocol*>(data)->getHost().c_str();
  }

  // Class
  KuzzleException::KuzzleException(int status, const std::string& error)
    : std::runtime_error(error), status(status) {}

  std::string KuzzleException::getMessage() const {
    return what();
  }

  Kuzzle::Kuzzle(Protocol* proto, options *opts) {
=======
  Kuzzle::Kuzzle(Protocol* proto, const Options& options) {
>>>>>>> origin/1-dev
    this->_kuzzle = new kuzzle();
    this->_protocol = new_protocol_bridge(proto);

    kuzzle_new_kuzzle(
      this->_kuzzle,
      this->_protocol,
      options.c_opts());

    this->document = new Document(_kuzzle);
    this->auth = new Auth(_kuzzle);
    this->index = new Index(_kuzzle);
    this->server = new Server(_kuzzle);
    this->collection = new Collection(_kuzzle);
    this->realtime = new Realtime(_kuzzle);
  }

  Kuzzle::~Kuzzle() {
    unregisterKuzzle(this->_kuzzle);
    delete this->_kuzzle;

    delete this->_protocol;

    delete this->document;
    delete this->auth;
    delete this->index;
    delete this->server;
    delete this->collection;
    delete this->realtime;
  }

  void Kuzzle::connect() {
    char * err = kuzzle_connect(_kuzzle);

    if (err != nullptr) {
      const std::string cppError = err;
      free(err);
      throw InternalException(cppError);
    }
  }

  void Kuzzle::disconnect() noexcept {
    kuzzle_disconnect(_kuzzle);
  }

<<<<<<< HEAD
  KuzzleResponse Kuzzle::query(kuzzle_request* query, query_options* options) {
    KUZZLE_API(kuzzle_response, r, kuzzle_query(_kuzzle, query, options))

    KuzzleResponse res(r);
    kuzzle_free_kuzzle_response(r);
    return res;
=======
  kuzzle_response* Kuzzle::query(const kuzzle_request& request) {
    return this->query(request, query_options());
  }

  kuzzle_response* Kuzzle::query(
      const kuzzle_request& request,
      const query_options& options) {
    KUZZLE_API(kuzzle_response, r, kuzzle_query(
        _kuzzle,
        const_cast<kuzzle_request*>(&request),
        const_cast<query_options*>(&options)))
    return r;
>>>>>>> origin/1-dev
  }

  Kuzzle* Kuzzle::playQueue() noexcept {
    kuzzle_play_queue(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::setAutoReplay(bool auto_replay) noexcept {
    kuzzle_set_auto_replay(_kuzzle, auto_replay);
    return this;
  }

  Kuzzle* Kuzzle::startQueuing() noexcept {
    kuzzle_start_queuing(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::stopQueuing() noexcept {
    kuzzle_stop_queuing(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::flushQueue() noexcept {
    kuzzle_flush_queue(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::setVolatile(const std::string& volatile_data) noexcept {
    kuzzle_set_volatile(_kuzzle, const_cast<char*>(volatile_data.c_str()));
    return this;
  }

  std::string Kuzzle::getVolatile() noexcept {
    return std::string(kuzzle_get_volatile(_kuzzle));
  }

  std::string Kuzzle::getJwt() noexcept {
    return std::string(kuzzle_get_jwt(_kuzzle));
  }

  Protocol* Kuzzle::getProtocol() noexcept {
    return static_cast<Protocol*>(this->_protocol->instance);
  }

  void Kuzzle::emitEvent(Event event, const std::string& body) noexcept {
    kuzzle_emit_event(_kuzzle, event, const_cast<char*>(body.c_str()));
    KuzzleEventEmitter::emitEvent(event, body);
  }

  KuzzleEventEmitter* Kuzzle::addListener(Event event,
    SharedEventListener listener) noexcept {

    kuzzle_add_listener(_kuzzle, event, _c_emit_event, this);

    return KuzzleEventEmitter::addListener(event, listener);
  }

  KuzzleEventEmitter* Kuzzle::removeListener(
      Event event,
      SharedEventListener listener) noexcept {
    KuzzleEventEmitter::removeListener(event, listener);

    // if no listener remains, we need to unregister it from the go kuzzle
    // layers
    if (this->listeners.find(event) == this->listeners.end()) {
      kuzzle_remove_listener(_kuzzle, event, _c_emit_event);
    }

    return this;
  }

  KuzzleEventEmitter* Kuzzle::removeAllListeners(Event event) noexcept {
    kuzzle_remove_all_listeners(_kuzzle, event);

    return KuzzleEventEmitter::removeAllListeners(event);
  }

<<<<<<< HEAD
  KuzzleEventEmitter* Kuzzle::once(Event event, EventListener* listener) {
    kuzzle_once(_kuzzle, event, &trigger_event_listener, this);

    return this;
=======
  KuzzleEventEmitter* Kuzzle::once(
      Event event,
      SharedEventListener listener) noexcept {
    kuzzle_once(_kuzzle, event, &_c_emit_event, this);
    return KuzzleEventEmitter::once(event, listener);
>>>>>>> origin/1-dev
  }
}
