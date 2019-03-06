#include "kuzzle.hpp"
#include "internal/kuzzle_request.hpp"

namespace kuzzleio {

    const std::string &KuzzleRequest::getRequest_id() const {
        return request_id;
    }

    void KuzzleRequest::setRequest_id(const std::string &request_id) {
        KuzzleRequest::request_id = request_id;
    }

    const std::string &KuzzleRequest::getController() const {
        return controller;
    }

    void KuzzleRequest::setController(const std::string &controller) {
        KuzzleRequest::controller = controller;
    }

    const std::string &KuzzleRequest::getAction() const {
        return action;
    }

    void KuzzleRequest::setAction(const std::string &action) {
        KuzzleRequest::action = action;
    }

    const std::string &KuzzleRequest::getIndex() const {
        return index;
    }

    void KuzzleRequest::setIndex(const std::string &index) {
        KuzzleRequest::index = index;
    }

    const std::string &KuzzleRequest::getCollection() const {
        return collection;
    }

    void KuzzleRequest::setCollection(const std::string &collection) {
        KuzzleRequest::collection = collection;
    }

    const std::string &KuzzleRequest::getBody() const {
        return body;
    }

    void KuzzleRequest::setBody(const std::string &body) {
        KuzzleRequest::body = body;
    }

    const std::string &KuzzleRequest::getId() const {
        return id;
    }

    void KuzzleRequest::setId(const std::string &id) {
        KuzzleRequest::id = id;
    }

    long KuzzleRequest::getFrom() const {
        return from;
    }

    void KuzzleRequest::setFrom(long from) {
        KuzzleRequest::from = from;
    }

    long KuzzleRequest::getSize() const {
        return size;
    }

    void KuzzleRequest::setSize(long size) {
        KuzzleRequest::size = size;
    }

    const std::string &KuzzleRequest::getScroll() const {
        return scroll;
    }

    void KuzzleRequest::setScroll(const std::string &scroll) {
        KuzzleRequest::scroll = scroll;
    }

    const std::string &KuzzleRequest::getScroll_id() const {
        return scroll_id;
    }

    void KuzzleRequest::setScroll_id(const std::string &scroll_id) {
        KuzzleRequest::scroll_id = scroll_id;
    }

    const std::string &KuzzleRequest::getStrategy() const {
        return strategy;
    }

    void KuzzleRequest::setStrategy(const std::string &strategy) {
        KuzzleRequest::strategy = strategy;
    }

    unsigned long long int KuzzleRequest::getExpires_in() const {
        return expires_in;
    }

    void KuzzleRequest::setExpires_in(unsigned long long int expires_in) {
        KuzzleRequest::expires_in = expires_in;
    }

    const std::string &KuzzleRequest::getVolatiles() const {
        return volatiles;
    }

    void KuzzleRequest::setVolatiles(const std::string &volatiles) {
        KuzzleRequest::volatiles = volatiles;
    }

    const std::string &KuzzleRequest::getScope() const {
        return scope;
    }

    void KuzzleRequest::setScope(const std::string &scope) {
        KuzzleRequest::scope = scope;
    }

    const std::string &KuzzleRequest::getState() const {
        return state;
    }

    void KuzzleRequest::setState(const std::string &state) {
        KuzzleRequest::state = state;
    }

    const std::string &KuzzleRequest::getUsers() const {
        return users;
    }

    void KuzzleRequest::setUsers(const std::string &users) {
        KuzzleRequest::users = users;
    }

    long KuzzleRequest::getStart() const {
        return start;
    }

    void KuzzleRequest::setStart(long start) {
        KuzzleRequest::start = start;
    }

    long KuzzleRequest::getStop() const {
        return stop;
    }

    void KuzzleRequest::setStop(long stop) {
        KuzzleRequest::stop = stop;
    }

    long KuzzleRequest::getEnd() const {
        return end;
    }

    void KuzzleRequest::setEnd(long end) {
        KuzzleRequest::end = end;
    }

    unsigned char KuzzleRequest::getBit() const {
        return bit;
    }

    void KuzzleRequest::setBit(unsigned char bit) {
        KuzzleRequest::bit = bit;
    }

    const std::string &KuzzleRequest::getMember() const {
        return member;
    }

    void KuzzleRequest::setMember(const std::string &member) {
        KuzzleRequest::member = member;
    }

    const std::string &KuzzleRequest::getMember1() const {
        return member1;
    }

    void KuzzleRequest::setMember1(const std::string &member1) {
        KuzzleRequest::member1 = member1;
    }

    const std::string &KuzzleRequest::getMember2() const {
        return member2;
    }

    void KuzzleRequest::setMember2(const std::string &member2) {
        KuzzleRequest::member2 = member2;
    }

    const std::vector<std::string> &KuzzleRequest::getMembers() const {
        return members;
    }

    void KuzzleRequest::setMembers(const std::vector<std::string> &members) {
        KuzzleRequest::members = members;
    }

    double KuzzleRequest::getLon() const {
        return lon;
    }

    void KuzzleRequest::setLon(double lon) {
        KuzzleRequest::lon = lon;
    }

    double KuzzleRequest::getLat() const {
        return lat;
    }

    void KuzzleRequest::setLat(double lat) {
        KuzzleRequest::lat = lat;
    }

