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

#include "kuzzle.hpp"
#include "internal/collection.hpp"

namespace kuzzleio
{
Collection::Collection(kuzzle *kuzzle)
{
  _collection = kuzzle_get_collection_controller(kuzzle);
  kuzzle_new_collection(_collection, kuzzle);
}

Collection::~Collection()
{
  unregisterCollection(_collection);

  // do not use "delete":
  // _collection is allocated in the cgo world, using calloc
  free(_collection);
}

void Collection::create(const std::string &index, const std::string &collection)
{
  this->create(index, collection, "{}", query_options());
}

void Collection::create(const std::string &index, const std::string &collection, const std::string &mapping)
{
  this->create(index, collection, mapping, query_options());
}

void Collection::create(const std::string &index, const std::string &collection, const query_options &options)
{
  this->create(index, collection, "{}", options);
}

void Collection::create(const std::string &index, const std::string &collection, const std::string &mapping, const query_options &options)
{
  KUZZLE_API(error_result, r, kuzzle_collection_create(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<char *>(mapping.c_str()), const_cast<query_options *>(&options)))

  kuzzle_free_error_result(r);
}

bool Collection::exists(const std::string &index, const std::string &collection)
{
  return this->exists(index, collection, query_options());
}

bool Collection::exists(const std::string &index, const std::string &collection, const query_options &options)
{
  KUZZLE_API(bool_result, r, kuzzle_collection_exists(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<query_options *>(&options)))

  bool ret = r->result;
  kuzzle_free_bool_result(r);

  return ret;
}

std::string Collection::list(const std::string &index)
{
  return this->list(index, query_options());
}

std::string Collection::list(const std::string &index, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_collection_list(_collection, const_cast<char *>(index.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

void Collection::truncate(const std::string &index, const std::string &collection)
{
  this->truncate(index, collection, query_options());
}

void Collection::truncate(const std::string &index, const std::string &collection, const query_options &options)
{
  KUZZLE_API(error_result, r, kuzzle_collection_truncate(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<query_options *>(&options)))

  kuzzle_free_error_result(r);
}

std::string Collection::mapping(const std::string &index, const std::string &collection)
{
  return this->mapping(index, collection, query_options());
}

std::string Collection::mapping(const std::string &index, const std::string &collection, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_collection_get_mapping(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

void Collection::updateMapping(const std::string &index, const std::string &collection, const std::string &mapping)
{
  this->updateMapping(index, collection, mapping, query_options());
}

void Collection::updateMapping(const std::string &index, const std::string &collection, const std::string &mapping, const query_options &options)
{
  KUZZLE_API(error_result, r, kuzzle_collection_update_mapping(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<char *>(mapping.c_str()), const_cast<query_options *>(&options)))

  kuzzle_free_error_result(r);
}

std::string Collection::specifications(const std::string &index, const std::string &collection)
{
  return this->specifications(index, collection, query_options());
}

std::string Collection::specifications(const std::string &index, const std::string &collection, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_collection_get_specifications(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

SearchResult *Collection::searchSpecifications(const std::string &query)
{
  return this->searchSpecifications(query, query_options());
}

SearchResult *Collection::searchSpecifications(const std::string &query, const query_options &options)
{
  KUZZLE_API(search_result, r, kuzzle_collection_search_specifications(_collection, const_cast<char *>(query.c_str()), const_cast<query_options *>(&options)))

  return new SearchResult(r);
}

std::string Collection::updateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications)
{
  return this->updateSpecifications(index, collection, specifications, query_options());
}

std::string Collection::updateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications, const query_options &options)
{
  KUZZLE_API(string_result, r, kuzzle_collection_update_specifications(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<char *>(specifications.c_str()), const_cast<query_options *>(&options)))

  std::string ret = r->result;
  kuzzle_free_string_result(r);

  return ret;
}

validation_response *Collection::validateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications)
{
  return this->validateSpecifications(index, collection, specifications, query_options());
}

validation_response *Collection::validateSpecifications(const std::string &index, const std::string &collection, const std::string &specifications, const query_options &options)
{
  KUZZLE_API(validation_response, r, kuzzle_collection_validate_specifications(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<char *>(specifications.c_str()), const_cast<query_options *>(&options)))

  return r;
}

void Collection::deleteSpecifications(const std::string &index, const std::string &collection)
{
  this->deleteSpecifications(index, collection, query_options());
}

void Collection::deleteSpecifications(const std::string &index, const std::string &collection, const query_options &options)
{
  KUZZLE_API(error_result, r, kuzzle_collection_delete_specifications(_collection, const_cast<char *>(index.c_str()), const_cast<char *>(collection.c_str()), const_cast<query_options *>(&options)))

  kuzzle_free_error_result(r);
}
} // namespace kuzzleio
