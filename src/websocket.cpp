#include "websocket.hpp"

namespace kuzzleio {
  // go websocket listener bridges
  void bridge_notify(notification_result* payload, void* _ws) {
    static_cast<WebSocket*>(_ws)->notify(payload);
  }

  // WebSocket class implementation
  WebSocket::WebSocket(const std::string& host)
    : WebSocket(host, Options()) {}

  WebSocket::WebSocket(const std::string& host, const Options& options) {
    this->_web_socket = new web_socket();

    kuzzle_websocket_new_web_socket(
        this->_web_socket,
        const_cast<char*>(host.c_str()),
        options.c_opts(),
        this);
  }

  WebSocket::~WebSocket() {
    kuzzle_websocket_remove_all_listeners(this->_web_socket, -1);
    kuzzle_websocket_cancel_subs(this->_web_socket);

    try {
      this->close();
    } catch(InternalException e) {
      // Ignores the exception: it doesn't matter if
      // closing the socket fails, since we're destroying
      // it anyway
    }

<<<<<<< HEAD
  void trigger_websocket_notification_listener(notification_result* result, void* data) {
    NotificationListener* listener = static_cast<WebSocket*>(data)->getNotificationListener(result->room_id);
    if (listener) {
      (*listener)(new NotificationResult(result));
    }
=======
    unregisterWebSocket(this->_web_socket);
    delete this->_web_socket;
>>>>>>> origin/1-dev
  }

  KuzzleEventEmitter* WebSocket::addListener(
      Event event,
      SharedEventListener listener) noexcept {
    Protocol::addListener(event, listener);

    // this results in a no-op if that bridge listener is already registered
    kuzzle_websocket_add_listener(this->_web_socket, event, _c_emit_event);
    return this;
  }

  KuzzleEventEmitter* WebSocket::removeListener(
      Event event,
      SharedEventListener listener) noexcept {
    Protocol::removeListener(event, listener);

    // if no listener remains, we need to unregister it from the go websocket
    // layers
    if (this->listeners.find(event) == this->listeners.end()) {
      kuzzle_websocket_remove_listener(
          this->_web_socket, event, _c_emit_event);
    }

    return this;
  }

  KuzzleEventEmitter* WebSocket::removeAllListeners(Event event) noexcept {
    Protocol::removeAllListeners(event);
    kuzzle_websocket_remove_all_listeners(this->_web_socket, event);
    return this;
  }

  KuzzleEventEmitter* WebSocket::once(
      Event event,
      SharedEventListener listener) noexcept {
    Protocol::once(event, listener);

    // this results in a no-op if that bridge listener is already registered
    kuzzle_websocket_once(this->_web_socket, event, _c_emit_event);

    return this;
  }

  void WebSocket::connect() {
    char* err = kuzzle_websocket_connect(this->_web_socket);
    if (err != nullptr) {
      const std::string cppError(err);
      free(err);
      throw InternalException(cppError);
    }
  }

  kuzzle_response* WebSocket::send(
      const std::string& query,
      query_options *options,
      const std::string& request_id) {
    return kuzzle_websocket_send(this->_web_socket,
                                 const_cast<char*>(query.c_str()), options,
                                 const_cast<char*>(request_id.c_str()));
  }

  void WebSocket::close() {
    char* err = kuzzle_websocket_close(this->_web_socket);

    if (err != nullptr) {
      const std::string cppError(err);
      free(err);
      throw InternalException(cppError);
    }
  }

  int WebSocket::getState() {
    return kuzzle_websocket_get_state(this->_web_socket);
  }

  // this ones is only used to change the "notify" method visibility
  // from protected to public
  void WebSocket::notify(notification_result* payload) noexcept {
    Protocol::notify(payload);
  }

  void WebSocket::registerSub(
      const std::string& channel,
      const std::string& room_id,
      const std::string& filters,
      bool subscribe_to_self,
      std::shared_ptr<NotificationListener> listener) {

    Protocol::registerSub(
        channel, room_id, filters, subscribe_to_self, listener);

    kuzzle_websocket_register_sub(
        this->_web_socket,
        const_cast<char*>(channel.c_str()),
        const_cast<char*>(room_id.c_str()),
        const_cast<char*>(filters.c_str()),
        subscribe_to_self,
        bridge_notify);
  }

  void WebSocket::unregisterSub(const std::string& channel) {
    kuzzle_websocket_unregister_sub(
        this->_web_socket, const_cast<char*>(channel.c_str()));
    Protocol::unregisterSub(channel);
  }

  void WebSocket::cancelSubs() {
    kuzzle_websocket_cancel_subs(this->_web_socket);
    Protocol::cancelSubs();
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
    char *host = kuzzle_websocket_get_host(this->_web_socket);
    std::string str_host(host);
    free(host);

    return str_host;
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
