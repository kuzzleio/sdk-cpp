#ifndef _NOTIFICATION_RESULT_HPP
#define _NOTIFICATION_RESULT_HPP

#include <string>
#include "notification_content.hpp"

namespace kuzzleio {
  class NotificationResult {
     public:
      const std::string request_id;
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
      const std::string n_type;
      const std::string room_id;
      const uint64_t timestamp;
      const int status;
      const std::string error;
      const std::string stack;

      NotificationResult(const notification_result* r) :
        request_id(r->request_id),
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
        n_type(r->n_type),
        room_id(r->room_id),
        timestamp(r->timestamp),
        status(r->status),
        error(r->error ? r->error : ""),
        stack(r->stack ? r->stack : "")
        {}

      NotificationResult(NotificationResult* r) :
        request_id(r->request_id),
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
        n_type(r->n_type),
        room_id(r->room_id),
        timestamp(r->timestamp),
        status(r->status),
        error(r->error),
        stack(r->stack)
        {}
  };
}

#endif