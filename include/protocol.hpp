#ifndef KUZZLE_PROTOCOL_HPP
#define KUZZLE_PROTOCOL_HPP

#include <string>
#include <map>
#include <memory>
#include "kuzzle.hpp"
#include "internal/protocol.h"
#include "internal/event_emitter.hpp"

namespace kuzzleio {
  class Protocol : public KuzzleEventEmitter {
    private:
      std::map<
          kuzzle_event_listener, SharedEventListener> bridgeListeners;

      std::map<
          std::string,
          std::map<
            kuzzle_notification_listener,
            std::shared_ptr<NotificationListener>
          >
      > bridgeSubs;

    protected:
      std::map<
          std::string,
          std::set<std::shared_ptr<NotificationListener>>
      > notificationListeners;

      virtual void notify(notification_result* payload) noexcept;

    public:
      virtual ~Protocol() = default;

      // to be implemented
      virtual void connect() = 0;
      virtual kuzzle_response* send(
          const std::string& query, query_options * options,
          const std::string& requestId) = 0;
      virtual void close() = 0;
      virtual int getState() = 0;
      virtual std::string getHost() = 0;
      virtual bool isReady() = 0;

      // to be overridden: though the NotificationListener storage is
      // handled by this class, you still need to send a subscribe request
      // to Kuzzle, using the provided arguments, using the implemented
      // protocol
      virtual void registerSub(
          const std::string& channel, const std::string& roomId,
          const std::string& filters, bool subscribetoSelf,
          std::shared_ptr<NotificationListener> listener);
      virtual void unregisterSub(const std::string& channel);
      virtual void cancelSubs();

      // event emitter overrides
      virtual KuzzleEventEmitter* removeAllListeners(Event) noexcept override;

      // internals -- used for bridging with golang
      using KuzzleEventEmitter::removeListener;
      virtual void removeListener(int, kuzzle_event_listener);

      using KuzzleEventEmitter::addListener;
      virtual void addListener(int, kuzzle_event_listener);

      using KuzzleEventEmitter::once;
      virtual void once(int, kuzzle_event_listener);

      virtual void registerSub(
        const std::string& channel, const std::string& roomId,
        const std::string& filters, bool subscribetoSelf,
        kuzzle_notification_listener listener);
  };

  protocol* new_protocol_bridge(Protocol*);
}

#endif
