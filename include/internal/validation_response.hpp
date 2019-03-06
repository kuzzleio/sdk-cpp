#ifndef _VALIDATION_RESPONSE_HPP
#define _VALIDATION_RESPONSE_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class ValidationResponse {
    public:
      const bool valid;
      const std::vector<std::string> details;
      const std::string description;
      const int status;
      const std::string error;
      const std::string stack;

      ValidationResponse(const validation_response* u) :
        valid(u->valid),
        details(std::vector<std::string>(u->details, u->details + u->details_length)),
        description(u->description),
        status(u->status),
        error(u->error ? u->error : ""),
        stack(u->stack ? u->stack : "")
        {};
      ValidationResponse(ValidationResponse* u) :
        valid(u->valid),
        details(u->details),
        description(u->description),
        status(u->status),
        error(u->error),
        stack(u->stack)
        {};
      ValidationResponse(std::shared_ptr<ValidationResponse> u) :
        valid(u->valid),
        details(u->details),
        description(u->description),
        status(u->status),
        error(u->error),
        stack(u->stack)
        {}

      const bool getValid() const;

      const std::vector<std::string> &getDetails() const;

      const std::string &getDescription() const;

      const int getStatus() const;

      const std::string &getError() const;

      const std::string &getStack() const;;
  };
}

#endif