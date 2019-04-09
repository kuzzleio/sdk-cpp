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

#ifndef _KUZZLE_INDEX_HPP
#define _KUZZLE_INDEX_HPP
#include <cstdlib>
#include <vector>
#include "exceptions.hpp"
#include "core.hpp"

namespace kuzzleio
{
class Kuzzle;
class Index
{
private:
  kuzzle_index *_index;

public:
  Index(kuzzle *kuzzle);
  virtual ~Index();

  void create(const std::string &index);
  void create(const std::string &index, const query_options &options);

  void delete_(const std::string &index);
  void delete_(const std::string &index, const query_options &options);

  std::vector<std::string> mDelete(const std::vector<std::string> &indexes);
  std::vector<std::string> mDelete(const std::vector<std::string> &indexes, const query_options &options);

  bool exists(const std::string &index);
  bool exists(const std::string &index, const query_options &options);

  void refresh(const std::string &index);
  void refresh(const std::string &index, const query_options &options);

  void refreshInternal();
  void refreshInternal(const query_options &options);

  void autoRefresh(const std::string &index, bool auto_refresh);
  void autoRefresh(const std::string &index, bool auto_refresh, const query_options &options);

  bool autoRefresh(const std::string &index);
  bool autoRefresh(const std::string &index, const query_options &options);

  std::vector<std::string> list();
  std::vector<std::string> list(const query_options &options);
};
} // namespace kuzzleio

#endif
