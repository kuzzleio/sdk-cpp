#ifndef KUZZLE_WEBSOCKET_HPP
#define KUZZLE_WEBSOCKET_HPP

#include "internal/core.hpp"
#include "protocol.hpp"

namespace kuzzleio {
  class WebSocket : public Protocol {
    private:
      web_socket* _web_socket;

    public:
      WebSocket(const std::string& host, options* query_options=nullptr);
      virtual ~WebSocket();

      virtual KuzzleEventEmitter* addListener(
          Event, SharedEventListener) noexcept override;
      virtual KuzzleEventEmitter* removeListener(
          Event, SharedEventListener) noexcept override;
      virtual KuzzleEventEmitter* removeAllListeners(Event) noexcept override;
      virtual KuzzleEventEmitter* once(
          Event, SharedEventListener) noexcept override;

      virtual void notify(notification_result* payload) noexcept;

      virtual void connect();
      virtual kuzzle_response* send(const std::string&, query_options *,
          const std::string&);
      virtual void close();
      virtual int getState();
      virtual void registerSub(
          const std::string& channel, const std::string& room_id,
          const std::string& filters, bool subscribe_to_self,
          std::shared_ptr<NotificationListener>);
      virtual void unregisterSub(const std::string&);
      virtual void cancelSubs();
      virtual void startQueuing();
      virtual void stopQueuing();
      virtual void playQueue();
      virtual void clearQueue();
      virtual std::string getHost();

      // Getters
      bool isAutoReconnect();
      bool isAutoResubscribe();
      unsigned int getPort();
      unsigned long long getReconnectionDelay();
      bool isSslConnection();
  };
}

#endif
