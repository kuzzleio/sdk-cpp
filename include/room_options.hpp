// Copyright 2015-2018 Kuzzle
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _ROOM_OPTIONS_HPP_
# define _ROOM_OPTIONS_HPP_

# include "core.hpp"

extern void kuzzle_set_default_room_options(room_options*);

namespace kuzzleio {
  class RoomOptions : public room_options {
    public:
      RoomOptions() {
        kuzzle_set_default_room_options(this);
      }
  };
}

#endif // _ROOM_OPTIONS_HPP_
