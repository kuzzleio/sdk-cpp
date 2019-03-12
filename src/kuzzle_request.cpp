#include "kuzzle.hpp"
#include "internal/kuzzle_request.hpp"

namespace kuzzleio {
    const std::string &KuzzleRequest::requestId() const {
            return _requestId;
    }

    void KuzzleRequest::requestId(const std::string &requestId) {
            KuzzleRequest::_requestId = requestId;
    }

    const std::string &KuzzleRequest::controller() const {
            return _controller;
    }

    void KuzzleRequest::controller(const std::string &controller) {
            KuzzleRequest::_controller = controller;
    }

    const std::string &KuzzleRequest::action() const {
            return _action;
    }

    void KuzzleRequest::action(const std::string &action) {
            KuzzleRequest::_action = action;
    }

    const std::string &KuzzleRequest::index() const {
            return _index;
    }

    void KuzzleRequest::index(const std::string &index) {
            KuzzleRequest::_index = index;
    }

    const std::string &KuzzleRequest::collection() const {
            return _collection;
    }

    void KuzzleRequest::collection(const std::string &collection) {
            KuzzleRequest::_collection = collection;
    }

    const std::string &KuzzleRequest::body() const {
            return _body;
    }

    void KuzzleRequest::body(const std::string &body) {
            KuzzleRequest::_body = body;
    }

    const std::string &KuzzleRequest::id() const {
            return _id;
    }

    void KuzzleRequest::id(const std::string &id) {
            KuzzleRequest::_id = id;
    }

    long KuzzleRequest::from() const {
            return _from;
    }

    void KuzzleRequest::from(long from) {
            KuzzleRequest::_from = from;
    }

    long KuzzleRequest::size() const {
            return _size;
    }

    void KuzzleRequest::size(long size) {
            KuzzleRequest::_size = size;
    }

    const std::string &KuzzleRequest::scroll() const {
            return _scroll;
    }

    void KuzzleRequest::scroll(const std::string &scroll) {
            KuzzleRequest::_scroll = scroll;
    }

    const std::string &KuzzleRequest::scrollId() const {
            return _scrollId;
    }

    void KuzzleRequest::scrollId(const std::string &scrollId) {
            KuzzleRequest::_scrollId = scrollId;
    }

    const std::string &KuzzleRequest::strategy() const {
            return _strategy;
    }

    void KuzzleRequest::strategy(const std::string &strategy) {
            KuzzleRequest::_strategy = strategy;
    }

    unsigned long long int KuzzleRequest::expiresIn() const {
            return _expiresIn;
    }

    void KuzzleRequest::expiresIn(unsigned long long int expiresIn) {
            KuzzleRequest::_expiresIn = expiresIn;
    }

    const std::string &KuzzleRequest::volatiles() const {
            return _volatiles;
    }

    void KuzzleRequest::volatiles(const std::string &volatiles) {
            KuzzleRequest::_volatiles = volatiles;
    }

    const std::string &KuzzleRequest::scope() const {
            return _scope;
    }

    void KuzzleRequest::scope(const std::string &scope) {
            KuzzleRequest::_scope = scope;
    }

    const std::string &KuzzleRequest::state() const {
            return _state;
    }

    void KuzzleRequest::state(const std::string &state) {
            KuzzleRequest::_state = state;
    }

    const std::string &KuzzleRequest::users() const {
            return _users;
    }

    void KuzzleRequest::users(const std::string &users) {
            KuzzleRequest::_users = users;
    }

    long KuzzleRequest::start() const {
            return _start;
    }

    void KuzzleRequest::start(long start) {
            KuzzleRequest::_start = start;
    }

    long KuzzleRequest::stop() const {
            return _stop;
    }

    void KuzzleRequest::stop(long stop) {
            KuzzleRequest::_stop = stop;
    }

    long KuzzleRequest::end() const {
            return _end;
    }

    void KuzzleRequest::end(long end) {
            KuzzleRequest::_end = end;
    }

    unsigned char KuzzleRequest::bit() const {
            return _bit;
    }

    void KuzzleRequest::bit(unsigned char bit) {
            KuzzleRequest::_bit = bit;
    }

    const std::string &KuzzleRequest::member() const {
            return _member;
    }

    void KuzzleRequest::member(const std::string &member) {
            KuzzleRequest::_member = member;
    }

    const std::string &KuzzleRequest::member1() const {
            return _member1;
    }

    void KuzzleRequest::member1(const std::string &member1) {
            KuzzleRequest::_member1 = member1;
    }

    const std::string &KuzzleRequest::member2() const {
            return _member2;
    }

    void KuzzleRequest::member2(const std::string &member2) {
            KuzzleRequest::_member2 = member2;
    }

    const std::vector<std::string> &KuzzleRequest::members() const {
            return _members;
    }

    void KuzzleRequest::members(const std::vector<std::string> &members) {
            KuzzleRequest::_members = members;
    }

    double KuzzleRequest::lon() const {
            return _lon;
    }

    void KuzzleRequest::lon(double lon) {
            KuzzleRequest::_lon = lon;
    }

