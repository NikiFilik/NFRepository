#pragma once

#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

namespace nf {
	class User {
	public:
		int id;
		std::string name;
		std::string login;
		int password;
		std::string email;
		std::string address;

		User(int id, const std::string& name, const std::string& login, const std::string& password);

		std::string toString() const;

		json toJson() const;

		static User fromJson(const json& j);

		bool operator == (const nf::User& user);

	protected:
		static int hash(const std::string& password);

    private:
        User(int id, const std::string& name, const std::string& login, int passwordHashed, const std::string& email, const std::string& address);
	};

	std::ostream& operator<<(std::ostream& out, const nf::User& user);
}