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

  void Index::create(const std::string& index, query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_index_create(_index, const_cast<char*>(index.c_str()), options))
    kuzzle_free_error_result(r);
  }

  void Index::delete_(const std::string& index, query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_index_delete(_index, const_cast<char*>(index.c_str()), options))
    kuzzle_free_error_result(r);
  }

  std::vector<std::string> Index::mDelete(const std::vector<std::string>& indexes, query_options *options) {
    char **indexesArray = new char *[indexes.size()];
    for (size_t i = 0; i < indexes.size(); i++) {
      indexesArray[i] = const_cast<char*>(indexes[i].c_str());
    }

    KUZZLE_API(
      string_array_result,
      r,
      kuzzle_index_mdelete(_index, indexesArray, indexes.size(), options),
      delete[] indexesArray
    )

    std::vector<std::string> v = std::vector<std::string>(r->result, r->result + r->result_length);
    kuzzle_free_string_array_result(r);
    return v;
  }

  bool Index::exists(const std::string& index, query_options *options) {
    KUZZLE_API(bool_result, r, kuzzle_index_exists(_index, const_cast<char*>(index.c_str()), options))

    bool ret = r->result;
    kuzzle_free_bool_result(r);
    return ret;
  }

  void Index::refresh(const std::string& index, query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_index_refresh(_index, const_cast<char*>(index.c_str()), options))
    kuzzle_free_error_result(r);
  }

  void Index::refreshInternal(query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_index_refresh_internal(_index, options))
    kuzzle_free_error_result(r);
  }

  void Index::setAutoRefresh(const std::string& index, bool autoRefresh, query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_index_set_auto_refresh(_index, const_cast<char*>(index.c_str()), autoRefresh, options))
    kuzzle_free_error_result(r);
  }

  bool Index::getAutoRefresh(const std::string& index, query_options *options) {
    KUZZLE_API(bool_result, r, kuzzle_index_get_auto_refresh(_index, const_cast<char*>(index.c_str()), options))

    bool ret = r->result;
    kuzzle_free_bool_result(r);
    return ret;
  }

  std::vector<std::string> Index::list(query_options *options) {
    KUZZLE_API(string_array_result, r, kuzzle_index_list(_index, options))

    std::vector<std::string> v = std::vector<std::string>(r->result, r->result + r->result_length);
    kuzzle_free_string_array_result(r);
    return v;
  }
}
