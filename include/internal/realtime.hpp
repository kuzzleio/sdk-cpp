#ifndef _KUZZLE_REALTIME_HPP
#define _KUZZLE_REALTIME_HPP

#include <map>
#include <functional>

#include "exceptions.hpp"
#include "core.hpp"
#include "internal/notification_result.hpp"

namespace kuzzleio {
  typedef std::function<void(kuzzleio::NotificationResult*)> NotificationListener;

  class Kuzzle;

  class Realtime {
    private:
      realtime *_realtime;
      std::map<std::string, NotificationListener*> _listener_instances;

    public:
      Realtime(kuzzle* kuzzle);
      virtual ~Realtime();
      int count(const std::string& roomId, query_options *options=nullptr);
      void publish(const std::string& index, const std::string& collection, const std::string& body, query_options *options=nullptr);
      std::string subscribe(const std::string& index, const std::string& collection, const std::string& body, NotificationListener* cb, room_options* options=nullptr);
      void unsubscribe(const std::string& roomId, query_options *options=nullptr);

      NotificationListener* getListener(const std::string& roomId);
  };
}

#endif
