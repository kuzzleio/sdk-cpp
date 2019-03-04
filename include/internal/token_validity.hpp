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
      const unsigned long long expires_at;
      const int status;
      const std::string error;
      const std::string stack;

      TokenValidity(const token_validity* u) :
        valid(u->valid),
        state(u->state),
        expires_at(u->expires_at),
        status(u->status),
        error(u->error ? u->error : ""),
        stack(u->stack ? u->stack : "")
        {};
      TokenValidity(TokenValidity* u) :
        valid(u->valid),
        state(u->state),
        expires_at(u->expires_at),
        status(u->status),
        error(u->error),
        stack(u->stack)
        {};
  };
}

#endif