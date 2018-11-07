#ifndef KUZZLE_WEBSOCKET_HPP
#define KUZZLE_WEBSOCKET_HPP

#include <map>
#include <list>
#include "core.hpp"
#include "protocol.hpp"

namespace kuzzleio {

  class WebSocket : public Protocol {
    private:
      std::map<int, std::list<EventListener*>>  _websocket_listener_instances;
      std::map<int, std::list<EventListener*>>  _websocket_once_listener_instances;
    public:
    web_socket* _web_socket;
    WebSocket(const std::string&, options* query_options=nullptr);
    std::list<EventListener*> getListeners(int) noexcept;
    std::list<EventListener*> getOnceListeners(int) noexcept;

    virtual void addListener(Event, EventListener*);
    virtual void removeListener(Event, EventListener*);
    virtual void removeAllListeners(Event);
    virtual void once(Event, EventListener*);
    virtual int listenerCount(Event);
    virtual char* connect();
    virtual kuzzle_response* send(const std::string&, query_options *, const std::string&);
    virtual std::string close();
    virtual int getState();
    virtual void emitEvent(Event);
    virtual void registerSub(const std::string&, const std::string&, const std::string&, int, NotificationListener*, void*);
    virtual void unregisterSub(const std::string&);
    virtual void cancelSubs();
    virtual void startQueuing();
    virtual void stopQueuing();
    virtual void playQueue();
    virtual void clearQueue();
  };

}

#endif