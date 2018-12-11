#include "websocket.hpp"

namespace kuzzleio {
  WebSocket::WebSocket(const std::string& host, options *opts) {
    this->_web_socket = new web_socket();

    kuzzle_websocket_new_web_socket(this->_web_socket, const_cast<char*>(host.c_str()), opts, this);
  }

  void trigger_websocket_event_listener(int event, char* res, void* data) {
    std::list<EventListener*> listeners = static_cast<WebSocket*>(data)->getListeners(event);
    for (EventListener*& listener : listeners) {
      (*listener)(res);
    }
  }

  void trigger_websocket_once(int event, char* res, void* data) {
    std::list<EventListener*> listeners = static_cast<WebSocket*>(data)->getOnceListeners(event);
    for (EventListener*& listener : listeners) {
      (*listener)(res);
      static_cast<WebSocket*>(data)->getOnceListeners(event).remove(listener);
    }
  }

  void trigger_websocket_notification_listener(notification_result* result, void* data) {
    NotificationListener* listener = static_cast<WebSocket*>(data)->getNotificationListener(result->room_id);
    if (listener) {
      (*listener)(result);
    }
  }

  std::list<EventListener*> WebSocket::getListeners(int event) noexcept {
    return _websocket_listener_instances[event];
  }

  std::list<EventListener*> WebSocket::getOnceListeners(int event) noexcept {
    return _websocket_once_listener_instances[event];
  }

  NotificationListener* WebSocket::getNotificationListener(const std::string& room_id) noexcept {
    return _websocket_notification_listener_instances[room_id];
  }

  void WebSocket::addListener(Event event, EventListener* listener) {
    _websocket_listener_instances[event].push_back(listener);
    kuzzle_websocket_add_listener(this->_web_socket, event, trigger_websocket_event_listener);
  }

  void WebSocket::removeListener(Event event, EventListener* listener) {
    _websocket_listener_instances[event].remove(listener);
  }

  void WebSocket::removeAllListeners(Event event) {
    kuzzle_websocket_remove_all_listeners(this->_web_socket, event);
    _websocket_listener_instances[event].clear();
  }

  void WebSocket::once(Event event, EventListener* listener) {
    _websocket_once_listener_instances[event].push_back(listener);
    kuzzle_websocket_once(this->_web_socket, event, trigger_websocket_once);
  }

  int WebSocket::listenerCount(Event event) {
    return kuzzle_websocket_listener_count(this->_web_socket, event);
  }

  void WebSocket::connect() {
    char* err = kuzzle_websocket_connect(this->_web_socket);
    if (err != NULL) {
      const std::string cppError = err;
      free(err);
      throw InternalException(cppError);
    }
  }

  kuzzle_response* WebSocket::send(const std::string& query, query_options *options, const std::string& request_id) {
    kuzzle_response* res = kuzzle_websocket_send(this->_web_socket, const_cast<char*>(query.c_str()), options, const_cast<char*>(request_id.c_str()));
    return res;
  }

  void WebSocket::close() {
    char* err = kuzzle_websocket_close(this->_web_socket);

    if (err != NULL) {
      const std::string cppError = err;
      free(err);
      throw InternalException(cppError);
    }
  }

  int WebSocket::getState() {
    return kuzzle_websocket_get_state(this->_web_socket);
  }

  void WebSocket::emitEvent(Event event) {
    kuzzle_websocket_emit_event(this->_web_socket, event, nullptr);
  }

  void WebSocket::registerSub(const std::string& channel, const std::string& room_id, const std::string& filters, bool subscribe_to_self, NotificationListener* listener) {
    _websocket_notification_listener_instances[channel] = listener;
    kuzzle_websocket_register_sub(this->_web_socket, const_cast<char*>(channel.c_str()), const_cast<char*>(room_id.c_str()), const_cast<char*>(filters.c_str()), subscribe_to_self, trigger_websocket_notification_listener);
  }

  void WebSocket::unregisterSub(const std::string& id) {
    kuzzle_websocket_unregister_sub(this->_web_socket, const_cast<char*>(id.c_str()));
    _websocket_notification_listener_instances[id] = nullptr;
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

  bool WebSocket::isAutoReconnect() {
    return kuzzle_websocket_is_auto_reconnect(this->_web_socket);
  }

  bool WebSocket::isAutoResubscribe() {
    return kuzzle_websocket_is_auto_resubscribe(this->_web_socket);
  }

  std::string WebSocket::getHost() {
    return std::string(kuzzle_websocket_get_host(this->_web_socket));
  }

  unsigned int WebSocket::getPort() {
    return kuzzle_websocket_get_port(this->_web_socket);
  }

  unsigned long long WebSocket::getReconnectionDelay() {
    return kuzzle_websocket_get_reconnection_delay(this->_web_socket);
  }

  bool WebSocket::isSslConnection() {
    return kuzzle_websocket_is_ssl_connection(this->_web_socket);
  }
}
