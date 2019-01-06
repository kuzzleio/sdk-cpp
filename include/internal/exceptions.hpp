// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#define PARTIAL_EXCEPTION 206
#define BAD_REQUEST_EXCEPTION 400
#define UNAUTHORIZED_EXCEPTION 401
#define FORBIDDEN_EXCEPTION 403
#define NOT_FOUND_EXCEPTION 404
#define PRECONDITION_EXCEPTION 412
#define SIZE_LIMIT_EXCEPTION 413
#define INTERNAL_EXCEPTION 500
#define SERVICE_UNAVAILABLE_EXCEPTION 503
#define GATEWAY_TIMEOUT_EXCEPTION 504

namespace kuzzleio {

  class KuzzleException : public std::runtime_error {
    private:
      const int _status;

    public:
      KuzzleException(const std::string& message)
        : KuzzleException(500, message)
        {};

      KuzzleException(int status, const std::string& error)
        : std::runtime_error(error),
          _status(status)
        {};

      KuzzleException(const KuzzleException& ke)
      : _status(ke.status()),
        std::runtime_error(ke.getMessage()) {};

      virtual ~KuzzleException() throw() {};

      std::string getMessage() const {
        return what();
      };

      int status() const {
        return _status;
      };

  };

  class BadRequestException : public KuzzleException {
    public:
      BadRequestException(const std::string& message="Bad Request Exception")
        : KuzzleException(BAD_REQUEST_EXCEPTION, message) {};
      BadRequestException(const BadRequestException& bre) : KuzzleException(bre.status(), bre.getMessage()) {}
  };
  class ForbiddenException: public KuzzleException {
    public:
      ForbiddenException(const std::string& message="Forbidden Exception")
        : KuzzleException(FORBIDDEN_EXCEPTION, message) {};
      ForbiddenException(const ForbiddenException& fe) : KuzzleException(fe.status(), fe.getMessage()) {}
  };
  class GatewayTimeoutException: public KuzzleException {
    public:
      GatewayTimeoutException(const std::string& message="Gateway Timeout Exception")
        : KuzzleException(GATEWAY_TIMEOUT_EXCEPTION, message) {};
      GatewayTimeoutException(const GatewayTimeoutException& gte) : KuzzleException(gte.status(), gte.getMessage()) {}
  };
  class InternalException: public KuzzleException {
    public:
      InternalException(const std::string& message="Internal Exception")
        : KuzzleException(INTERNAL_EXCEPTION, message) {};
      InternalException(const InternalException& ie) : KuzzleException(ie.status(), ie.getMessage()) {}
  };
  class NotFoundException: public KuzzleException {
    public:
      NotFoundException(const std::string& message="Not Found Exception")
        : KuzzleException(NOT_FOUND_EXCEPTION, message) {};
      NotFoundException(const NotFoundException& nfe) : KuzzleException(nfe.status(), nfe.getMessage()) {}
  };
  class PartialException: public KuzzleException {
    public:
      PartialException(const std::string& message="Partial Exception")
        : KuzzleException(PARTIAL_EXCEPTION, message) {};
      PartialException(const PartialException& pe) : KuzzleException(pe.status(), pe.getMessage()) {}
  };
  class PreconditionException: public KuzzleException {
    public:
      PreconditionException(const std::string& message="Precondition Exception")
        : KuzzleException(PRECONDITION_EXCEPTION, message) {};
      PreconditionException(const PreconditionException& pe) : KuzzleException(pe.status(), pe.getMessage()) {}
  };
  class ServiceUnavailableException: public KuzzleException {
    public:
      ServiceUnavailableException(const std::string& message="Service Unavailable Exception")
        : KuzzleException(SERVICE_UNAVAILABLE_EXCEPTION, message) {};
      ServiceUnavailableException(const ServiceUnavailableException& sue) : KuzzleException(sue.status(), sue.getMessage()) {}
  };
  class SizeLimitException: public KuzzleException {
    public:
      SizeLimitException(const std::string& message="Size Limit Exception")
        : KuzzleException(SIZE_LIMIT_EXCEPTION, message) {};
      SizeLimitException(const SizeLimitException& sle) : KuzzleException(sle.status(), sle.getMessage()) {}
  };
  class UnauthorizedException : public KuzzleException {
    public:
      UnauthorizedException(const std::string& message="Unauthorized Exception")
      : KuzzleException(UNAUTHORIZED_EXCEPTION, message) {}
      UnauthorizedException(const UnauthorizedException& ue) : KuzzleException(ue.status(), ue.getMessage()) {}
  };

  static void throwKuzzleException(int status, const std::string& error) {
    switch(status) {
      case PARTIAL_EXCEPTION:
        throw PartialException(error);
      break;
      case BAD_REQUEST_EXCEPTION:
        throw BadRequestException(error);
      break;
      case UNAUTHORIZED_EXCEPTION:
        throw UnauthorizedException(error);
      break;
      case FORBIDDEN_EXCEPTION:
        throw ForbiddenException(error);
      break;
      case NOT_FOUND_EXCEPTION:
        throw NotFoundException(error);
      break;
      case PRECONDITION_EXCEPTION:
        throw PreconditionException(error);
      break;
      case SIZE_LIMIT_EXCEPTION:
        throw SizeLimitException(error);
      break;
      case INTERNAL_EXCEPTION:
        throw InternalException(error);
      break;
      case SERVICE_UNAVAILABLE_EXCEPTION:
        throw ServiceUnavailableException(error);
      break;
      case GATEWAY_TIMEOUT_EXCEPTION:
        throw GatewayTimeoutException(error);
      break;
      default:
        throw KuzzleException(500, error);
    }
  }
}

#endif
