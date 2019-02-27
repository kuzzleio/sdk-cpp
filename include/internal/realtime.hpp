#ifndef _KUZZLE_REALTIME_HPP
#define _KUZZLE_REALTIME_HPP

#include <map>
#include <functional>
#include <memory>

#include "exceptions.hpp"
#include "core.hpp"
#include "internal/notification_result.hpp"

namespace kuzzleio {
<<<<<<< HEAD
  typedef std::function<void(kuzzleio::NotificationResult*)> NotificationListener;
=======
  typedef std::function<void(std::shared_ptr<notification_result>)>
    NotificationListener;
>>>>>>> origin/1-dev

  class Kuzzle;

  class Realtime {
    private:
      realtime *_realtime;
      std::map<std::string, NotificationListener*> _listener_instances;

    public:
      Realtime(kuzzle* kuzzle);
      virtual ~Realtime();

      int count(const std::string& room_id);
      int count(const std::string& room_id, const query_options& options);

      void publish(const std::string& index, const std::string& collection,
          const std::string& message);
      void publish(const std::string& index, const std::string& collection,
          const std::string& message, const query_options& options);

      std::string subscribe(const std::string& index,
          const std::string& collection, const std::string& filters,
          NotificationListener* listener);
      std::string subscribe(const std::string& index,
          const std::string& collection, const std::string& filters,
          NotificationListener* listener, const room_options& options);

      void unsubscribe(const std::string& room_id);
      void unsubscribe(const std::string& room_id,
          const query_options& options);

      // Internal usage only
      NotificationListener* getListener(const std::string& room_id);
  };
}

#endif
