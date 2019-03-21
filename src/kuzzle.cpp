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

  Kuzzle::Kuzzle(Protocol* proto, const Options& options) {
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
  }

  Kuzzle* Kuzzle::playQueue() noexcept {
    kuzzle_play_queue(_kuzzle);
    return this;
  }

  Kuzzle* Kuzzle::autoReplay(bool auto_replay) noexcept {
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

  Kuzzle* Kuzzle::volatiles(const std::string& volatile_data) noexcept {
    kuzzle_set_volatile(_kuzzle, const_cast<char*>(volatile_data.c_str()));
    return this;
  }

  std::string Kuzzle::volatiles() const noexcept {
    char *volatiles = kuzzle_get_volatile(_kuzzle);
    std::string volatilestr = volatiles;

    free(volatiles);

    return volatilestr;
  }

  std::string Kuzzle::jwt() const noexcept {
    char *jwt = kuzzle_get_jwt(_kuzzle);
    std::string jwtstr = jwt;

    free(jwt);

    return jwtstr;
  }

  Kuzzle *Kuzzle::jwt(const std::string &jwt) noexcept {
    kuzzle_set_jwt(_kuzzle, const_cast<char*>(jwt.c_str()));
    return this;
  }

  Protocol* Kuzzle::getProtocol() const noexcept {
    return static_cast<Protocol*>(this->_protocol->instance);
  }

  bool Kuzzle::autoQueue() const noexcept {
    return kuzzle_get_auto_queue(_kuzzle);
  }

  bool Kuzzle::autoReconnect() const noexcept {
    return kuzzle_get_auto_reconnect(_kuzzle);
  }

  bool Kuzzle::autoResubscribe() const noexcept {
    return kuzzle_get_auto_resubscribe(_kuzzle);
  }

  bool Kuzzle::autoReplay() const noexcept {
    return kuzzle_get_auto_replay(_kuzzle);
  }

  int Kuzzle::queueMaxSize() const noexcept {
    return kuzzle_get_queue_max_size(_kuzzle);
  }

  int Kuzzle::queueTTL() const noexcept {
    return kuzzle_get_queue_ttl(_kuzzle);
  }

  int Kuzzle::replayInterval() const noexcept {
    return kuzzle_get_replay_interval(_kuzzle);
  }

  int Kuzzle::reconnectionDelay() const noexcept {
    return kuzzle_get_reconnection_delay(_kuzzle);
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

  KuzzleEventEmitter* Kuzzle::once(
      Event event,
      SharedEventListener listener) noexcept {
    kuzzle_once(_kuzzle, event, &_c_emit_event, this);
    return KuzzleEventEmitter::once(event, listener);
  }
}
