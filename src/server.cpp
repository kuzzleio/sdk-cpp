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
#include "internal/server.hpp"

namespace kuzzleio
{
Server::Server(kuzzle *kuzzle)
{
  _server = kuzzle_get_server_controller(kuzzle);
  kuzzle_new_server(_server, kuzzle);
}

Server::~Server()
{
  unregisterServer(_server);

  // do not use "delete":
  // _server is allocated in the cgo world, using calloc
  free(_server);
}

bool Server::adminExists()
{
  return this->adminExists(query_options());
}

bool Server::adminExists(const query_options &options)
{
  KUZZLE_API(bool_result, r, kuzzle_admin_exists(_server, const_cast<query_options *>(&options)))

  bool ret = r->result;
  kuzzle_free_bool_result(r);

  return ret;
}

std::string Server::allStats()
{
  return this->allStats(query_options());
}

std::string Server::allStats(const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_get_all_stats(_server, const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

std::string Server::stats(time_t start, time_t end)
{
  return this->stats(start, end, query_options());
}

std::string Server::stats(time_t start, time_t end, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_get_stats(_server, start, end, const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

std::string Server::lastStats()
{
  return this->lastStats(query_options());
}

std::string Server::lastStats(const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_get_last_stats(_server, const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

std::string Server::config()
{
  return this->config(query_options());
}

std::string Server::config(const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_get_config(_server, const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

std::string Server::info()
{
  return this->info(query_options());
}

std::string Server::info(const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_info(_server, const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

long long Server::now()
{
  return this->now(query_options());
}

// java wrapper for this method is in typemap.i
long long Server::now(const query_options &options)
{
  KUZZLE_API(date_result, r, kuzzle_now(_server, const_cast<query_options *>(&options)))

  long long ret = r->result;
  kuzzle_free_date_result(r);

  return ret;
}
} // namespace kuzzleio
