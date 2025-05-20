#include "User.hpp"

namespace nf {
	User::User(int id, const std::string& name, const std::string& login, const std::string& password) :
		id(id), name(name), login(login), password(User::hash(password)), email(), address() {

	}

	User::User(int id, const std::string& name, const std::string& login, int passwordHashed, const std::string& email, const std::string& address) :
		id(id), name(name), login(login), password(passwordHashed), email(email), address(address) {

	}

	std::string User::toString() const {
		std::string str;

		str += "{id: ";					str += std::to_string(id);			str += ", ";
		str += "name: \"";				str += name;						str += "\", ";
		str += "login: \"";				str += login;						str += "\", ";
		str += "password (hashed): \"";	str += std::to_string(password);	str += "\", ";
		str += "email: \"";				str += email;						str += "\", ";
		str += "address: \"";			str += address;						str += "\"}";

		return str;
	}

	json User::toJson() const {
		return {
			{"id", id},
			{"name", name},
			{"login", login},
			{"password (hashed)", password},
			{"email", email},
			{"address", address}
		};
	}

	User User::fromJson(const json& j) {
		return User(
			j["id"].get<int>(),
			j["name"].get<std::string>(),
			j["login"].get<std::string>(),
			j["password (hashed)"].get<int>(),
			j["email"].get<std::string>(),
			j["address"].get<std::string>()
		);
	}

	bool User::operator == (const nf::User& user) {
		return this->id == user.id;
	}

	int User::hash(const std::string& password) {
		const int X = 31, Q = 1000003;
		int passwordHashed = 0;
		for (int i = 0; i < password.size(); i++) {
			passwordHashed = (passwordHashed * X + password[i]) % Q;
		}
		return passwordHashed;
	}

	std::ostream& operator<<(std::ostream& out, const nf::User& user) {
		return out << user.toString();
	}
}