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

#ifndef _KUZZLE_SERVER_HPP
#define _KUZZLE_SERVER_HPP

#include "exceptions.hpp"
#include "core.hpp"

namespace kuzzleio {
  class Server {
    private:
      server *_server;

    public:
      Server(kuzzle* kuzzle);
      virtual ~Server();

      bool adminExists();
      bool adminExists(const query_options& options);

      std::string getAllStats();
      std::string getAllStats(const query_options& options);

      std::string getStats(time_t start, time_t end);
      std::string getStats(time_t start, time_t end, const query_options& options);

      std::string getLastStats();
      std::string getLastStats(const query_options& options);

      std::string getConfig();
      std::string getConfig(const query_options& options);

      std::string info();
      std::string info(const query_options& options);

      long long now();
      long long now(const query_options& options);
  };
}

#endif
