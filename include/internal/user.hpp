#ifndef _KUZZLE_USER_HPP_
#define _KUZZLE_USER_HPP_

#include <vector>
#include <string>
#include "core.hpp"

namespace kuzzleio {
  class User {
    private:
      std::string _id;
      std::string _content;
      std::vector<std::string> _profile_ids;

    public:
      std::string const& id() const;
      std::string const& content() const;
      std::vector<std::string> const& profile_ids() const;

      User(const kuzzle_user* u) :
        _id(u->id),
        _content(u->content),
        _profile_ids(std::vector<std::string>(u->profile_ids, u->profile_ids + u->profile_ids_length))
        {};
      User() = default;
      User& operator=(const kuzzle_user*);
  };
}

#endif
