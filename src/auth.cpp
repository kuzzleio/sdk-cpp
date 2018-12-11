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

#include "kuzzle.hpp"
#include "internal/auth.hpp"

namespace kuzzleio {
  Auth::Auth(Kuzzle *kuzzle) {
      _auth = new auth();
      _kuzzle = kuzzle;
      kuzzle_new_auth(_auth, kuzzle->_kuzzle);
  }

  Auth::Auth(Kuzzle *kuzzle, auth *auth) {
    _auth = auth;
    _kuzzle = kuzzle;
    kuzzle_new_auth(_auth, kuzzle->_kuzzle);
  }

  Auth::~Auth() {
      unregisterAuth(_auth);
      delete(_auth);
  }

  token_validity* Auth::checkToken(const std::string& token) {
    return kuzzle_check_token(_auth, const_cast<char*>(token.c_str()));
  }

  std::string Auth::createMyCredentials(const std::string& strategy, const std::string& credentials, query_options* options) {
    KUZZLE_API(string_result, r, kuzzle_create_my_credentials(_auth, const_cast<char*>(strategy.c_str()), const_cast<char*>(credentials.c_str()), options))

    std::string ret = r->result;

    kuzzle_free_string_result(r);
    return ret;
  }

  bool Auth::credentialsExist(const std::string& strategy, query_options *options) {
    KUZZLE_API(bool_result, r, kuzzle_credentials_exist(_auth, const_cast<char*>(strategy.c_str()), options))

    bool ret = r->result;
    kuzzle_free_bool_result(r);
    return ret;
  }

  void Auth::deleteMyCredentials(const std::string& strategy, query_options *options) {
    KUZZLE_API(error_result, r, kuzzle_delete_my_credentials(_auth, const_cast<char*>(strategy.c_str()), options))
    kuzzle_free_error_result(r);
  }

  kuzzle_user* Auth::getCurrentUser() {
    KUZZLE_API(user_result, r, kuzzle_get_current_user(_auth))

    kuzzle_user *u = r->result;
    kuzzle_free_user_result(r);
    return u;
  }

  std::string Auth::getMyCredentials(const std::string& strategy, query_options *options) {
    KUZZLE_API(string_result, r, kuzzle_get_my_credentials(_auth, const_cast<char*>(strategy.c_str()), options))

    std::string ret = r->result;
    kuzzle_free_string_result(r);
    return ret;
  }

  std::vector<UserRight> Auth::getMyRights(query_options* options) {
    KUZZLE_API(user_rights_result, r, kuzzle_get_my_rights(_auth, options))

    std::vector<UserRight> user_rights;

    for (size_t i = 0; i < r->rights_length; ++i) {
      user_rights.push_back(UserRight(r->rights[i]));
    }

    kuzzle_free_user_rights_result(r);
    return user_rights;
  }

  std::vector<std::string> Auth::getStrategies(query_options *options) {
    KUZZLE_API(string_array_result, r, kuzzle_get_strategies(_auth, options))

    std::vector<std::string> strategies = std::vector<std::string>(r->result, r->result + r->result_length);

    kuzzle_free_string_array_result(r);
    return strategies;
  }

  std::string Auth::login(const std::string& strategy, const std::string& credentials) {
    KUZZLE_API(string_result, r, kuzzle_login(_auth, const_cast<char*>(strategy.c_str()), const_cast<char*>(credentials.c_str()), nullptr))

    std::string ret = r->result;
    kuzzle_free_string_result(r);
    return ret;
  }

  std::string Auth::login(const std::string& strategy, const std::string& credentials, int expires_in) {
    KUZZLE_API(string_result, r, kuzzle_login(_auth, const_cast<char*>(strategy.c_str()), const_cast<char*>(credentials.c_str()), &expires_in))

    std::string ret = r->result;
    kuzzle_free_string_result(r);
    return ret;
  }

  void Auth::logout() noexcept {
    kuzzle_logout(_auth);
  }

  void Auth::setJwt(const std::string& jwt) noexcept {
    kuzzle_set_jwt(_kuzzle->_kuzzle, const_cast<char*>(jwt.c_str()));
  }

  std::string Auth::updateMyCredentials(const std::string& strategy, const std::string& credentials, query_options *options) {
    KUZZLE_API(string_result, r, kuzzle_update_my_credentials(_auth, const_cast<char*>(strategy.c_str()), const_cast<char*>(credentials.c_str()), options))

    std::string ret = r->result;
    kuzzle_free_string_result(r);
    return ret;
  }

  kuzzle_user* Auth::updateSelf(const std::string& content, query_options* options) {
    KUZZLE_API(user_result, r, kuzzle_update_self(_auth, const_cast<char*>(content.c_str()), options))

    kuzzle_user *ret = r->result;
    kuzzle_free_user_result(r);
    return ret;
  }

  bool Auth::validateMyCredentials(const std::string& strategy, const std::string& credentials, query_options* options) {
    KUZZLE_API(bool_result, r, kuzzle_validate_my_credentials(_auth, const_cast<char*>(strategy.c_str()), const_cast<char*>(credentials.c_str()), options))

    bool ret = r->result;
    kuzzle_free_bool_result(r);
    return ret;
  }
}
