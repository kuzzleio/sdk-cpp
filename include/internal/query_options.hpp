#ifndef QUERY_OPTIONS_HPP
#define QUERY_OPTIONS_HPP

#include <string>
#include "core.hpp"

namespace kuzzleio {

    class QueryOptions {
        private:
            const query_options* queryOptsC = new query_options();
            bool queuable;
            bool withdist;
            bool withcoord;
            long from;
            long size;
            std::string scroll;
            std::string scrollId;
            std::string refresh;
            std::string ifExist;
            int retryOnConflict;
            std::string volatiles;

        public:
            QueryOptions(const query_options* u) :
                queryOptsC(u),
                queuable(u->queuable),
                withdist(u->withdist),
                withcoord(u->withcoord),
                from(u->from),
                size(u->size),
                scroll(u->scroll),
                scrollId(u->scroll_id),
                refresh(u->refresh),
                ifExist(u->if_exist),
                retryOnConflict(u->retry_on_conflict),
                volatiles(u->volatiles)
                {};

            QueryOptions(const QueryOptions& u) :
                queryOptsC(u.queryOptsC),
                queuable(u.queuable),
                withdist(u.withdist),
                withcoord(u.withcoord),
                from(u.from),
                size(u.size),
                scroll(u.scroll),
                scrollId(u.scrollId),
                refresh(u.refresh),
                ifExist(u.ifExist),
                retryOnConflict(u.retryOnConflict),
                volatiles(u.volatiles)
                {};

            QueryOptions() {};

            const query_options *getQueryOptsC() const;

            bool isQueuable() const;

            bool isWithdist() const;

            bool isWithcoord() const;

            long getFrom() const;

            long getSize() const;

            const std::string &getScroll() const;

            const std::string &getScrollId() const;

            const std::string &getRefresh() const;

            const std::string &getIfExist() const;

            int getRetryOnConflict() const;

            const std::string &getVolatiles() const;

            void setQueuable(bool queuable);

            void setWithdist(bool withdist);

            void setWithcoord(bool withcoord);

            void setFrom(long from);

            void setSize(long size);

            void setScroll(const std::string &scroll);

            void setScrollId(const std::string &scrollId);

            void setRefresh(const std::string &refresh);

            void setIfExist(const std::string &ifExist);

            void setRetryOnConflict(int retryOnConflict);

            void setVolatiles(const std::string &volatiles);
    };
}

#endif //QUERY_OPTIONS_HPP
