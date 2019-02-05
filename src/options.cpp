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

#include "kuzzle.hpp"
#include "internal/options.hpp"
#include <cstdlib>

namespace kuzzleio {
  Options::Options() {
    // CGo functions use ?alloc/free => do not use C++ new/delete
    this->c_options = static_cast<options*>(malloc(sizeof(options)));
    kuzzle_set_default_options(this->c_options);
  }

  Options::~Options() {
    kuzzle_free_options(this->c_options);
  }

  options* Options::c_opts() const noexcept {
    return this->c_options;
  }

  unsigned int Options::port() const noexcept {
    return this->c_options->port;
  }

  unsigned int Options::queueTTL() const noexcept {
    return this->c_options->queue_ttl;
  }

  unsigned long Options::queueMaxSize() const noexcept {
    return this->c_options->queue_max_size;
  }

  bool Options::autoQueue() const noexcept {
    return this->c_options->auto_queue;
  }

  bool Options::autoReconnect() const noexcept {
    return this->c_options->auto_reconnect;
  }

  bool Options::autoReplay() const noexcept {
    return this->c_options->auto_replay;
  }

  bool Options::autoResubscribe() const noexcept {
    return this->c_options->auto_resubscribe;
  }

  unsigned long Options::reconnectionDelay() const noexcept {
    return this->c_options->reconnection_delay;
  }

  unsigned long Options::replayInterval() const noexcept {
    return this->c_options->replay_interval;
  }

  void Options::autoQueue(bool value) noexcept {
    this->c_options->auto_queue = value;
  }

  void Options::autoReconnect(bool value) noexcept {
    this->c_options->auto_reconnect = value;
  }

  void Options::autoReplay(bool value) noexcept {
    this->c_options->auto_replay = value;
  }

  void Options::autoResubscribe(bool value) noexcept {
    this->c_options->auto_resubscribe = value;
  }

  void Options::port(unsigned int value) noexcept {
    this->c_options->port = value;
  }

  void Options::queueMaxSize(unsigned long value) noexcept {
    this->c_options->queue_max_size = value;
  }

  void Options::queueTTL(unsigned int value) noexcept {
    this->c_options->queue_ttl = value;
  }

  void Options::reconnectionDelay(unsigned long value) noexcept {
    this->c_options->reconnection_delay = value;
  }

  void Options::replayInterval(unsigned long value) noexcept {
    this->c_options->replay_interval = value;
  }
}
