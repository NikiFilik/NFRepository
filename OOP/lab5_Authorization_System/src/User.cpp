#include "User.hpp"

namespace nf {
	User::User(int id, const std::string& name, const std::string& login, const std::string& password) :
		id(id), name(name), login(login), password(password), email(), address() {

	}

	std::string User::toString() {
		std::string str;

		str += "{id: ";			str += std::to_string(id);	str += ", ";
		str += "name: \"";		str += name;				str += "\", ";
		str += "login: \"";		str += login;				str += "\", ";
		str += "email: \"";		str += email;				str += "\", ";
		str += "address: \"";	str += address;				str += "\"}";

		return str;
	}
}