#include "websocket.hpp"
#include <iostream>

namespace kuzzleio {

    WebSocket::WebSocket(const std::string& host, options *opts) {
      this->_web_socket = new web_socket();

      kuzzle_websocket_new_web_socket(this->_web_socket, const_cast<char*>(host.c_str()), opts, this);
    }

    void trigger_websocket_event_listener(int event, char* res, void* data) {
      EventListener* listener = static_cast<WebSocket*>(data)->getListeners()[event];
      if (listener) {
        (*listener)(res);
      }
    }

    std::map<int, EventListener*> WebSocket::getListeners() noexcept {
      return _listener_instances;
    }

    void WebSocket::addListener(Event event, EventListener* listener) {
      kuzzle_websocket_add_listener(this->_web_socket, event, trigger_websocket_event_listener);
      _listener_instances[event] = listener;
    }

    void WebSocket::removeListener(Event, EventListener*) {}

    void WebSocket::removeAllListeners(Event event) {
      kuzzle_websocket_remove_all_listeners(this->_web_socket, event);
    }

    void WebSocket::once(Event, EventListener*) {}

    int WebSocket::listenerCount(Event event) {
      return kuzzle_websocket_listener_count(this->_web_socket, event);
    }

    char* WebSocket::connect() {
      return kuzzle_websocket_connect(this->_web_socket);
    }

    kuzzle_response* WebSocket::send(const std::string& query, query_options *options, const std::string& request_id) {
      return kuzzle_websocket_send(this->_web_socket, const_cast<char*>(query.c_str()), options, const_cast<char*>(request_id.c_str()));
    }

    std::string WebSocket::close() {
      const char* res = kuzzle_websocket_close(this->_web_socket);
      if (res) {
        return std::string(kuzzle_websocket_close(this->_web_socket));
      }
      return "";
    }

    int WebSocket::getState() {
      return kuzzle_websocket_get_state(this->_web_socket);
    }
    
    void WebSocket::emitEvent(Event event) {
      kuzzle_websocket_emit_event(this->_web_socket, event, nullptr);
    }

    void WebSocket::registerSub(const std::string&, const std::string&, const std::string&, int, NotificationListener*, void*) {}

    void WebSocket::unregisterSub(const std::string& id) {
      kuzzle_websocket_unregister_sub(this->_web_socket, const_cast<char*>(id.c_str()));
    }

    void WebSocket::cancelSubs() {
      kuzzle_websocket_cancel_subs(this->_web_socket);
    }

    void WebSocket::startQueuing() {
      kuzzle_websocket_start_queuing(this->_web_socket);
    }

    void WebSocket::stopQueuing() {
      kuzzle_websocket_stop_queuing(this->_web_socket);
    }
    void WebSocket::playQueue() {
      kuzzle_websocket_play_queue(this->_web_socket);
    }

    void WebSocket::clearQueue() {
      kuzzle_websocket_clear_queue(this->_web_socket);
    }

}