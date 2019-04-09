// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _COLLECTION_HPP_
#define _COLLECTION_HPP_

#include <iostream>
#include <list>

#include "core.hpp"
#include "exceptions.hpp"
#include "search_result.hpp"

namespace kuzzleio
{
class Kuzzle;
class SpecificationSearchResult;
class SearchResult;

class Collection
{
  private:
    collection *_collection;

  public:
    Collection(kuzzle *kuzzle);
    virtual ~Collection();

    void create(const std::string &index, const std::string &collection);
    void create(const std::string &index, const std::string &collection, const std::string &mapping);
    void create(const std::string &index, const std::string &collection, const query_options &options);
    void create(const std::string &index, const std::string &collection, const std::string &mapping, const query_options &options);

    void truncate(const std::string &index, const std::string &collection);
    void truncate(const std::string &index, const std::string &collection, const query_options &options);

    void updateMapping(const std::string &index, const std::string &collection, const std::string &mapping);
    void updateMapping(const std::string &index, const std::string &collection, const std::string &mapping, const query_options &options);

    void deleteSpecifications(const std::string &index, const std::string &collection);
    void deleteSpecifications(const std::string &index, const std::string &collection, const query_options &options);

    bool exists(const std::string &index, const std::string &collection);
    bool exists(const std::string &index, const std::string &collection, const query_options &options);

    std::string list(const std::string &index);
    std::string list(const std::string &index, const query_options &options);

    std::string mapping(const std::string &index, const std::string &collection);
    std::string mapping(const std::string &index, const std::string &collection, const query_options &options);

    std::string specifications(const std::string &index, const std::string &collection);
    std::string specifications(const std::string &index, const std::string &collection, const query_options &options);

    std::string updateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications);
    std::string updateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications, const query_options &options);

    SearchResult *searchSpecifications(const std::string &query);
    SearchResult *searchSpecifications(const std::string &query, const query_options &options);

    validation_response *validateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications);
    validation_response *validateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications, const query_options &options);
};
} // namespace kuzzleio

#endif
