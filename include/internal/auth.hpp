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

namespace kuzzleio
{
class Kuzzle;

class Auth
{
private:
  auth *_auth;
  kuzzle *_kuzzle;

public:
  Auth(kuzzle *kuzzle);
  virtual ~Auth();

  token_validity *checkToken(const std::string &token);

  std::string createMyCredentials(const std::string &strategy, const std::string &credentials);
  std::string createMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options);

  bool credentialsExist(const std::string &strategy);
  bool credentialsExist(const std::string &strategy, const query_options &options);

  void deleteMyCredentials(const std::string &strategy);
  void deleteMyCredentials(const std::string &strategy, const query_options &options);

  User currentUser();

  std::string myCredentials(const std::string &strategy);
  std::string myCredentials(const std::string &strategy, const query_options &options);

  std::vector<std::shared_ptr<UserRight>> myRights();
  std::vector<std::shared_ptr<UserRight>> myRights(const query_options &options);

  std::vector<std::string> strategies();
  std::vector<std::string> strategies(const query_options &options);

  std::string login(const std::string &strategy, const std::string &credentials);
  std::string login(const std::string &strategy, const std::string &credentials, int expiresIn);

  void logout() noexcept;

  void setJwt(const std::string &jwt) noexcept;

  std::string updateMyCredentials(const std::string &strategy, const std::string &credentials);
  std::string updateMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options);

  User updateSelf(const std::string &content);
  User updateSelf(const std::string &content, const query_options &options);

  bool validateMyCredentials(const std::string &strategy, const std::string &credentials);
  bool validateMyCredentials(const std::string &strategy, const std::string &credentials, const query_options &options);
};
} // namespace kuzzleio

#endif
