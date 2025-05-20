#pragma once

#include "IAuthService.hpp"

#include "User.hpp"
#include "IDataRepository.hpp"
#include "DataRepository.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"

namespace nf {
	class AuthService : public nf::IAuthService {
    protected:
        DataRepository<nf::User>& repository;
        std::string authFileName;
        User* currentUser = nullptr;

        void loadAuth();

        void saveAuth() const;

    public:
        AuthService(nf::DataRepository<nf::User>& repository, const std::string& authFileName);

        void signIn(const User& user) override;

        void signOut() override;

        bool isAuthorized() override;

        nf::User getCurrentUser() override;
	};
}