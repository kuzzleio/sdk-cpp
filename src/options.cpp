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
  void Options::resyncHeaders() {
    if (this->c_options->header_length > 0) {
      for(size_t i = 0; i < this->c_options->header_length; i++) {
        free(this->c_options->header_names[i]);
        free(this->c_options->header_values[i]);
      }

      free(this->c_options->header_names);
      free(this->c_options->header_values);

      this->c_options->header_names = nullptr;
      this->c_options->header_values = nullptr;
    }

    if (this->headers.size() > 0) {
      this->c_options->header_names =
          static_cast<char**>(malloc(this->headers.size() * sizeof(char*)));

      this->c_options->header_values =
          static_cast<char**>(malloc(this->headers.size() * sizeof(char*)));

      size_t count = 0;
      for(auto hdr : this->headers) {
        this->c_options->header_names[count] =
          static_cast<char*>(malloc(1+hdr.first.size()));
        strcpy(this->c_options->header_names[count], hdr.first.c_str());

        this->c_options->header_values[count] =
          static_cast<char*>(malloc(1+hdr.second.size()));
        strcpy(this->c_options->header_values[count], hdr.second.c_str());

        count++;
      }
    }
  }

  Options::Options() {
    // CGo functions use ?alloc/free => do not use C++ new/delete
    this->c_options = static_cast<options*>(malloc(sizeof(options)));
    kuzzle_set_default_options(this->c_options);
    this->headers_changed = false;
  }

  Options::~Options() {
    kuzzle_free_options(this->c_options);
  }

  options* Options::c_opts() noexcept {
    if (this->headers_changed) {
      this->resyncHeaders();
      this->headers_changed = false;
    }

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

  void Options::clearHeaders() noexcept {
    this->headers.clear();
    this->headers_changed = true;
  }

  void Options::delHeader(std::string & name) noexcept {
    if (this->headers.erase(name) > 0) {
      this->headers_changed = true;
    }
  }

  void Options::setHeader(std::string & name, std::string & value) noexcept {
    this->headers[name] = value;
    this->headers_changed = true;
  }
}
