#ifndef KUZZLE_PROTOCOL_HPP
#define KUZZLE_PROTOCOL_HPP

#include <string>
#include "core.hpp"
#include "kuzzle.hpp"
#include "event_emitter.hpp"
#include "realtime.hpp"

namespace kuzzleio {

  class Protocol {
    public:
    protocol *_protocol;
    virtual void addListener(int, EventListener*) = 0;
    virtual void removeListener(int, EventListener*) = 0;
    virtual void removeAllListeners(int) = 0;
    virtual void once(int, EventListener*) = 0;
    virtual int listenerCount(int) = 0;
    virtual void connect() = 0;
    virtual std::string send(const std::string&, query_options *, kuzzle_response*, const std::string&) = 0;
    virtual std::string close() = 0;
    virtual int getState() = 0;
    virtual void emitEvent(int, void*) = 0;
    virtual void registerSub(const std::string&, const std::string&, const std::string&, int, NotificationListener*, void*) = 0;
    virtual void unregisterSub(const std::string&) = 0;
    virtual void cancelSubs() = 0;
    virtual void startQueuing() = 0;
    virtual void stopQueuing() = 0;
    virtual void playQueue() = 0;
    virtual void clearQueue() = 0;
  };

}

#endif