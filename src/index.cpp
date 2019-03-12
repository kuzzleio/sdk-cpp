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
#include "internal/index.hpp"

namespace kuzzleio {
  Index::Index(kuzzle* kuzzle) {
    _index = kuzzle_get_index_controller(kuzzle);
    kuzzle_new_index(_index, kuzzle);
  }

  Index::~Index() {
    unregisterIndex(_index);

    // do not use "delete":
    // _index is allocated in the cgo world, using calloc
    free(_index);
  }

  void Index::create(const std::string& index) {
    this->create(index, QueryOptions());
  }

  void Index::create(const std::string& index, const QueryOptions& options) {
    KUZZLE_API(error_result, r, kuzzle_index_create(
      _index,
      const_cast<char*>(index.c_str()),
      const_cast<query_options*>(options.queryOptsC())))

    kuzzle_free_error_result(r);
  }


  void Index::delete_(const std::string& index) {
    this->delete_(index, QueryOptions());
  }

  void Index::delete_(const std::string& index, const QueryOptions& options) {
    KUZZLE_API(error_result, r, kuzzle_index_delete(
      _index,
      const_cast<char*>(index.c_str()),
      const_cast<query_options*>(options.queryOptsC())))

    kuzzle_free_error_result(r);
  }


  std::vector<std::string> Index::mDelete(const std::vector<std::string>& indexes) {
    return this->mDelete(indexes, QueryOptions());
  }

  std::vector<std::string> Index::mDelete(const std::vector<std::string>& indexes, const QueryOptions& options) {
    char **indexes_array = new char *[indexes.size()];

    for (size_t i = 0; i < indexes.size(); i++) {
      indexes_array[i] = const_cast<char*>(indexes[i].c_str());
    }

    KUZZLE_API(
      string_array_result,
      r,
      kuzzle_index_mdelete(_index, indexes_array, indexes.size(), const_cast<query_options*>(options.queryOptsC())),
      delete[] indexes_array
    )

    std::vector<std::string> v = std::vector<std::string>(r->result, r->result + r->result_length);
    kuzzle_free_string_array_result(r);

    return v;
  }


  bool Index::exists(const std::string& index) {
    return this->exists(index, QueryOptions());
  }

  bool Index::exists(const std::string& index, const QueryOptions& options) {
    KUZZLE_API(bool_result, r, kuzzle_index_exists(
      _index,
      const_cast<char*>(index.c_str()),
      const_cast<query_options*>(options.queryOptsC())))

    bool ret = r->result;
    kuzzle_free_bool_result(r);

    return ret;
  }


  void Index::refresh(const std::string& index) {
    this->refresh(index, QueryOptions());
  }

  void Index::refresh(const std::string& index, const QueryOptions& options) {
    KUZZLE_API(error_result, r, kuzzle_index_refresh(
      _index,
      const_cast<char*>(index.c_str()),
      const_cast<query_options*>(options.queryOptsC())))

    kuzzle_free_error_result(r);
  }


  void Index::refreshInternal() {
    this->refreshInternal(QueryOptions());
  }

  void Index::refreshInternal(const QueryOptions& options) {
    KUZZLE_API(error_result, r, kuzzle_index_refresh_internal(
      _index,
      const_cast<query_options*>(options.queryOptsC())))

    kuzzle_free_error_result(r);
  }


  void Index::setAutoRefresh(const std::string& index, bool auto_refresh) {
    this->setAutoRefresh(index, auto_refresh, QueryOptions());
  }

  void Index::setAutoRefresh(const std::string& index, bool auto_refresh, const QueryOptions& options) {
    KUZZLE_API(error_result, r, kuzzle_index_set_auto_refresh(
      _index,
      const_cast<char*>(index.c_str()),
      auto_refresh,
      const_cast<query_options*>(options.queryOptsC())))

    kuzzle_free_error_result(r);
  }


  bool Index::getAutoRefresh(const std::string& index) {
    return this->getAutoRefresh(index, QueryOptions());
  }

  bool Index::getAutoRefresh(const std::string& index, const QueryOptions& options) {
    KUZZLE_API(bool_result, r, kuzzle_index_get_auto_refresh(
      _index,
      const_cast<char*>(index.c_str()),
      const_cast<query_options*>(options.queryOptsC())))

    bool ret = r->result;
    kuzzle_free_bool_result(r);

    return ret;
  }


  std::vector<std::string> Index::list() {
    return this->list(QueryOptions());
  }

  std::vector<std::string> Index::list(const QueryOptions& options) {
    KUZZLE_API(string_array_result, r, kuzzle_index_list(
      _index,
      const_cast<query_options*>(options.queryOptsC())))

    std::vector<std::string> v = std::vector<std::string>(r->result, r->result + r->result_length);
    kuzzle_free_string_array_result(r);

    return v;
  }
}
