#ifndef _KUZZLE_RESULT_HPP
#define _KUZZLE_RESULT_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleResponse {
    private:
      kuzzle_response* _kr = nullptr;

    public:
      KuzzleResponse(kuzzle_response* src) :
        _kr(src)
        {};
      KuzzleResponse(const KuzzleResponse& src) :
        _kr(src._kr)
        {};

      virtual inline ~KuzzleResponse() { /*if (_kr != nullptr) kuzzle_free_kuzzle_response(_kr); */};

      const char* requestId() const;

      const char* result() const;

      const char* volatiles() const;

      const char* index() const;

      const char* collection() const;

      const char* controller() const;

      const char* action() const;

      const char* roomId() const;

      const char* channel() const;

      const int status() const;

      const char* error() const;

      const char* stack() const;;
  };
}

#endif