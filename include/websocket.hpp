#ifndef KUZZLE_WEBSOCKET_HPP
#define KUZZLE_WEBSOCKET_HPP

#include <map>
#include <list>
#include "internal/core.hpp"
#include "protocol.hpp"

namespace kuzzleio {

  class WebSocket : public Protocol {
    private:
      std::map<int, std::list<EventListener*>>  _websocket_listener_instances;
      std::map<int, std::list<EventListener*>>  _websocket_once_listener_instances;
      std::map<std::string, NotificationListener*>  _websocket_notification_listener_instances;
    public:
    web_socket* _web_socket;
    WebSocket(const std::string&, options* query_options=nullptr);
    std::list<EventListener*> getListeners(int) noexcept;
    std::list<EventListener*> getOnceListeners(int) noexcept;
    NotificationListener* getNotificationListener(const std::string&) noexcept;

    virtual void addListener(KuzzleEvent, EventListener*);
    virtual void removeListener(KuzzleEvent, EventListener*);
    virtual void removeAllListeners(KuzzleEvent);
    virtual void once(KuzzleEvent, EventListener*);
    virtual int listenerCount(KuzzleEvent);
    virtual char* connect();
    virtual kuzzle_response* send(const std::string&, query_options *, const std::string&);
    virtual std::string close();
    virtual int getState();
    virtual void emitEvent(KuzzleEvent);
    virtual void registerSub(const std::string&, const std::string&, const std::string&, bool, NotificationListener*);
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