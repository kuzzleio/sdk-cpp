#ifndef KUZZLE_PROTOCOL_HPP
#define KUZZLE_PROTOCOL_HPP

#include <string>
#include <map>
#include "kuzzle.hpp"
#include "internal/protocol.h"

namespace kuzzleio {
  
  class Protocol {
    public:
      protocol *_protocol;
      std::map<int, std::map<kuzzle_event_listener*, EventListener*>>  listener_instances;
      std::map<int, std::map<kuzzle_event_listener*, EventListener*>>  listener_once_instances;
      std::map<std::string, NotificationListener*> notification_listener_instances;

    virtual void addListener(Event, EventListener*) = 0;
    virtual void removeListener(Event, EventListener*) = 0;
    virtual void removeAllListeners(Event) = 0;
    virtual void once(Event, EventListener*) = 0;
    virtual int listenerCount(Event) = 0;
    virtual void connect() = 0;
    virtual kuzzle_response* send(const std::string&, query_options *, const std::string&) = 0;
    virtual void close() = 0;
    virtual int getState() = 0;
    virtual void emitEvent(Event) = 0;
    virtual void registerSub(const std::string&, const std::string&, const std::string&, bool, NotificationListener*) = 0;
    virtual void unregisterSub(const std::string&) = 0;
    virtual void cancelSubs() = 0;
    virtual void startQueuing() = 0;
    virtual void stopQueuing() = 0;
    virtual void playQueue() = 0;
    virtual void clearQueue() = 0;
    virtual std::string getHost() = 0;
  };

}

#endif
