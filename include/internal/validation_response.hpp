#ifndef _VALIDATION_RESPONSE_HPP
#define _VALIDATION_RESPONSE_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class ValidationResponse {
    private:
      const bool _valid;
      const std::vector<std::string> _details;
      const std::string _description;
      const int _status;
      const std::string _error;
      const std::string _stack;

    public:
      ValidationResponse(const validation_response* u) :
        _valid(u->valid),
        _details(std::vector<std::string>(u->details, u->details + u->details_length)),
        _description(u->description),
        _status(u->status),
        _error(u->error ? u->error : ""),
        _stack(u->stack ? u->stack : "")
        {};
      ValidationResponse(const ValidationResponse& u) :
        _valid(u._valid),
        _details(u._details),
        _description(u._description),
        _status(u._status),
        _error(u._error),
        _stack(u._stack)
        {};

      const bool valid() const;

      const std::vector<std::string> &details() const;

      const std::string &description() const;

      const int status() const;

      const std::string &error() const;

      const std::string &stack() const;;
  };
}

#endif