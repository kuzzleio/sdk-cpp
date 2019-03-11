#include "internal/query_options.hpp"

namespace kuzzleio {
    const query_options *QueryOptions::getQueryOptsC() const {
        return queryOptsC;
    }

    bool QueryOptions::isQueuable() const {
        return queuable;
    }

    bool QueryOptions::isWithdist() const {
        return withdist;
    }

    bool QueryOptions::isWithcoord() const {
        return withcoord;
    }

    long QueryOptions::getFrom() const {
        return from;
    }

    long QueryOptions::getSize() const {
        return size;
    }

    const std::string &QueryOptions::getScroll() const {
        return scroll;
    }

    const std::string &QueryOptions::getScrollId() const {
        return scrollId;
    }

    const std::string &QueryOptions::getRefresh() const {
        return refresh;
    }

    const std::string &QueryOptions::getIfExist() const {
        return ifExist;
    }

    int QueryOptions::getRetryOnConflict() const {
        return retryOnConflict;
    }

    const std::string &QueryOptions::getVolatiles() const {
        return volatiles;
    }

    void QueryOptions::setQueuable(bool queuable) {
        QueryOptions::queuable = queuable;
    }

    void QueryOptions::setWithdist(bool withdist) {
        QueryOptions::withdist = withdist;
    }

    void QueryOptions::setWithcoord(bool withcoord) {
        QueryOptions::withcoord = withcoord;
    }

    void QueryOptions::setFrom(long from) {
        QueryOptions::from = from;
    }

    void QueryOptions::setSize(long size) {
        QueryOptions::size = size;
    }

    void QueryOptions::setScroll(const std::string &scroll) {
        QueryOptions::scroll = scroll;
    }

    void QueryOptions::setScrollId(const std::string &scrollId) {
        QueryOptions::scrollId = scrollId;
    }

    void QueryOptions::setRefresh(const std::string &refresh) {
        QueryOptions::refresh = refresh;
    }

    void QueryOptions::setIfExist(const std::string &ifExist) {
        QueryOptions::ifExist = ifExist;
    }

    void QueryOptions::setRetryOnConflict(int retryOnConflict) {
        QueryOptions::retryOnConflict = retryOnConflict;
    }

    void QueryOptions::setVolatiles(const std::string &volatiles) {
        QueryOptions::volatiles = volatiles;
    }
}