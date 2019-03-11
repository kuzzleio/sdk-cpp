#ifndef _NOTIFICATION_RESULT_HPP
#define _NOTIFICATION_RESULT_HPP

#include <string>
#include "notification_content.hpp"

namespace kuzzleio {
  class NotificationResult {
    private:
      const std::string requestId;
      const NotificationContent result;
      const std::string volatiles;
      const std::string index;
      const std::string collection;
      const std::string controller;
      const std::string action;
      const std::string protocol;
      const std::string scope;
      const std::string state;
      const std::string user;
      const std::string nType;
      const std::string roomId;
      const uint64_t timestamp;
      const int status;
      const std::string error;
      const std::string stack;

    public:
      NotificationResult(const notification_result* r) :
        requestId(r->request_id),
        result(NotificationContent(r->result)),
        volatiles(r->volatiles),
        index(r->index),
        collection(r->collection),
        controller(r->controller),
        action(r->action),
        protocol(r->protocol),
        scope(r->scope),
        state(r->state),
        user(r->user),
        nType(r->n_type),
        roomId(r->room_id),
        timestamp(r->timestamp),
        status(r->status),
        error(r->error ? r->error : ""),
        stack(r->stack ? r->stack : "")
        {}

      NotificationResult(const NotificationResult& r) :
        requestId(r.requestId),
        result(NotificationContent(r.result)),
        volatiles(r.volatiles),
        index(r.index),
        collection(r.collection),
        controller(r.controller),
        action(r.action),
        protocol(r.protocol),
        scope(r.scope),
        state(r.state),
        user(r.user),
        nType(r.nType),
        roomId(r.roomId),
        timestamp(r.timestamp),
        status(r.status),
        error(r.error),
        stack(r.stack)
        {}

      const std::string &getRequestId() const;

      const NotificationContent &getResult() const;

      const std::string &getVolatiles() const;

      const std::string &getIndex() const;

      const std::string &getCollection() const;

      const std::string &getController() const;

      const std::string &getAction() const;

      const std::string &getProtocol() const;

      const std::string &getScope() const;

      const std::string &getState() const;

      const std::string &getUser() const;

      const std::string &getNType() const;

      const std::string &getRoomId() const;

      const uint64_t getTimestamp() const;

      const int getStatus() const;

      const std::string &getError() const;

      const std::string &getStack() const;
  };
}

#endif