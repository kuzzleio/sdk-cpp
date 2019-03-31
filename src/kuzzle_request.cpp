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
#include "internal/kuzzle_request.hpp"
#include "internal/utils.hpp"

namespace kuzzleio {

    KuzzleRequest::KuzzleRequest() {
        _kr = static_cast<kuzzle_request*>(calloc(48, sizeof(kuzzle_request)));
    }

    KuzzleRequest::KuzzleRequest(const kuzzle_request* src) {
        _kr = static_cast<kuzzle_request*>(calloc(48, sizeof(kuzzle_request)));
        _kr->request_id = toC::dupstring(src->request_id);
        _kr->controller = toC::dupstring(src->controller);
        _kr->action = toC::dupstring(src->action);
        _kr->index = toC::dupstring(src->index);
        _kr->collection = toC::dupstring(src->collection);
        _kr->body = toC::dupstring(src->body);
        _kr->id = toC::dupstring(src->id);
        _kr->from = src->from;
        _kr->size = src->size;
        _kr->scroll = toC::dupstring(src->scroll);
        _kr->scroll_id = toC::dupstring(src->scroll_id);
        _kr->strategy = toC::dupstring(src->strategy);
        _kr->expires_in = src->expires_in;
        _kr->volatiles = toC::dupstring(src->volatiles);
        _kr->scope = toC::dupstring(src->scope);
        _kr->state = toC::dupstring(src->state);
        _kr->users = toC::dupstring(src->users);
        _kr->start = src->start;
        _kr->stop = src->stop;
        _kr->end = src->end;
        _kr->bit = src->bit;
        _kr->member = toC::dupstring(src->member);
        _kr->member1 = toC::dupstring(src->member1);
        _kr->member2 = toC::dupstring(src->member2);
        _kr->members = nullptr;
        if (src->members != nullptr)
            _members = std::vector<std::string>(src->members, src->members + src->members_length);
        _kr->members_length = src->members_length;
        _kr->lon = src->lon;
        _kr->lat = src->lat;
        _kr->distance = src->distance;
        _kr->unit = toC::dupstring(src->unit);
        _kr->options = nullptr;
        if (src->options != nullptr)
            _options = std::vector<std::string>(src->options, src->options + src->options_length);
        _kr->options_length = src->options_length;
        _kr->keys = nullptr;
        if (src->keys != nullptr)
            _keys = std::vector<std::string>(src->keys, src->keys + src->keys_length);
        _kr->keys_length = src->keys_length;
        _kr->cursor = src->cursor;
        _kr->offset = src->offset;
        _kr->field = toC::dupstring(src->field);
        _kr->fields = nullptr;
        if (src->fields != nullptr)
            _fields = std::vector<std::string>(src->fields, src->fields + src->fields_length);
        _kr->fields_length = src->fields_length;
        _kr->subcommand = toC::dupstring(src->subcommand);
        _kr->pattern = toC::dupstring(src->pattern);
        _kr->idx = src->idx;
        _kr->min = toC::dupstring(src->min);
        _kr->max = toC::dupstring(src->max);
        _kr->limit = toC::dupstring(src->limit);
        _kr->count = src->count;
        _kr->match = toC::dupstring(src->match);
        _kr->reset = src->reset;
        _kr->include_trash = src->include_trash;
    }

    const char* KuzzleRequest::requestId() const {
        return _kr->request_id;
    }

    void KuzzleRequest::requestId(const char* requestId) {
        if (_kr->request_id != nullptr)
            free(const_cast<char*>(_kr->request_id));
        KuzzleRequest::_kr->request_id = toC::dupstring(requestId);
    }

    const char* KuzzleRequest::controller() const {
        return _kr->controller;
    }

    void KuzzleRequest::controller(const char* controller) {
        if (_kr->controller != nullptr)
            free(const_cast<char*>(_kr->controller));
        KuzzleRequest::_kr->controller = toC::dupstring(controller);
    }

    const char* KuzzleRequest::action() const {
        return _kr->action;
    }

    void KuzzleRequest::action(const char* action) {
        if (_kr->action != nullptr)
            free(const_cast<char*>(_kr->action));
        KuzzleRequest::_kr->action = toC::dupstring(action);
    }

    const char* KuzzleRequest::index() const {
        return _kr->index;
    }

    void KuzzleRequest::index(const char* index) {
        if (_kr->index != nullptr)
            free(const_cast<char*>(_kr->index));
        KuzzleRequest::_kr->index = toC::dupstring(index);
    }

    const char* KuzzleRequest::collection() const {
        return _kr->collection;
    }

    void KuzzleRequest::collection(const char* collection) {
        if (_kr->collection != nullptr)
            free(const_cast<char*>(_kr->collection));
        KuzzleRequest::_kr->collection = toC::dupstring(collection);
    }

    const char* KuzzleRequest::body() const {
        return _kr->body;
    }

    void KuzzleRequest::body(const char* body) {
        if (_kr->body != nullptr)
            free(const_cast<char*>(_kr->body));
        KuzzleRequest::_kr->body = toC::dupstring(body);
    }

