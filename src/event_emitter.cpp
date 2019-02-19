#include "internal/event_emitter.hpp"

namespace kuzzleio {
  void _c_emit_event(int event, char* payload, void* ptr) {
    static_cast<KuzzleEventEmitter*>(ptr)->emitEvent(
      static_cast<Event>(event),
      payload);
  }

  KuzzleEventEmitter* KuzzleEventEmitter::addListener(
      Event e,
      SharedEventListener l) noexcept {
    this->listeners[e].insert(l);
    return this;
  }

  KuzzleEventEmitter* KuzzleEventEmitter::removeListener(
      Event e,
      SharedEventListener l) noexcept {
    auto lset = this->listeners.find(e);

    if (lset != this->listeners.end()) {
      lset->second.erase(l);

      if (lset->second.empty()) {
        this->listeners.erase(e);
      }
    }

    return this;
  }

  KuzzleEventEmitter* KuzzleEventEmitter::removeAllListeners(Event e) noexcept {
    this->listeners.erase(e);

    return this;
  }

  KuzzleEventEmitter* KuzzleEventEmitter::once(
      Event e,
      SharedEventListener l) noexcept {
    this->onceListeners[e].insert(l);

    return this;
  }

  int KuzzleEventEmitter::listenerCount(Event e) noexcept {
    auto lset = this->listeners.find(e);

    if (lset != this->listeners.end()) {
      return lset->second.size();
    }

    return 0;
  }

  void KuzzleEventEmitter::emitEvent(
      Event e,
      const std::string& payload) noexcept {

    auto lset = this->listeners.find(e);

    if (lset != this->listeners.end()) {
      for(auto l : lset->second) {
        (*l)(payload);
      }
    }

    this->emitEventOnce(e, payload);
  }

  void KuzzleEventEmitter::emitEventOnce(
      Event e,
      const std::string& payload) noexcept {
    auto lset = this->onceListeners.find(e);

    if (lset != this->listeners.end()) {
      for(auto l : lset->second) {
        (*l)(payload);
      }

      this->onceListeners.erase(e);
    }
  }
}
