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

#include "kuzzle.hpp"
#include "internal/user_right.hpp"

namespace kuzzleio {
  std::string const& UserRight::controller() const {
    return _controller;
  }

  std::string const& UserRight::action() const {
    return _action;
  }

  std::string const& UserRight::index() const {
    return _index;
  }

  std::string const& UserRight::collection() const {
    return _collection;
  }

  std::string const& UserRight::value() const {
    return _value;
  }

  void UserRight::controller(std::string const& value) {
    this->_controller = value;
  }

  void UserRight::action(std::string const& value) {
    this->_action = value;
  }

  void UserRight::collection(std::string const& value) {
    this->_collection = value;
  }

  void UserRight::index(std::string const& value) {
    this->_index = value;
  }

  void UserRight::value(std::string const& value) {
    this->_value = value;
  }
}
