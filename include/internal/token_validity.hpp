#ifndef _TOKEN_VALIDITY_HPP
#define _TOKEN_VALIDITY_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class TokenValidity {
    public:
      const bool _valid;
      const std::string _state;
      const unsigned long long _expiresAt;
      const int _status;
      const std::string _error;
      const std::string _stack;

      TokenValidity(const token_validity* u) :
        _valid(u->valid),
        _state(u->state),
        _expiresAt(u->expires_at),
        _status(u->status),
        _error(u->error ? u->error : ""),
        _stack(u->stack ? u->stack : "")
        {};
      TokenValidity(const TokenValidity& u) :
        _valid(u._valid),
        _state(u._state),
        _expiresAt(u._expiresAt),
        _status(u._status),
        _error(u._error),
        _stack(u._stack)
        {}

      const bool valid() const;

      const std::string &state() const;

      const unsigned long long int expiresAt() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif