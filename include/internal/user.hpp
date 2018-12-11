#ifndef _KUZZLE_USER_HPP_
#define _KUZZLE_USER_HPP_

#include <vector>
#include <string>
#include "core.hpp"

namespace kuzzleio {
  class User {
    public:
      std::string id;
      std::string content;
      std::vector<std::string> profile_ids;

      User(const kuzzle_user*);
      User() = default;
      User& operator=(const kuzzle_user*);
  };
}

#endif
