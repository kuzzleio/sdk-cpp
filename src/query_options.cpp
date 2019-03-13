#include "internal/query_options.hpp"

namespace kuzzleio {

    QueryOptions::QueryOptions(const QueryOptions &src) {
        _qo = new query_options();
        _qo->queuable = src.queuable();
        _qo->withdist = src.withdist();
        _qo->withcoord = src.withcoord();
        _qo->from = src.from();
        _qo->size = src.size();
        _qo->scroll = new char[strlen(src.scroll()) + 1];
        _qo->scroll = strcpy(const_cast<char*>(_qo->scroll), src.scroll());
        _qo->scroll_id = new char[strlen(src.scrollId()) + 1];
        _qo->scroll_id = strcpy(const_cast<char*>(_qo->scroll_id), src.scrollId());
        _qo->refresh = new char[strlen(src.refresh()) + 1];
        _qo->refresh = strcpy(const_cast<char*>(_qo->refresh), src.refresh());
        _qo->if_exist = new char[strlen(src.ifExist()) + 1];
        _qo->if_exist = strcpy(const_cast<char*>(_qo->if_exist), src.ifExist());
        _qo->volatiles = new char[strlen(src.volatiles()) + 1];
        _qo->volatiles = strcpy(const_cast<char*>(_qo->volatiles), src.volatiles());
        _qo->retry_on_conflict = src.retryOnConflict();
    }

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

    void QueryOptions::scroll(const char* scroll) {
        QueryOptions::_qo->scroll = scroll;
    }

    void QueryOptions::scrollId(const char* scrollId) {
        QueryOptions::_qo->scroll_id = scrollId;
    }

    void QueryOptions::refresh(const char* refresh) {
        QueryOptions::_qo->refresh = refresh;
    }

    void QueryOptions::ifExist(const char* ifExist) {
        QueryOptions::_qo->if_exist = ifExist;
    }

    void QueryOptions::retryOnConflict(int retryOnConflict) {
        QueryOptions::_qo->retry_on_conflict = retryOnConflict;
    }

    void QueryOptions::volatiles(const char* volatiles) {
        QueryOptions::_qo->volatiles = volatiles;
    }

}