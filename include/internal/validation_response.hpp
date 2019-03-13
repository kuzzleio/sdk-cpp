#ifndef _VALIDATION_RESPONSE_HPP
#define _VALIDATION_RESPONSE_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class ValidationResponse {
    private:
        validation_response* _vr = nullptr;
        const std::vector<std::string> _details;

    public:
      ValidationResponse(validation_response* src) :
          _vr(src),
          _details(std::vector<std::string>(src->details, src->details + src->details_length))
        {};
      ValidationResponse(const ValidationResponse& src) :
          _vr(src._vr),
          _details(src._details)
        {};

      virtual inline ~ValidationResponse() { if (_vr != nullptr) kuzzle_free_validation_response(_vr); };

      const bool valid() const;

      const std::vector<std::string> &details() const;

      const char* description() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;;
  };
}

#endif