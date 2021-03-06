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

#ifndef _SEARCH_RESULT_HPP_
#define _SEARCH_RESULT_HPP_

#include "kuzzle.hpp"
#include <memory>

namespace kuzzleio {
    class SearchResult {
        protected:
            search_result* _sr;

        public:
            char const* aggregations() const;
            char const* hits() const;
            char const* scroll_id() const;
            unsigned total() const;
            unsigned fetched() const;

            SearchResult(search_result* sr);
            virtual ~SearchResult();
            virtual std::shared_ptr<SearchResult> next();
    };
}

#endif
