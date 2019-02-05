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

#ifndef _KUZZLE_OPTIONS_HPP_
#define _KUZZLE_OPTIONS_HPP_

#include "internal/core.hpp"
#include <string>

namespace kuzzleio {
  class Options {
    private:
      options *c_options;

    public:
      Options();
      virtual ~Options();

      // getters
      options* c_opts() const noexcept;
      bool autoQueue() const noexcept;
      bool autoReconnect() const noexcept;
      bool autoReplay() const noexcept;
      bool autoResubscribe() const noexcept;
      unsigned int port() const noexcept;
      unsigned long queueMaxSize() const noexcept;
      unsigned int queueTTL() const noexcept;
      unsigned long reconnectionDelay() const noexcept;
      unsigned long replayInterval() const noexcept;

      // setters
      void autoQueue(bool value) noexcept;
      void autoReconnect(bool value) noexcept;
      void autoReplay(bool value) noexcept;
      void autoResubscribe(bool value) noexcept;
      void port(unsigned int value) noexcept;
      void queueMaxSize(unsigned long value) noexcept;
      void queueTTL(unsigned int value) noexcept;
      void reconnectionDelay(unsigned long value) noexcept;
      void replayInterval(unsigned long value) noexcept;
  };
}

#endif
