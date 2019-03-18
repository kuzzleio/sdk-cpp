#include "kuzzle.hpp"
#include "internal/kuzzle_request.hpp"

namespace kuzzleio {

    KuzzleRequest::KuzzleRequest() {
        _kr = new kuzzle_request();
        _kr->from = 0;
        _kr->size = 0;
        _kr->expires_in = 0;
        _kr->start = 0;
        _kr->stop = 0;
        _kr->end = 0;
        _kr->bit = 0;
        _kr->lon = 0;
        _kr->lat = 0;
        _kr->distance = 0;
        _kr->cursor = 0;
        _kr->offset = 0;
        _kr->idx = 0;
        _kr->count = 0;
        _kr->reset = false;
        _kr->include_trash = false;
    }

    KuzzleRequest::KuzzleRequest(const kuzzle_request* src) {
        _kr = new kuzzle_request();
        _kr->request_id = strdup(src->request_id);
        _kr->controller = strdup(src->controller);
        _kr->action = strdup(src->action);
        _kr->index = strdup(src->index);
        _kr->collection = strdup(src->collection);
        _kr->body = strdup(src->body);
        _kr->id = strdup(src->id);
        _kr->from = src->from;
        _kr->size = src->size;
        _kr->scroll = strdup(src->scroll);
        _kr->scroll_id = strdup(src->scroll_id);
        _kr->strategy = strdup(src->strategy);
        _kr->expires_in = src->expires_in;
        _kr->volatiles = strdup(src->volatiles);
        _kr->scope = strdup(src->scope);
        _kr->state = strdup(src->state);
        _kr->users = strdup(src->users);
        _kr->start = src->start;
        _kr->stop = src->stop;
        _kr->end = src->end;
        _kr->bit = src->bit;
        _kr->member = strdup(src->member);
        _kr->member1 = strdup(src->member1);
        _kr->member2 = strdup(src->member2);
        _kr->members = NULL;
        _members = std::vector<std::string>(src->members, src->members + src->members_length);
        _kr->members_length = src->members_length;
        _kr->lon = src->lon;
        _kr->lat = src->lat;
        _kr->distance = src->distance;
        _kr->unit = strdup(src->unit);
        _kr->options = NULL;
        _options = std::vector<std::string>(src->options, src->options + src->options_length);
        _kr->options_length = src->options_length;
        _kr->keys = NULL;
        _keys = std::vector<std::string>(src->keys, src->keys + src->keys_length);
        _kr->keys_length = src->keys_length;
        _kr->cursor = src->cursor;
        _kr->offset = src->offset;
        _kr->field = strdup(src->field);
        _kr->fields = NULL;
        _fields = std::vector<std::string>(src->fields, src->fields + src->fields_length);
        _kr->fields_length = src->fields_length;
        _kr->subcommand = strdup(src->subcommand);
        _kr->pattern = strdup(src->pattern);
        _kr->idx = src->idx;
        _kr->min = strdup(src->min);
        _kr->max = strdup(src->max);
        _kr->limit = strdup(src->limit);
        _kr->count = src->count;
        _kr->match = strdup(src->match);
        _kr->reset = src->reset;
        _kr->include_trash = src->include_trash;
    }

    char* KuzzleRequest::strdup(const char* s) {
        if (s == NULL)
            return NULL;
        size_t len = 0;
        for (; s[len]; len++);
        char *dest = new char[len + 1];
        strcpy(dest, s);
        return dest;
    }

    const char* KuzzleRequest::requestId() const {
            return _kr->request_id;
    }

    void KuzzleRequest::requestId(const char* requestId) {
            KuzzleRequest::_kr->request_id = strdup(requestId);
    }

    const char* KuzzleRequest::controller() const {
            return _kr->controller;
    }

    void KuzzleRequest::controller(const char* controller) {
            KuzzleRequest::_kr->controller = strdup(controller);
    }

    const char* KuzzleRequest::action() const {
            return _kr->action;
    }

    void KuzzleRequest::action(const char* action) {
            KuzzleRequest::_kr->action = strdup(action);
    }

    const char* KuzzleRequest::index() const {
            return _kr->index;
    }

    void KuzzleRequest::index(const char* index) {
            KuzzleRequest::_kr->index = strdup(index);
    }

    const char* KuzzleRequest::collection() const {
            return _kr->collection;
    }

    void KuzzleRequest::collection(const char* collection) {
            KuzzleRequest::_kr->collection = strdup(collection);
    }

    const char* KuzzleRequest::body() const {
            return _kr->body;
    }

    void KuzzleRequest::body(const char* body) {
            KuzzleRequest::_kr->body = strdup(body);
    }

    const char* KuzzleRequest::id() const {
            return _kr->id;
    }

    void KuzzleRequest::id(const char* id) {
            KuzzleRequest::_kr->id = strdup(id);
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
            KuzzleRequest::_kr->scroll = strdup(scroll);
    }

    const char* KuzzleRequest::scrollId() const {
            return _kr->scroll_id;
    }

    void KuzzleRequest::scrollId(const char* scrollId) {
            KuzzleRequest::_kr->scroll_id = strdup(scrollId);
    }

    const char* KuzzleRequest::strategy() const {
            return _kr->strategy;
    }

    void KuzzleRequest::strategy(const char* strategy) {
            KuzzleRequest::_kr->strategy = strdup(strategy);
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
            KuzzleRequest::_kr->volatiles = strdup(volatiles);
    }

    const char* KuzzleRequest::scope() const {
            return _kr->scope;
    }

    void KuzzleRequest::scope(const char* scope) {
            KuzzleRequest::_kr->scope = strdup(scope);
    }

    const char* KuzzleRequest::state() const {
            return _kr->state;
    }

