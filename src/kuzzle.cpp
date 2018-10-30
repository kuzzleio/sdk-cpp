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
#include "kuzzle.hpp"
#include "auth.hpp"
#include "index.hpp"
#include "server.hpp"
#include "protocol.hpp"
#include "collection.hpp"
#include "document.hpp"
#include "realtime.hpp"
#include "kuzzle.hpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <functional>

namespace kuzzleio {

  // Bridges for protocol
  void bridge_add_listener(int event, kuzzle_event_listener* listener, void* data) {
    EventListener *l = new std::function<void(const std::string)>([=](const std::string& res) {
      if (res != "") {
        (*listener)(event, const_cast<char*>(res.c_str()), data);        
      } else {
        (*listener)(event, NULL, data);
      }
    });

    static_cast<Protocol*>(data)->addListener((Event)event, l);
  }

  void bridge_emit_event(int event, void* res, void* data) {
    static_cast<Protocol*>(data)->emitEvent((Event)event);
  }

  char* bridge_connect(void* data) {
    return static_cast<Protocol*>(data)->connect();
  }

  int bridge_get_state(void* data) {
    return static_cast<Protocol*>(data)->getState();
  }

  kuzzle_response* bridge_send(const char* query, query_options* options, char* request_id, void* data) {
    return static_cast<Protocol*>(data)->send(std::string(query), options, std::string(request_id));
  }

  int bridge_listener_count(int event, void* data) {
    return static_cast<Protocol*>(data)->listenerCount((Event)event);
  }

  const char* bridge_close(void* data) {
    return static_cast<Protocol*>(data)->close().c_str();
  }

  void bridge_unregister_sub(const char* id, void* data) {
    static_cast<Protocol*>(data)->unregisterSub(std::string(id));
  }

  void bridge_cancel_subs(void* data) {
    static_cast<Protocol*>(data)->cancelSubs();
  }

  void bridge_start_queuing(void* data) {
    static_cast<Protocol*>(data)->startQueuing();
  }

  void bridge_stop_queuing(void* data) {
    static_cast<Protocol*>(data)->stopQueuing();
  }

  void bridge_play_queue(void* data) {
    static_cast<Protocol*>(data)->playQueue();
  }

  void bridge_clear_queue(void* data) {
    static_cast<Protocol*>(data)->clearQueue();
  }

  void bridge_remove_all_listeners(int event, void* data) {
    static_cast<Protocol*>(data)->removeAllListeners((Event)event);
  }

  // Class
  KuzzleException::KuzzleException(int status, const std::string& error)
    : std::runtime_error(error), status(status) {}

  std::string KuzzleException::getMessage() const {
    return what();
  }

  Kuzzle::Kuzzle(Protocol* proto, options *opts) {
    this->_kuzzle = new kuzzle();

    proto->_protocol = new protocol();
    proto->_protocol->instance = proto;

    proto->_protocol->add_listener = bridge_add_listener;
    proto->_protocol->emit_event = bridge_emit_event;
    proto->_protocol->connect = bridge_connect;
    proto->_protocol->send = bridge_send;
    proto->_protocol->get_state = bridge_get_state;
    proto->_protocol->listener_count = bridge_listener_count;
    proto->_protocol->close = bridge_close;
    proto->_protocol->unregister_sub = bridge_unregister_sub;
    proto->_protocol->cancel_subs = bridge_cancel_subs;
    proto->_protocol->start_queuing = bridge_start_queuing;
    proto->_protocol->stop_queuing = bridge_stop_queuing;
    proto->_protocol->play_queue = bridge_play_queue;
    proto->_protocol->clear_queue = bridge_clear_queue;
    proto->_protocol->remove_all_listeners = bridge_remove_all_listeners;

    this->_protocol = proto->_protocol;

    kuzzle_new_kuzzle(this->_kuzzle, this->_protocol, opts);

    this->document = new Document(this, kuzzle_get_document_controller(_kuzzle));
    this->auth = new Auth(this, kuzzle_get_auth_controller(_kuzzle));
    this->index = new Index(this, kuzzle_get_index_controller(_kuzzle));
    this->server = new Server(this, kuzzle_get_server_controller(_kuzzle));
    this->collection = new Collection(this, kuzzle_get_collection_controller(_kuzzle));
    this->realtime = new Realtime(this, kuzzle_get_realtime_controller(_kuzzle));
  }

  Kuzzle::~Kuzzle() {
    unregisterKuzzle(this->_kuzzle);
    unregisterProtocol(this->_protocol);
    delete(this->_kuzzle);
    delete(this->document);
    delete(this->auth);
    delete(this->index);
    delete(this->server);
    delete(this->collection);
    delete(this->realtime);
  }

  char* Kuzzle::connect() noexcept {
    return kuzzle_connect(_kuzzle);
  }

  void Kuzzle::disconnect() noexcept {
    kuzzle_disconnect(_kuzzle);
  }

  kuzzle_response* Kuzzle::query(kuzzle_request* query, query_options* options) {
    kuzzle_response *r = kuzzle_query(_kuzzle, query, options);
    if (r->error != nullptr)
        throwExceptionFromStatus(r);
    return r;
  }

  Kuzzle* Kuzzle::playQueue() noexcept {
    kuzzle_play_queue(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::setAutoReplay(bool autoReplay) noexcept {
    kuzzle_set_auto_replay(_kuzzle, autoReplay);
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

  Kuzzle* Kuzzle::setVolatile(const std::string& volatiles) noexcept {
    kuzzle_set_volatile(_kuzzle, const_cast<char*>(volatiles.c_str()));
    return this;
  }

  std::string Kuzzle::getVolatile() noexcept {
    return std::string(kuzzle_get_volatile(_kuzzle));
  }

  std::string Kuzzle::getJwt() noexcept {
    return std::string(kuzzle_get_jwt(_kuzzle));
  }

  void trigger_event_listener(int event, char* res, void* data) {
    EventListener* listener = static_cast<Kuzzle*>(data)->getListeners()[event];
    if (listener) {
      (*listener)(res);
    }
  }

  std::map<int, EventListener*> Kuzzle::getListeners() noexcept {
    return _listener_instances;
  }

  void Kuzzle::emitEvent(Event event, const std::string& body) noexcept {
    kuzzle_emit_event(_kuzzle, event, nullptr);
  }

  KuzzleEventEmitter* Kuzzle::addListener(Event event, EventListener* listener) {
    kuzzle_add_listener(_kuzzle, event, trigger_event_listener, this);
    _listener_instances[event] = listener;

    return this;
  }

  KuzzleEventEmitter* Kuzzle::removeListener(Event event, EventListener* listener) {
    kuzzle_remove_listener(_kuzzle, event, (void*)&trigger_event_listener);
    _listener_instances[event] = nullptr;

    return this;
  }

  KuzzleEventEmitter* Kuzzle::removeAllListeners(Event event) {
    kuzzle_remove_all_listeners(_kuzzle, event);

    return this;
  }

  KuzzleEventEmitter* Kuzzle::once(Event event, EventListener* listener) {
    kuzzle_once(_kuzzle, event, &trigger_event_listener, this);
  }

  int Kuzzle::listenerCount(Event event) {
    return kuzzle_listener_count(_kuzzle, event);
  }

}
