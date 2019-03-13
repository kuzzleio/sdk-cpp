#include "internal/query_options.hpp"

namespace kuzzleio {
    query_options *QueryOptions::qo() const {
        return _qo;
    }

    bool QueryOptions::queuable() const {
        return _qo->queuable;
    }

    bool QueryOptions::withdist() const {
        return _qo->withdist;
    }

    bool QueryOptions::withcoord() const {
        return _qo->withcoord;
    }

    long QueryOptions::from() const {
        return _qo->from;
    }

    long QueryOptions::size() const {
        return _qo->size;
    }

    const char* QueryOptions::scroll() const {
        return _qo->scroll;
    }

    const char* QueryOptions::scrollId() const {
        return _qo->scroll_id;
    }

    const char* QueryOptions::refresh() const {
        return _qo->refresh;
    }

    const char* QueryOptions::ifExist() const {
        return _qo->if_exist;
    }

    int QueryOptions::retryOnConflict() const {
        return _qo->retry_on_conflict;
    }

    const char* QueryOptions::volatiles() const {
        return _qo->volatiles;
    }

    void QueryOptions::queuable(bool queuable) {
        QueryOptions::_qo->queuable = queuable;
    }

    void QueryOptions::withdist(bool withdist) {
        QueryOptions::_qo->withdist = withdist;
    }

    void QueryOptions::withcoord(bool withcoord) {
        QueryOptions::_qo->withcoord = withcoord;
    }

    void QueryOptions::from(long from) {
        QueryOptions::_qo->from = from;
    }

    void QueryOptions::size(long size) {
        QueryOptions::_qo->size = size;
    }

    void QueryOptions::scroll(const std::string &scroll) {
        QueryOptions::_qo->scroll = stringToC(scroll);
    }

    void QueryOptions::scrollId(const std::string &scrollId) {
        QueryOptions::_qo->scroll_id = stringToC(scrollId);
    }

    void QueryOptions::refresh(const std::string &refresh) {
        QueryOptions::_qo->refresh = stringToC(refresh);
    }

    void QueryOptions::ifExist(const std::string &ifExist) {
        QueryOptions::_qo->if_exist = stringToC(ifExist);
    }

    void QueryOptions::retryOnConflict(int retryOnConflict) {
        QueryOptions::_qo->retry_on_conflict = retryOnConflict;
    }

    void QueryOptions::volatiles(const std::string &volatiles) {
        QueryOptions::_qo->volatiles = stringToC(volatiles);
    }

}