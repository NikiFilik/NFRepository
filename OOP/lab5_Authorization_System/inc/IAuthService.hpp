#pragma once

#include "User.hpp"

namespace nf {
	class IAuthService {
	public:
		virtual void signIn(const nf::User& user) = 0;
		virtual void signOut() = 0;
		virtual bool isAuthorized() = 0;
		virtual nf::User getCurrentUser() = 0;

		virtual ~IAuthService() = default;
	};
}