    double KuzzleRequest::lat() const {
            return _lat;
    }

    void KuzzleRequest::lat(double lat) {
            KuzzleRequest::_lat = lat;
    }

    double KuzzleRequest::distance() const {
            return _distance;
    }

    void KuzzleRequest::distance(double distance) {
            KuzzleRequest::_distance = distance;
    }

    const std::string &KuzzleRequest::unit() const {
            return _unit;
    }

    void KuzzleRequest::unit(const std::string &unit) {
            KuzzleRequest::_unit = unit;
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
            return _cursor;
    }

    void KuzzleRequest::cursor(long cursor) {
            KuzzleRequest::_cursor = cursor;
    }

    long KuzzleRequest::offset() const {
            return _offset;
    }

    void KuzzleRequest::offset(long offset) {
            KuzzleRequest::_offset = offset;
    }

    const std::string &KuzzleRequest::field() const {
            return _field;
    }

    void KuzzleRequest::field(const std::string &field) {
            KuzzleRequest::_field = field;
    }

    const std::vector<std::string> &KuzzleRequest::fields() const {
            return _fields;
    }

    void KuzzleRequest::fields(const std::vector<std::string> &fields) {
            KuzzleRequest::_fields = fields;
    }

    const std::string &KuzzleRequest::subcommand() const {
            return _subcommand;
    }

    void KuzzleRequest::subcommand(const std::string &subcommand) {
            KuzzleRequest::_subcommand = subcommand;
    }

    const std::string &KuzzleRequest::pattern() const {
            return _pattern;
    }

    void KuzzleRequest::pattern(const std::string &pattern) {
            KuzzleRequest::_pattern = pattern;
    }

    long KuzzleRequest::idx() const {
            return _idx;
    }

    void KuzzleRequest::idx(long idx) {
            KuzzleRequest::_idx = idx;
    }

    const std::string &KuzzleRequest::min() const {
            return _min;
    }

    void KuzzleRequest::min(const std::string &min) {
            KuzzleRequest::_min = min;
    }

    const std::string &KuzzleRequest::max() const {
            return _max;
    }

    void KuzzleRequest::max(const std::string &max) {
            KuzzleRequest::_max = max;
    }

    const std::string &KuzzleRequest::limit() const {
            return _limit;
    }

    void KuzzleRequest::limit(const std::string &limit) {
            KuzzleRequest::_limit = limit;
    }

    unsigned long KuzzleRequest::count() const {
            return _count;
    }

    void KuzzleRequest::count(unsigned long count) {
            KuzzleRequest::_count = count;
    }

    const std::string &KuzzleRequest::match() const {
            return _match;
    }

    void KuzzleRequest::match(const std::string &match) {
            KuzzleRequest::_match = match;
    }

    bool KuzzleRequest::reset() const {
            return _reset;
    }

    void KuzzleRequest::reset(bool reset) {
            KuzzleRequest::_reset = reset;
    }

    bool KuzzleRequest::includeTrash() const {
            return _includeTrash;
    }

    void KuzzleRequest::includeTrash(bool includeTrash) {
            KuzzleRequest::_includeTrash = includeTrash;
    }

    kuzzle_request *KuzzleRequest::toC() const {
        kuzzle_request *req = new kuzzle_request();
        req->controller = stringToC(this->_controller);
        req->action = stringToC(this->_action);
        req->index = stringToC(this->_index);
        req->collection = stringToC(this->_collection);
        req->body = stringToC(this->_body);
        req->id = stringToC(this->_id);
        req->from = this->_from;
        req->size = this->_size;
        req->scroll = stringToC(this->_scroll);
        req->scroll_id = stringToC(this->_scrollId);
        req->strategy = stringToC(this->_strategy);
        req->expires_in = this->_expiresIn;
        req->volatiles = stringToC(this->_volatiles);
        req->scope = stringToC(this->_scope);
        req->state = stringToC(this->_state);
        req->users = stringToC(this->_users);
        req->start = this->_start;
        req->stop = this->_stop;
        req->end = this->_end;
        req->bit = this->_bit;
        req->member = stringToC(this->_member);
        req->member1 = stringToC(this->_member1);
        req->member2 = stringToC(this->_member2);
        req->members = vectorToC(this->_members);
        req->lon = this->_lon;
        req->lat = this->_lat;
        req->distance = this->_distance;
        req->unit = stringToC(this->_unit);
        req->options = vectorToC(this->_options);
        req->keys = vectorToC(this->_keys);
        req->cursor = this->_cursor;
        req->offset = this->_offset;
        req->field = stringToC(this->_field);
        req->fields = vectorToC(this->_fields);
        req->subcommand = stringToC(this->_subcommand);
        req->pattern = stringToC(this->_pattern);
        req->idx = this->_idx;
        req->min = stringToC(this->_min);
        req->max = stringToC(this->_max);
        req->limit = stringToC(this->_limit);
        req->count = this->_count;
        req->match = stringToC(this->_match);
        req->reset = this->_reset;
        req->include_trash = this->_includeTrash;

        return req;
    }


}