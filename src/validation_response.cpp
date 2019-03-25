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
#include "internal/validation_response.hpp"

namespace kuzzleio {

    ValidationResponse::ValidationResponse(validation_response *src) {
        _vr = (validation_response*)malloc(sizeof(validation_response));
        _vr->valid = src->valid;
        _vr->details = NULL;
        if (src->details != NULL)
            _details = std::vector<std::string>(src->details, src->details + src->details_length);
        _vr->details_length = src->details_length;
        _vr->description = toC::dupstring(src->description);
        _vr->status = src->status;
        _vr->error = toC::dupstring(src->error);
        _vr->stack = toC::dupstring(src->stack);
    }

    const bool ValidationResponse::valid() const {
        return _vr->valid;
    }

    const std::vector<std::string>& ValidationResponse::details() const {
        return _details;
    }

    const char* ValidationResponse::description() const {
        return _vr->description;
    }

    const int ValidationResponse::status() const {
        return _vr->status;
    }

    const char* ValidationResponse::error() const {
        return _vr->error;
    }

    const char* ValidationResponse::stack() const {
        return _vr->stack;
    }

}