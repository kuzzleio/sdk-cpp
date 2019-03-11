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
      const std::string controller;
      const std::string action;
      const std::string index;
      const std::string collection;
      const std::string value;

  public:
      UserRight(const user_right* r) :
        controller(r->controller),
        action(r->action),
        index(r->index),
        collection(r->collection),
        value(r->value)
        {};
      UserRight(const UserRight& r) :
        controller(r.controller),
        action(r.action),
        index(r.index),
        collection(r.collection),
        value(r.value)
        {}

      const std::string &getController() const;

      const std::string &getAction() const;

      const std::string &getIndex() const;

      const std::string &getCollection() const;

      const std::string &getValue() const;;
  };
}

#endif
