#ifndef _TOKEN_VALIDITY_HPP
#define _TOKEN_VALIDITY_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class TokenValidity {
    public:
      const bool valid;
      const std::string state;
      const unsigned long long expiresAt;
      const int status;
      const std::string error;
      const std::string stack;

      TokenValidity(const token_validity* u) :
        valid(u->valid),
        state(u->state),
        expiresAt(u->expires_at),
        status(u->status),
        error(u->error ? u->error : ""),
        stack(u->stack ? u->stack : "")
        {};
      TokenValidity(const TokenValidity& u) :
        valid(u.valid),
        state(u.state),
        expiresAt(u.expiresAt),
        status(u.status),
        error(u.error),
        stack(u.stack)
        {}

      const bool getValid() const;

      const std::string &getState() const;

      const unsigned long long int getExpiresAt() const;

      const int getStatus() const;

      const std::string &getError() const;

      const std::string &getStack() const;;
  };
}

#endif