#include "internal/query_options.hpp"

namespace kuzzleio {
    const query_options *QueryOptions::queryOptsC() const {
        return _queryOptsC;
    }

    bool QueryOptions::queuable() const {
        return _queuable;
    }

    bool QueryOptions::withdist() const {
        return _withdist;
    }

    bool QueryOptions::withcoord() const {
        return _withcoord;
    }

    long QueryOptions::from() const {
        return _from;
    }

    long QueryOptions::size() const {
        return _size;
    }

    const std::string &QueryOptions::scroll() const {
        return _scroll;
    }

    const std::string &QueryOptions::scrollId() const {
        return _scrollId;
    }

    const std::string &QueryOptions::refresh() const {
        return _refresh;
    }

    const std::string &QueryOptions::ifExist() const {
        return _ifExist;
    }

    int QueryOptions::retryOnConflict() const {
        return _retryOnConflict;
    }

    const std::string &QueryOptions::volatiles() const {
        return _volatiles;
    }

    void QueryOptions::queuable(bool queuable) {
        QueryOptions::_queuable = queuable;
    }

    void QueryOptions::withdist(bool withdist) {
        QueryOptions::_withdist = withdist;
    }

    void QueryOptions::withcoord(bool withcoord) {
        QueryOptions::_withcoord = withcoord;
    }

    void QueryOptions::from(long from) {
        QueryOptions::_from = from;
    }

    void QueryOptions::size(long size) {
        QueryOptions::_size = size;
    }

    void QueryOptions::scroll(const std::string &scroll) {
        QueryOptions::_scroll = scroll;
    }

    void QueryOptions::scrollId(const std::string &scrollId) {
        QueryOptions::_scrollId = scrollId;
    }

    void QueryOptions::refresh(const std::string &refresh) {
        QueryOptions::_refresh = refresh;
    }

    void QueryOptions::ifExist(const std::string &ifExist) {
        QueryOptions::_ifExist = ifExist;
    }

    void QueryOptions::retryOnConflict(int retryOnConflict) {
        QueryOptions::_retryOnConflict = retryOnConflict;
    }

    void QueryOptions::volatiles(const std::string &volatiles) {
        QueryOptions::_volatiles = volatiles;
    }
}