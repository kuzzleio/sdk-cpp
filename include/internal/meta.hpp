#ifndef _META_HPP
#define _META_HPP

#include <string>

namespace kuzzleio {
  class Meta {
     private:
      meta* _m = nullptr;

     public:
      Meta(meta* src) :
        _m(src)
        {};
      Meta(const Meta& src) :
        _m(src._m)
        {};

      virtual inline ~Meta() { if (_m != nullptr) kuzzle_free_meta(_m); };

      const char * author() const;

      const uint64_t createdAt() const;

      const uint64_t updatedAt() const;

      const char * updater() const;

      const bool active() const;

      const uint64_t deletedAt() const;;
  };
}

#endif