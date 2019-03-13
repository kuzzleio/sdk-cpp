#ifndef _NOTIFICATION_RESULT_HPP
#define _NOTIFICATION_RESULT_HPP

#include <string>
#include "notification_content.hpp"

namespace kuzzleio {
  class NotificationResult {
    private:
      notification_result* _nr = nullptr;

    public:
      NotificationResult(notification_result* src) :
        _nr(src)
        {};

      NotificationResult(const NotificationResult& src) :
        _nr(src._nr)
        {};

      const char* requestId() const;

      const NotificationContent result() const;

      const char* volatiles() const;

      const char* index() const;

      const char* collection() const;

      const char* controller() const;

      const char* action() const;

      const char* protocol() const;

      const char* scope() const;

      const char* state() const;

      const char* user() const;

      const char* nType() const;

      const char* roomId() const;

      const uint64_t timestamp() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;
  };
}

#endif