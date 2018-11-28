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
#include "internal/event_emitter.hpp"

namespace kuzzleio {

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
    return static_cast<Protocol*>(data)->connect();
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
    return static_cast<Protocol*>(data)->close().c_str();
  }

  void bridge_cpp_register_sub(const char* channel, const char* room_id, const char* filters, bool subscribe_to_self, kuzzle_notification_listener* listener, void* data) {
    NotificationListener *nl = new std::function<void(kuzzleio::notification_result*)>([=](kuzzleio::notification_result* res) {
      (*listener)(res, data);
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

  bool bridge_cpp_is_auto_reconnect(void* data) {
    return static_cast<Protocol*>(data)->isAutoReconnect();
  }

  bool bridge_cpp_is_auto_resubscribe(void* data) {
    return static_cast<Protocol*>(data)->isAutoResubscribe();
  }

  const char* bridge_cpp_get_host(void* data) {
    return static_cast<Protocol*>(data)->getHost().c_str();
  }

  unsigned int bridge_cpp_get_port(void* data) {
    return static_cast<Protocol*>(data)->getPort();
  }

  unsigned long long bridge_cpp_get_reconnection_delay(void* data) {
    return static_cast<Protocol*>(data)->getReconnectionDelay();
  }

  bool bridge_cpp_is_ssl_connection(void* data) {
    return static_cast<Protocol*>(data)->isSslConnection();
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

    proto->_protocol->add_listener = bridge_cpp_add_listener;
    proto->_protocol->once = bridge_cpp_once;
    proto->_protocol->remove_listener = bridge_cpp_remove_listener;
    proto->_protocol->emit_event = bridge_cpp_emit_event;
    proto->_protocol->connect = bridge_cpp_connect;
    proto->_protocol->send = bridge_cpp_send;
    proto->_protocol->get_state = bridge_cpp_get_state;
    proto->_protocol->listener_count = bridge_cpp_listener_count;
    proto->_protocol->close = bridge_cpp_close;
    proto->_protocol->register_sub = bridge_cpp_register_sub;
    proto->_protocol->unregister_sub = bridge_cpp_unregister_sub;
    proto->_protocol->cancel_subs = bridge_cpp_cancel_subs;
    proto->_protocol->start_queuing = bridge_cpp_start_queuing;
    proto->_protocol->stop_queuing = bridge_cpp_stop_queuing;
    proto->_protocol->play_queue = bridge_cpp_play_queue;
    proto->_protocol->clear_queue = bridge_cpp_clear_queue;
    proto->_protocol->remove_all_listeners = bridge_cpp_remove_all_listeners;
    proto->_protocol->is_auto_reconnect = bridge_cpp_is_auto_reconnect;
    proto->_protocol->is_auto_resubscribe = bridge_cpp_is_auto_resubscribe;
    proto->_protocol->get_host = bridge_cpp_get_host;
    proto->_protocol->get_port = bridge_cpp_get_port;
    proto->_protocol->get_reconnection_delay = bridge_cpp_get_reconnection_delay;
    proto->_protocol->is_ssl_connection = bridge_cpp_is_ssl_connection;

    this->_protocol = proto->_protocol;
    this->_cpp_protocol = proto;

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

  Protocol* Kuzzle::getProtocol() noexcept {
    return _cpp_protocol;
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
    kuzzle_emit_event(_kuzzle, event, const_cast<char*>(body.c_str()));
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
