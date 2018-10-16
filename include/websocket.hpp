#ifndef KUZZLE_WEBSOCKET_HPP
#define KUZZLE_WEBSOCKET_HPP

#include "core.hpp"
#include "protocol.hpp"

namespace kuzzleio {

  class WebSocket : public Protocol {
    public:
    web_socket* _web_socket;
    WebSocket(const std::string&, options*);
    virtual void addListener(int, EventListener*);
    virtual void removeListener(int, EventListener*);
    virtual void removeAllListeners(int);
    virtual void once(int, EventListener*);
    virtual int listenerCount(int);
    virtual void connect();
    virtual std::string send(const std::string&, query_options *, kuzzle_response*, const std::string&);
    virtual std::string close();
    virtual int getState();
    virtual void emitEvent(int, void*);
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