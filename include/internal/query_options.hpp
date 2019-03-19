#ifndef QUERY_OPTIONS_HPP
#define QUERY_OPTIONS_HPP

#include <string>
#include "core.hpp"
#include "kuzzle.hpp"

namespace kuzzleio {

    class QueryOptions {
        private:
            query_options* _qo = nullptr;
            const char* strdup(const char* s);

        public:

            QueryOptions(const query_options* src);

            QueryOptions(const QueryOptions& src);

            QueryOptions() :
            _qo(new query_options())
            {};

            virtual inline ~QueryOptions() {if (_qo != nullptr) {kuzzle_free_query_options(_qo);}};

            query_options *qo() const;

            bool queuable() const;

            bool withdist() const;

            bool withcoord() const;

            long from() const;

            long size() const;

            const char* scroll() const;

            const char* scrollId() const;

            const char* refresh() const;

            const char* ifExist() const;

            int retryOnConflict() const;

            const char* volatiles() const;

            void queuable(bool queuable);

            void withdist(bool withdist);

            void withcoord(bool withcoord);

            void from(long from);

            void size(long size);

            void scroll(const char* scroll);

            void scrollId(const char* scrollId);

            void refresh(const char* refresh);

            void ifExist(const char* ifExist);

            void retryOnConflict(int retryOnConflict);

            void volatiles(const char* volatiles);
    };
}

#endif //QUERY_OPTIONS_HPP
