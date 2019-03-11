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

#ifndef _AUTH_HPP
#define _AUTH_HPP

#include <string>
#include <vector>
#include <memory>
#include "user_right.hpp"
#include "user.hpp"
#include "core.hpp"

namespace kuzzleio {
  class Kuzzle;
  class TokenValidity;

  class Auth {
    private:
      auth *_auth;
      kuzzle *_kuzzle;

    public:
      Auth(kuzzle *kuzzle);
      virtual ~Auth();

      const TokenValidity checkToken(const std::string& token) const;
      //std::shared_ptr<TokenValidity> checkToken(const std::string& token);

      std::string createMyCredentials(const std::string& strategy, const std::string& credentials);
      std::string createMyCredentials(const std::string& strategy, const std::string& credentials, const QueryOptions& options);

      bool credentialsExist(const std::string& strategy);
      bool credentialsExist(const std::string& strategy, const QueryOptions& options);

      void deleteMyCredentials(const std::string& strategy);
      void deleteMyCredentials(const std::string& strategy, const QueryOptions& options);

      User getCurrentUser();

      std::string getMyCredentials(const std::string& strategy);
      std::string getMyCredentials(const std::string& strategy, const QueryOptions& options);

      std::vector<std::shared_ptr<UserRight>> getMyRights();
      std::vector<std::shared_ptr<UserRight>> getMyRights(const QueryOptions& options);

      std::vector<std::string> getStrategies();
      std::vector<std::string> getStrategies(const QueryOptions& options);

      std::string login(const std::string& strategy, const std::string& credentials);
      std::string login(const std::string& strategy, const std::string& credentials, int expiresIn);

      void logout() noexcept;

      void setJwt(const std::string& jwt) noexcept;

      std::string updateMyCredentials(const std::string& strategy, const std::string& credentials);
      std::string updateMyCredentials(const std::string& strategy, const std::string& credentials, const QueryOptions& options);

      User updateSelf(const std::string& content);
      User updateSelf(const std::string& content, const QueryOptions& options);

      bool validateMyCredentials(const std::string& strategy, const std::string& credentials);
      bool validateMyCredentials(const std::string& strategy, const std::string& credentials, const QueryOptions& options);
  };
}

#endif