    void KuzzleRequest::state(const char* state) {
            KuzzleRequest::_kr->state = strdup(state);
    }

    const char* KuzzleRequest::users() const {
            return _kr->users;
    }

    void KuzzleRequest::users(const char* users) {
            KuzzleRequest::_kr->users = strdup(users);
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
            KuzzleRequest::_kr->member = strdup(member);
    }

    const char* KuzzleRequest::member1() const {
            return _kr->member1;
    }

    void KuzzleRequest::member1(const char* member1) {
            KuzzleRequest::_kr->member1 = strdup(member1);
    }

    const char* KuzzleRequest::member2() const {
            return _kr->member2;
    }

    void KuzzleRequest::member2(const char* member2) {
            KuzzleRequest::_kr->member2 = strdup(member2);
    }

    const std::vector<std::string> &KuzzleRequest::members() const {
            return _members;
    }

    void KuzzleRequest::members(const std::vector<std::string> &members) {
            KuzzleRequest::_kr->members = vectorToC(members);
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
            KuzzleRequest::_kr->unit = strdup(unit);
    }

    const std::vector<std::string> &KuzzleRequest::options() const {
            return _options;
    }

    void KuzzleRequest::options(const std::vector<std::string> &options) {
            KuzzleRequest::_kr->options = vectorToC(options);
            KuzzleRequest::_options = options;
    }

    const std::vector<std::string> &KuzzleRequest::keys() const {
            return _keys;
    }

    void KuzzleRequest::keys(const std::vector<std::string> &keys) {
            KuzzleRequest::_kr->keys = vectorToC(keys);
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
            KuzzleRequest::_kr->field = strdup(field);
    }

    const std::vector<std::string> &KuzzleRequest::fields() const {
            return _fields;
    }

    void KuzzleRequest::fields(const std::vector<std::string> &fields) {
            KuzzleRequest::_kr->fields = vectorToC(fields);
            KuzzleRequest::_fields = fields;
    }

    const char* KuzzleRequest::subcommand() const {
            return _kr->subcommand;
    }

    void KuzzleRequest::subcommand(const char* subcommand) {
            KuzzleRequest::_kr->subcommand = strdup(subcommand);
    }

    const char* KuzzleRequest::pattern() const {
            return _kr->pattern;
    }

    void KuzzleRequest::pattern(const char* pattern) {
            KuzzleRequest::_kr->pattern = strdup(pattern);
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
            KuzzleRequest::_kr->min = strdup(min);
    }

    const char* KuzzleRequest::max() const {
            return _kr->max;
    }

    void KuzzleRequest::max(const char* max) {
            KuzzleRequest::_kr->max = strdup(max);
    }

    const char* KuzzleRequest::limit() const {
            return _kr->limit;
    }

    void KuzzleRequest::limit(const char* limit) {
            KuzzleRequest::_kr->limit = strdup(limit);
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
            KuzzleRequest::_kr->match = strdup(match);
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

    char* const* KuzzleRequest::vectorToC(const std::vector<std::string> &vec) noexcept {
        if (!vec.size())
            return NULL;
        char** cc = new char*[vec.size()];
        for(unsigned int i = 0; i < vec.size(); ++i)
        {
            cc[i] = new char[vec[i].size() + 1];
            strcpy(cc[i], vec[i].c_str());
        }
        return cc;
    }

    kuzzle_request *KuzzleRequest::toC() {

        kuzzle_request *req = new kuzzle_request();
        req->controller = strdup(this->_kr->controller);
        req->action = strdup(this->_kr->action);
        req->index = strdup(this->_kr->index);
        req->collection = strdup(this->_kr->collection);
        req->body = strdup(this->_kr->body);
        req->id = strdup(this->_kr->id);
        req->from = this->_kr->from;
        req->size = this->_kr->size;
        req->scroll = strdup(this->_kr->scroll);
        req->scroll_id = strdup(this->_kr->scroll_id);
        req->strategy = strdup(this->_kr->strategy);
        req->expires_in = this->_kr->expires_in;
        req->volatiles = strdup(this->_kr->volatiles);
        req->scope = strdup(this->_kr->scope);
        req->state = strdup(this->_kr->state);
        req->users = strdup(this->_kr->users);
        req->start = this->_kr->start;
        req->stop = this->_kr->stop;
        req->end = this->_kr->end;
        req->bit = this->_kr->bit;
        req->member = strdup(this->_kr->member);
        req->member1 = strdup(this->_kr->member1);
        req->member2 = strdup(this->_kr->member2);
        req->members = vectorToC(this->_members);
        req->members_length = this->_members.size();
        req->lon = this->_kr->lon;
        req->lat = this->_kr->lat;
        req->distance = this->_kr->distance;
        req->unit = strdup(this->_kr->unit);
        req->options_length = this->_options.size();
        req->keys_length = this->_keys.size();
        req->options = vectorToC(this->_options);
        req->keys = vectorToC(this->_keys);
        req->cursor = this->_kr->cursor;
        req->offset = this->_kr->offset;
        req->field = strdup(this->_kr->field);
        req->fields = vectorToC(this->_fields);
        req->fields_length = this->_fields.size();
        req->subcommand = strdup(this->_kr->subcommand);
        req->pattern = strdup(this->_kr->pattern);
        req->idx = this->_kr->idx;
        req->min = strdup(this->_kr->min);
        req->max = strdup(this->_kr->max);
        req->limit = strdup(this->_kr->limit);
        req->count = this->_kr->count;
        req->match = strdup(this->_kr->match);
        req->reset = this->_kr->reset;
        req->include_trash = this->_kr->include_trash;

        if (_kr != nullptr)
            kuzzle_free_kuzzle_request(_kr);
        _kr = req;
        return req;
    }
}