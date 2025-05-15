#pragma once

#include <string>

namespace nf {
	class User {
	public:
		int id;
		std::string name;
		std::string login;
		std::string password;
		std::string email;
		std::string address;

		User(int id, const std::string& name, const std::string& login, const std::string& password);

		std::string toString();
	};
}