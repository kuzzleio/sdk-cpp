#ifndef _KUZZLE_USER_HPP_
#define _KUZZLE_USER_HPP_

#include <vector>
#include <string>
#include "core.hpp"

namespace kuzzleio {
  class User {
    public:
      const std::string id;
      const std::string content;
      const std::vector<std::string> profile_ids;

      User(const kuzzle_user* u) :
        id(u->id),
        content(u->content),
        profile_ids(std::vector<std::string>(u->profile_ids, u->profile_ids + u->profile_ids_length))
        {};
      User(User* u) :
        id(u->id),
        content(u->content),
        profile_ids(u->profile_ids)
        {};
  };
}

#endif
