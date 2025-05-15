#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "User.hpp"

int main() {
	nf::User user(0, "Nikita", "NikiFilik", "PASSWORD");
	std::cout << user.toString();
	return 0;
}