    const char* KuzzleRequest::id() const {
        return _kr->id;
    }

    void KuzzleRequest::id(const char* id) {
        if (_kr->id != nullptr)
            free(const_cast<char*>(_kr->id));
        KuzzleRequest::_kr->id = toC::dupstring(id);
    }

    long KuzzleRequest::from() const {
        return _kr->from;
    }

    void KuzzleRequest::from(long from) {
        KuzzleRequest::_kr->from = from;
    }

    long KuzzleRequest::size() const {
        return _kr->size;
    }

    void KuzzleRequest::size(long size) {
        KuzzleRequest::_kr->size = size;
    }

    const char* KuzzleRequest::scroll() const {
        return _kr->scroll;
    }

    void KuzzleRequest::scroll(const char* scroll) {
        if (_kr->scroll != nullptr)
            free(const_cast<char*>(_kr->scroll));
        KuzzleRequest::_kr->scroll = toC::dupstring(scroll);
    }

    const char* KuzzleRequest::scrollId() const {
        return _kr->scroll_id;
    }

    void KuzzleRequest::scrollId(const char* scrollId) {
        if (_kr->scroll_id != nullptr)
            free(const_cast<char*>(_kr->scroll_id));
        KuzzleRequest::_kr->scroll_id = toC::dupstring(scrollId);
    }

    const char* KuzzleRequest::strategy() const {
        return _kr->strategy;
    }

    void KuzzleRequest::strategy(const char* strategy) {
        if (_kr->strategy != nullptr)
            free(const_cast<char*>(_kr->strategy));
        KuzzleRequest::_kr->strategy = toC::dupstring(strategy);
    }

    unsigned long long int KuzzleRequest::expiresIn() const {
        return _kr->expires_in;
    }

    void KuzzleRequest::expiresIn(unsigned long long int expiresIn) {
        KuzzleRequest::_kr->expires_in = expiresIn;
    }

    const char* KuzzleRequest::volatiles() const {
        return _kr->volatiles;
    }

    void KuzzleRequest::volatiles(const char* volatiles) {
        if (_kr->volatiles != nullptr)
            free(const_cast<char*>(_kr->volatiles));
        KuzzleRequest::_kr->volatiles = toC::dupstring(volatiles);
    }

    const char* KuzzleRequest::scope() const {
        return _kr->scope;
    }

    void KuzzleRequest::scope(const char* scope) {
        if (_kr->scope != nullptr)
            free(const_cast<char*>(_kr->scope));
        KuzzleRequest::_kr->scope = toC::dupstring(scope);
    }

    const char* KuzzleRequest::state() const {
        return _kr->state;
    }

    void KuzzleRequest::state(const char* state) {
        if (_kr->state != nullptr)
            free(const_cast<char*>(_kr->state));
        KuzzleRequest::_kr->state = toC::dupstring(state);
    }

    const char* KuzzleRequest::users() const {
        return _kr->users;
    }

    void KuzzleRequest::users(const char* users) {
        if (_kr->users != nullptr)
            free(const_cast<char*>(_kr->users));
        KuzzleRequest::_kr->users = toC::dupstring(users);
    }

    long KuzzleRequest::start() const {
        return _kr->start;
    }

    void KuzzleRequest::start(long start) {
        KuzzleRequest::_kr->start = start;
    }

    long KuzzleRequest::stop() const {
        return _kr->stop;
    }

    void KuzzleRequest::stop(long stop) {
        KuzzleRequest::_kr->stop = stop;
    }

    long KuzzleRequest::end() const {
        return _kr->end;
    }

    void KuzzleRequest::end(long end) {
        KuzzleRequest::_kr->end = end;
    }

    unsigned char KuzzleRequest::bit() const {
        return _kr->bit;
    }

    void KuzzleRequest::bit(unsigned char bit) {
        KuzzleRequest::_kr->bit = bit;
    }

    const char* KuzzleRequest::member() const {
        return _kr->member;
    }

    void KuzzleRequest::member(const char* member) {
        if (_kr->member != nullptr)
            free(const_cast<char*>(_kr->member));
        KuzzleRequest::_kr->member = toC::dupstring(member);
    }

    const char* KuzzleRequest::member1() const {
        return _kr->member1;
    }

    void KuzzleRequest::member1(const char* member1) {
        if (_kr->member1 != nullptr)
            free(const_cast<char*>(_kr->member1));
        KuzzleRequest::_kr->member1 = toC::dupstring(member1);
    }

    const char* KuzzleRequest::member2() const {
        return _kr->member2;
    }

    void KuzzleRequest::member2(const char* member2) {
        if (_kr->member2 != nullptr)
            free(const_cast<char*>(_kr->member2));
        KuzzleRequest::_kr->member2 = toC::dupstring(member2);
    }

    const std::vector<std::string> &KuzzleRequest::members() const {
        return _members;
    }

    void KuzzleRequest::members(const std::vector<std::string> &members) {
        KuzzleRequest::_members = members;
    }

    double KuzzleRequest::lon() const {
        return _kr->lon;
    }

