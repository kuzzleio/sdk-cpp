#ifndef QUERY_OPTIONS_HPP
#define QUERY_OPTIONS_HPP

#include <string>
#include "core.hpp"

namespace kuzzleio {

    class QueryOptions {
        private:
            const query_options* _queryOptsC = nullptr;
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

            QueryOptions(const query_options* src) :
                _queryOptsC(cpyStruct(src)),
                _queuable(src->queuable),
                _withdist(src->withdist),
                _withcoord(src->withcoord),
                _from(src->from),
                _size(src->size),
                _scroll(src->scroll),
                _scrollId(src->scroll_id),
                _refresh(src->refresh),
                _ifExist(src->if_exist),
                _retryOnConflict(src->retry_on_conflict),
                _volatiles(src->volatiles)
                {};

            QueryOptions(const QueryOptions& src) :
                _queryOptsC(cpyStruct(src._queryOptsC)),
                _queuable(src._queuable),
                _withdist(src._withdist),
                _withcoord(src._withcoord),
                _from(src._from),
                _size(src._size),
                _scroll(src._scroll),
                _scrollId(src._scrollId),
                _refresh(src._refresh),
                _ifExist(src._ifExist),
                _retryOnConflict(src._retryOnConflict),
                _volatiles(src._volatiles)
                {};

            QueryOptions() :
            _queuable(false),
            _withdist(false),
            _withcoord(false),
            _from(0),
            _size(0),
            _retryOnConflict(0)
            {};

            const query_options* cpyStruct(const query_options* src);

            virtual inline ~QueryOptions() { if (_queryOptsC != nullptr) delete(_queryOptsC); };

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
