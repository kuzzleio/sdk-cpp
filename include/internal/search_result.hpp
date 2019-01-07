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

namespace kuzzleio {

    class SearchResult {
        protected:
            const search_result* _sr;
            const std::string _aggregations;
            const std::string _hits;
            const size_t _total;
            const size_t _fetched;
            const std::string _scroll_id;

        public:
            SearchResult(const search_result* sr);
            virtual ~SearchResult();

            SearchResult* next() const;

            size_t total() const;
            size_t fetched() const;
            const std::string& aggregations() const;
            const std::string& hits() const;
            const std::string& scroll_id() const;
    };

    class SpecificationSearchResult : public SearchResult {
        public:
            SpecificationSearchResult(const search_result* sr);
            virtual ~SpecificationSearchResult();
            SpecificationSearchResult* next() const;
    };

}

#endif
