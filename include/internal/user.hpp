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

      User(kuzzle_user*);
      User();

      User& operator=(kuzzle_user* u) {
        id = u->id;
        content = u->content;

        profile_ids.clear();

        for(size_t i = 0; i < u->profile_ids_length; i++) {
          profile_ids.push_back(u->profile_ids[i]);
        }

        return *this;
      }
  };
}

#endif
