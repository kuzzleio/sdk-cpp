#ifndef QUERY_OPTIONS_HPP
#define QUERY_OPTIONS_HPP

#include <string>
#include "core.hpp"

namespace kuzzleio {

    class QueryOptions {
        private:
            const query_options* _queryOptsC = new query_options();
            bool _queuable;
            bool _withdist;
            bool _withcoord;
            long _from;
            long _size;
            std::string _scroll;
            std::string _scrollId;
            std::string _refresh;
            std::string _ifExist;
            int _retryOnConflict;
            std::string _volatiles;

        public:
            QueryOptions(const query_options* u) :
                _queryOptsC(u),
                _queuable(u->queuable),
                _withdist(u->withdist),
                _withcoord(u->withcoord),
                _from(u->from),
                _size(u->size),
                _scroll(u->scroll),
                _scrollId(u->scroll_id),
                _refresh(u->refresh),
                _ifExist(u->if_exist),
                _retryOnConflict(u->retry_on_conflict),
                _volatiles(u->volatiles)
                {};

            QueryOptions(const QueryOptions& u) :
                _queryOptsC(u._queryOptsC),
                _queuable(u._queuable),
                _withdist(u._withdist),
                _withcoord(u._withcoord),
                _from(u._from),
                _size(u._size),
                _scroll(u._scroll),
                _scrollId(u._scrollId),
                _refresh(u._refresh),
                _ifExist(u._ifExist),
                _retryOnConflict(u._retryOnConflict),
                _volatiles(u._volatiles)
                {};

            QueryOptions() {};

            const query_options *queryOptsC() const;

            bool queuable() const;

            bool withdist() const;

            bool withcoord() const;

            long from() const;

            long size() const;

            const std::string &scroll() const;

            const std::string &scrollId() const;

            const std::string &refresh() const;

            const std::string &ifExist() const;

            int retryOnConflict() const;

            const std::string &volatiles() const;

            void queuable(bool queuable);

            void withdist(bool withdist);

            void withcoord(bool withcoord);

            void from(long from);

            void size(long size);

            void scroll(const std::string &scroll);

            void scrollId(const std::string &scrollId);

            void refresh(const std::string &refresh);

            void ifExist(const std::string &ifExist);

            void retryOnConflict(int retryOnConflict);

            void volatiles(const std::string &volatiles);
    };
}

#endif //QUERY_OPTIONS_HPP
