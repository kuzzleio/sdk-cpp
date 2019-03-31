#include "internal/query_options.hpp"
#include "internal/utils.hpp"

namespace kuzzleio {

    QueryOptions::QueryOptions(const QueryOptions &src) {
        _qo = static_cast<query_options*>(calloc(1, sizeof(query_options)));
        _qo->queuable = src.queuable();
        _qo->withdist = src.withdist();
        _qo->withcoord = src.withcoord();
        _qo->from = src.from();
        _qo->size = src.size();
        _qo->scroll = toC::dupstring(src.scroll());
        _qo->scroll_id = toC::dupstring(src.scrollId());
        _qo->refresh = toC::dupstring(src.refresh());
        _qo->if_exist = toC::dupstring(src.ifExist());
        _qo->volatiles = toC::dupstring(src.volatiles());
        _qo->retry_on_conflict = src.retryOnConflict();
    }
    QueryOptions::QueryOptions(const query_options* src) {
        _qo = static_cast<query_options*>(calloc(1, sizeof(query_options)));
        _qo->queuable = src->queuable;
        _qo->withdist = src->withdist;
        _qo->withcoord = src->withcoord;
        _qo->from = src->from;
        _qo->size = src->size;
        _qo->scroll = toC::dupstring(src->scroll);
        _qo->scroll_id = toC::dupstring(src->scroll_id);
        _qo->refresh = toC::dupstring(src->refresh);
        _qo->if_exist = toC::dupstring(src->if_exist);
        _qo->volatiles = toC::dupstring(src->volatiles);
        _qo->retry_on_conflict = src->retry_on_conflict;
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
        if (_qo->scroll != nullptr)
            free(const_cast<char*>(_qo->scroll));
        QueryOptions::_qo->scroll = toC::dupstring(scroll);
    }

    void QueryOptions::scrollId(const char* scrollId) {
        if (_qo->scroll_id != nullptr)
            free(const_cast<char*>(_qo->scroll_id));
        QueryOptions::_qo->scroll_id = toC::dupstring(scrollId);
    }

    void QueryOptions::refresh(const char* refresh) {
        if (_qo->refresh != nullptr)
            free(const_cast<char*>(_qo->refresh));
        QueryOptions::_qo->refresh = toC::dupstring(refresh);
    }

    void QueryOptions::ifExist(const char* ifExist) {
        if (_qo->if_exist != nullptr)
            free(const_cast<char*>(_qo->if_exist));
        QueryOptions::_qo->if_exist = toC::dupstring(ifExist);
    }

    void QueryOptions::retryOnConflict(int retryOnConflict) {
        QueryOptions::_qo->retry_on_conflict = retryOnConflict;
    }

    void QueryOptions::volatiles(const char* volatiles) {
        if (_qo->volatiles != nullptr)
            free(const_cast<char*>(_qo->volatiles));
        QueryOptions::_qo->volatiles = toC::dupstring(volatiles);
    }
}