// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _USER_RIGHT_HPP_
#define _USER_RIGHT_HPP_

#include "core.hpp"
#include <string>

namespace kuzzleio {
  class UserRight {
    private:
      const std::string _controller;
      const std::string _action;
      const std::string _index;
      const std::string _collection;
      const std::string _value;

    public:
      UserRight(const user_right* src) :
        _controller(src->controller),
        _action(src->action),
        _index(src->index),
        _collection(src->collection),
        _value(src->value)
        {};
      UserRight(const UserRight& src) :
        _controller(src._controller),
        _action(src._action),
        _index(src._index),
        _collection(src._collection),
        _value(src._value)
        {};

      const std::string &controller() const;

      const std::string &action() const;

      const std::string &index() const;

      const std::string &collection() const;

      const std::string &value() const;;
  };
}

#endif
