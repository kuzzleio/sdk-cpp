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
      ValidationResponse(const validation_response* src) :
        _valid(src->valid),
        _details(std::vector<std::string>(src->details, src->details + src->details_length)),
        _description(src->description),
        _status(src->status),
        _error(src->error ? src->error : ""),
        _stack(src->stack ? src->stack : "")
        {};
      ValidationResponse(const ValidationResponse& src) :
        _valid(src._valid),
        _details(src._details),
        _description(src._description),
        _status(src._status),
        _error(src._error),
        _stack(src._stack)
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