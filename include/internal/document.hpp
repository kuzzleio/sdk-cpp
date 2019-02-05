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

#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_

#include <memory>
#include "exceptions.hpp"
#include "search_result.hpp"
#include "core.hpp"

namespace kuzzleio {

    class Document {
        private:
            document* _document;

        public:
            Document(kuzzle* kuzzle);
            virtual ~Document();

            int count(const std::string& index, const std::string& collection);
            int count(const std::string& index, const std::string& collection, const query_options& options);
            int count(const std::string& index, const std::string& collection, const std::string& query);
            int count(const std::string& index, const std::string& collection, const std::string& query, const query_options& options);

            bool exists(const std::string& index, const std::string& collection, const std::string& id);
            bool exists(const std::string& index, const std::string& collection, const std::string& id, const query_options& options);

            std::string create(const std::string& index, const std::string& collection, const std::string& id, const std::string& document);
            std::string create(const std::string& index, const std::string& collection, const std::string& id, const std::string& document, const query_options& options);

            std::string createOrReplace(const std::string& index, const std::string& collection, const std::string& id, const std::string& document);
            std::string createOrReplace(const std::string& index, const std::string& collection, const std::string& id, const std::string& document, const query_options& options);

            std::string delete_(const std::string& index, const std::string& collection, const std::string& id);
            std::string delete_(const std::string& index, const std::string& collection, const std::string& id, const query_options& options);

            std::vector<std::string> deleteByQuery(const std::string& index, const std::string& collection, const std::string& query);
            std::vector<std::string> deleteByQuery(const std::string& index, const std::string& collection, const std::string& query, const query_options& options);

            std::string get(const std::string& index, const std::string& collection, const std::string& id);
            std::string get(const std::string& index, const std::string& collection, const std::string& id, const query_options& options);

            std::string replace(const std::string& index, const std::string& collection, const std::string& id, const std::string& document);
            std::string replace(const std::string& index, const std::string& collection, const std::string& id, const std::string& document, const query_options& options);

            std::string update(const std::string& index, const std::string& collection, const std::string& id, const std::string& document);
            std::string update(const std::string& index, const std::string& collection, const std::string& id, const std::string& document, const query_options& options);

            bool validate(const std::string& index, const std::string& collection, const std::string& document);
            bool validate(const std::string& index, const std::string& collection, const std::string& document, const query_options& options);

            std::shared_ptr<SearchResult> search(const std::string& index, const std::string& collection, const std::string& query);
            std::shared_ptr<SearchResult> search(const std::string& index, const std::string& collection, const std::string& query, const query_options& options);

            std::string mCreate(const std::string& index, const std::string& collection, const std::string& documents);
            std::string mCreate(const std::string& index, const std::string& collection, const std::string& documents, const query_options& options);

            std::string mCreateOrReplace(const std::string& index, const std::string& collection, const std::string& documents);
            std::string mCreateOrReplace(const std::string& index, const std::string& collection, const std::string& documents, const query_options& options);

            std::vector<std::string> mDelete(const std::string& index, const std::string& collection, const std::vector<std::string>& ids);
            std::vector<std::string> mDelete(const std::string& index, const std::string& collection, const std::vector<std::string>& ids, const query_options& options);

            std::string mGet(const std::string& index, const std::string& collection, const std::vector<std::string>& ids);
            std::string mGet(const std::string& index, const std::string& collection, const std::vector<std::string>& ids, const query_options& options);

            std::string mReplace(const std::string& index, const std::string& collection, const std::string& documents);
            std::string mReplace(const std::string& index, const std::string& collection, const std::string& documents, const query_options& options);

            std::string mUpdate(const std::string& index, const std::string& collection, const std::string& documents);
            std::string mUpdate(const std::string& index, const std::string& collection, const std::string& documents, const query_options& options);
    };
}

#endif