    double KuzzleRequest::getDistance() const {
        return distance;
    }

    void KuzzleRequest::setDistance(double distance) {
        KuzzleRequest::distance = distance;
    }

    const std::string &KuzzleRequest::getUnit() const {
        return unit;
    }

    void KuzzleRequest::setUnit(const std::string &unit) {
        KuzzleRequest::unit = unit;
    }

    const std::vector<std::string> &KuzzleRequest::getOptions() const {
        return options;
    }

    void KuzzleRequest::setOptions(const std::vector<std::string> &options) {
        KuzzleRequest::options = options;
    }

    const std::vector<std::string> &KuzzleRequest::getKeys() const {
        return keys;
    }

    void KuzzleRequest::setKeys(const std::vector<std::string> &keys) {
        KuzzleRequest::keys = keys;
    }

    long KuzzleRequest::getCursor() const {
        return cursor;
    }

    void KuzzleRequest::setCursor(long cursor) {
        KuzzleRequest::cursor = cursor;
    }

    long KuzzleRequest::getOffset() const {
        return offset;
    }

    void KuzzleRequest::setOffset(long offset) {
        KuzzleRequest::offset = offset;
    }

    const std::string &KuzzleRequest::getField() const {
        return field;
    }

    void KuzzleRequest::setField(const std::string &field) {
        KuzzleRequest::field = field;
    }

    const std::vector<std::string> &KuzzleRequest::getFields() const {
        return fields;
    }

    void KuzzleRequest::setFields(const std::vector<std::string> &fields) {
        KuzzleRequest::fields = fields;
    }

    const std::string &KuzzleRequest::getSubcommand() const {
        return subcommand;
    }

    void KuzzleRequest::setSubcommand(const std::string &subcommand) {
        KuzzleRequest::subcommand = subcommand;
    }

    const std::string &KuzzleRequest::getPattern() const {
        return pattern;
    }

    void KuzzleRequest::setPattern(const std::string &pattern) {
        KuzzleRequest::pattern = pattern;
    }

    long KuzzleRequest::getIdx() const {
        return idx;
    }

    void KuzzleRequest::setIdx(long idx) {
        KuzzleRequest::idx = idx;
    }

    const std::string &KuzzleRequest::getMin() const {
        return min;
    }

    void KuzzleRequest::setMin(const std::string &min) {
        KuzzleRequest::min = min;
    }

    const std::string &KuzzleRequest::getMax() const {
        return max;
    }

    void KuzzleRequest::setMax(const std::string &max) {
        KuzzleRequest::max = max;
    }

    const std::string &KuzzleRequest::getLimit() const {
        return limit;
    }

    void KuzzleRequest::setLimit(const std::string &limit) {
        KuzzleRequest::limit = limit;
    }

    unsigned long KuzzleRequest::getCount() const {
        return count;
    }

    void KuzzleRequest::setCount(unsigned long count) {
        KuzzleRequest::count = count;
    }

    const std::string &KuzzleRequest::getMatch() const {
        return match;
    }

    void KuzzleRequest::setMatch(const std::string &match) {
        KuzzleRequest::match = match;
    }

    bool KuzzleRequest::isReset() const {
        return reset;
    }

    void KuzzleRequest::setReset(bool reset) {
        KuzzleRequest::reset = reset;
    }

    bool KuzzleRequest::isInclude_trash() const {
        return include_trash;
    }

    void KuzzleRequest::setInclude_trash(bool include_trash) {
        KuzzleRequest::include_trash = include_trash;
    }

    kuzzle_request *KuzzleRequest::toC() const {
        kuzzle_request *req = new kuzzle_request();
        req->controller = this->controller.c_str();
        req->action = this->action.c_str();
        req->index = this->index.c_str();
        req->collection = this->collection.c_str();
        req->body = this->body.c_str();
        req->id = this->id.c_str();
        req->from = this->from;
        req->size = this->size;
        req->scroll = this->scroll.c_str();
        req->scroll_id = this->scroll_id.c_str();
        req->strategy = this->strategy.c_str();
        req->expires_in = this->expires_in;
        req->volatiles = this->volatiles.c_str();
        req->scope = this->scope.c_str();
        req->state = this->state.c_str();
        req->users = this->users.c_str();
        req->start = this->start;
        req->stop = this->stop;
        req->end = this->end;
        req->bit = this->bit;
        req->member = this->member.c_str();
        req->member1 = this->member1.c_str();
        req->member2 = this->member2.c_str();
        req->members = vector_to_c(this->members);
        req->lon = this->lon;
        req->lat = this->lat;
        req->distance = this->distance;
        req->unit = this->unit.c_str();
        req->options = vector_to_c(this->options);
        req->keys = vector_to_c(this->keys);
        req->cursor = this->cursor;
        req->offset = this->offset;
        req->field = this->field.c_str();
        req->fields = vector_to_c(this->fields);
        req->subcommand = this->subcommand.c_str();
        req->pattern = this->pattern.c_str();
        req->idx = this->idx;
        req->min = this->min.c_str();
        req->max = this->max.c_str();
        req->limit = this->limit.c_str();
        req->count = this->count;
        req->match = this->match.c_str();
        req->reset = this->reset;
        req->include_trash = this->include_trash;

        return req;
    }
}