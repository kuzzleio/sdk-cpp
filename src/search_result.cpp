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

#include <cassert>
#include "internal/search_result.hpp"
#include "internal/core.hpp"

namespace kuzzleio {
  SearchResult::SearchResult(search_result* sr) : _sr(sr) {
    assert(_sr != nullptr);
  }

  SearchResult::~SearchResult() {
      kuzzle_free_search_result(_sr);
  }

  char const* SearchResult::aggregations() const {
    return _sr->aggregations;
  }

  char const* SearchResult::hits() const {
    return _sr->hits;
  }

  char const* SearchResult::scroll_id() const {
    return _sr->scroll_id;
  }

  unsigned SearchResult::fetched() const {
    return _sr->fetched;
  }

  unsigned SearchResult::total() const {
    return _sr->total;
  }

  const SearchResult SearchResult::next() {
    search_result *sr = kuzzle_document_search_next(_sr);

    SearchResult srCpp(sr);
    return srCpp;
  }
}
