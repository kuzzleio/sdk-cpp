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

#include "internal/utils.hpp"

namespace kuzzleio {
    namespace toC {
        const char* dupstring(const char* s) {
            if (s == NULL)
                return NULL;
            size_t len = 0;
            for (; s[len]; len++);
            char *dest = new char[len + 1];
            dest = strcpy(dest, s);
            return dest;
        }
        char* const* vectorToC(const std::vector<std::string> &vec) {
            if (!vec.size())
                return NULL;
            char** cc = new char*[vec.size()];
            for(unsigned int i = 0; i < vec.size(); ++i)
            {
                cc[i] = new char[vec[i].size() + 1];
                strcpy(cc[i], vec[i].c_str());
            }
            return cc;
        }
    }
}