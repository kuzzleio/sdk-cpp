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

      TokenValidity(token_validity* src) :
        _valid(src->valid),
        _state(src->state),
        _expiresAt(src->expires_at),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        {};
      TokenValidity(const TokenValidity& src) :
        _valid(src._valid),
        _state(src._state),
        _expiresAt(src._expiresAt),
        _status(src._status),
        _error(src._error),
        _stack(src._stack)
        {};

      const bool valid() const;

      const std::string &state() const;

      const unsigned long long int expiresAt() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif