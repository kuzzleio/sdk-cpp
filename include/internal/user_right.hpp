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
      std::string _controller;
      std::string _action;
      std::string _index;
      std::string _collection;
      std::string _value;

    public:
      const std::string& controller() const;
      const std::string& action() const;
      const std::string& index() const;
      const std::string& collection() const;
      const std::string& value() const;

      void controller(std::string const&);
      void action(std::string const&);
      void index(std::string const&);
      void collection(std::string const&);
      void value(std::string const&);

      UserRight() = default;
      UserRight(const user_right* r) :
        _controller(r->controller),
        _action(r->action),
        _index(r->index),
        _collection(r->collection),
        _value(r->value)
        {};
  };
}

#endif