    void KuzzleRequest::lon(double lon) {
        KuzzleRequest::_kr->lon = lon;
    }

    double KuzzleRequest::lat() const {
        return _kr->lat;
    }

    void KuzzleRequest::lat(double lat) {
        KuzzleRequest::_kr->lat = lat;
    }

    double KuzzleRequest::distance() const {
        return _kr->distance;
    }

    void KuzzleRequest::distance(double distance) {
        KuzzleRequest::_kr->distance = distance;
    }

    const char* KuzzleRequest::unit() const {
        return _kr->unit;
    }

    void KuzzleRequest::unit(const char* unit) {
        if (_kr->unit != nullptr)
            free(const_cast<char*>(_kr->unit));
        KuzzleRequest::_kr->unit = toC::dupstring(unit);
    }

    const std::vector<std::string> &KuzzleRequest::options() const {
        return _options;
    }

    void KuzzleRequest::options(const std::vector<std::string> &options) {
        KuzzleRequest::_options = options;
    }

    const std::vector<std::string> &KuzzleRequest::keys() const {
        return _keys;
    }

    void KuzzleRequest::keys(const std::vector<std::string> &keys) {
        KuzzleRequest::_keys = keys;
    }

    long KuzzleRequest::cursor() const {
        return _kr->cursor;
    }

    void KuzzleRequest::cursor(long cursor) {
        KuzzleRequest::_kr->cursor = cursor;
    }

    long KuzzleRequest::offset() const {
        return _kr->offset;
    }

    void KuzzleRequest::offset(long offset) {
        KuzzleRequest::_kr->offset = offset;
    }

    const char* KuzzleRequest::field() const {
        return _kr->field;
    }

    void KuzzleRequest::field(const char* field) {
        if (_kr->field != nullptr)
            free(const_cast<char*>(_kr->field));
        KuzzleRequest::_kr->field = toC::dupstring(field);
    }

    const std::vector<std::string> &KuzzleRequest::fields() const {
        return _fields;
    }

    void KuzzleRequest::fields(const std::vector<std::string> &fields) {
        KuzzleRequest::_fields = fields;
    }

    const char* KuzzleRequest::subcommand() const {
        return _kr->subcommand;
    }

    void KuzzleRequest::subcommand(const char* subcommand) {
        if (_kr->subcommand != nullptr)
            free(const_cast<char*>(_kr->subcommand));
        KuzzleRequest::_kr->subcommand = toC::dupstring(subcommand);
    }

    const char* KuzzleRequest::pattern() const {
        return _kr->pattern;
    }

    void KuzzleRequest::pattern(const char* pattern) {
        if (_kr->pattern != nullptr)
            free(const_cast<char*>(_kr->pattern));
        KuzzleRequest::_kr->pattern = toC::dupstring(pattern);
    }

    long KuzzleRequest::idx() const {
        return _kr->idx;
    }

    void KuzzleRequest::idx(long idx) {
        KuzzleRequest::_kr->idx = idx;
    }

    const char* KuzzleRequest::min() const {
        return _kr->min;
    }

    void KuzzleRequest::min(const char* min) {
        if (_kr->min != nullptr)
            free(const_cast<char*>(_kr->min));
        KuzzleRequest::_kr->min = toC::dupstring(min);
    }

    const char* KuzzleRequest::max() const {
        return _kr->max;
    }

    void KuzzleRequest::max(const char* max) {
        if (_kr->max != nullptr)
            free(const_cast<char*>(_kr->max));
        KuzzleRequest::_kr->max = toC::dupstring(max);
    }

    const char* KuzzleRequest::limit() const {
        return _kr->limit;
    }

    void KuzzleRequest::limit(const char* limit) {
        if (_kr->limit != nullptr)
            free(const_cast<char*>(_kr->limit));
        KuzzleRequest::_kr->limit = toC::dupstring(limit);
    }

    unsigned long KuzzleRequest::count() const {
        return _kr->count;
    }

    void KuzzleRequest::count(unsigned long count) {
        KuzzleRequest::_kr->count = count;
    }

    const char* KuzzleRequest::match() const {
        return _kr->match;
    }

    void KuzzleRequest::match(const char* match) {
        if (_kr->match != nullptr)
            free(const_cast<char*>(_kr->match));
        KuzzleRequest::_kr->match = toC::dupstring(match);
    }

    bool KuzzleRequest::reset() const {
        return _kr->reset;
    }

    void KuzzleRequest::reset(bool reset) {
        KuzzleRequest::_kr->reset = reset;
    }

    bool KuzzleRequest::includeTrash() const {
        return _kr->include_trash;
    }

    void KuzzleRequest::includeTrash(bool includeTrash) {
        KuzzleRequest::_kr->include_trash = includeTrash;
    }
    

    kuzzle_request *KuzzleRequest::toC() {

        _kr->members = toC::vectorToC(this->_members);
        _kr->options = toC::vectorToC(this->_options);
        _kr->keys = toC::vectorToC(this->_keys);
        _kr->fields = toC::vectorToC(this->_fields);

        return _kr;
    }
}