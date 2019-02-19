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
#include "internal/exceptions.hpp"
#include <cstdlib>
#include <cstring>

#define DEFAULT_HEADER_CAPACITY 5

namespace kuzzleio {
  Options::Options() {
    // CGo functions use ?alloc/free => do not use C++ new/delete
    c_options = static_cast<options*>(malloc(sizeof(options)));
    kuzzle_set_default_options(c_options);

    header_capacity = 0;
  }

  Options::~Options() {
    // before freeing the C struct, we have to handle a special case about
    // headers: if there is a length of 0, but a capacity > 0
    // This means that headers have been cleared but, for efficiency reasons,
    // we did not deallocate the header containers themselves.
    // To prevent a memleak, we have to do it here
    if (c_options->header_length == 0 && header_capacity > 0) {
      free(c_options->header_names);
      c_options->header_names = nullptr;

      free(c_options->header_values);
      c_options->header_values = nullptr;
    }

    kuzzle_free_options(c_options);
  }

  options* Options::c_opts() const noexcept {
    return c_options;
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
    for(size_t i = 0; i < c_options->header_length; i++) {
      free(c_options->header_names[i]);
      free(c_options->header_values[i]);
    }
    c_options->header_length = 0;
  }

  void Options::delHeader(const std::string & name) noexcept {
    int index = -1;

    for (size_t i = 0; i < c_options->header_length && index < 0; i++) {
      if (!strcmp(c_options->header_names[i], name.c_str())) {
        index = i;
      }
    }

    if (index >= 0) {
      free(c_options->header_names[index]);
      free(c_options->header_values[index]);

      if (index != (c_options->header_length-1)) {
        memmove(
            c_options->header_names[index],
            c_options->header_names[index+1],
            c_options->header_length - (index+1));
        memmove(
            c_options->header_values[index],
            c_options->header_values[index+1],
            c_options->header_length - (index+1));
      }

      c_options->header_length--;
    }
  }

  void Options::setHeader(const std::string & name,
                          const std::string & value) {
    if (header_capacity == 0) {
      c_options->header_names =
        static_cast<char**>(malloc(DEFAULT_HEADER_CAPACITY * sizeof(char*)));
      c_options->header_names =
        static_cast<char**>(malloc(DEFAULT_HEADER_CAPACITY * sizeof(char*)));
      header_capacity = DEFAULT_HEADER_CAPACITY;
    } else if (c_options->header_length == header_capacity) {
      header_capacity *= 2;
      c_options->header_names =
        static_cast<char**>(realloc(c_options->header_names,
                                    header_capacity * sizeof(char*)));
      c_options->header_values =
        static_cast<char**>(realloc(c_options->header_values,
                                    header_capacity * sizeof(char*)));
    }

    if (c_options->header_values == nullptr ||
        c_options->header_names == nullptr) {
      throw InternalException("not enough memory");
    }

    size_t idx = c_options->header_length;
    c_options->header_names[idx] = static_cast<char*>(malloc(1+name.size()));
    strcpy(c_options->header_names[idx], name.c_str());
    c_options->header_values[idx] = static_cast<char*>(malloc(1+value.size()));
    strcpy(c_options->header_values[idx], value.c_str());
    c_options->header_length++;
  }

  bool Options::sslConnection() const noexcept {
    return this->c_options->ssl_connection;
  }

  void Options::sslConnection(bool value) noexcept {
    this->c_options->ssl_connection = value;
  }
}
