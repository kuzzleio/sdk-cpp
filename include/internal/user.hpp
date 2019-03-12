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
      User() = default;

      User(const kuzzle_user* src) :
        _id(src->id),
        _content(src->content),
        _profile_ids(std::vector<std::string>(src->profile_ids, src->profile_ids + src->profile_ids_length))
        {};

      User(const User& src) :
        _id(src._id),
        _content(src._content),
        _profile_ids(src._profile_ids)
        {};

      const User& operator=(const User& src) {
          _id = src.id();
          _content = src.content();
          _profile_ids = src.profile_ids();
          return *this;
        };

      inline std::string const& id() const {
        return _id;
      }

      inline std::string const& content() const {
        return _content;
      }

      inline std::vector<std::string> const& profile_ids() const {
        return _profile_ids;
      }

      inline User& id(const std::string id) {
        _id = id;
        return *this;
      }
  };
}

#endif
