#include <iostream>
#include "functions.hpp"

namespace nf
{
	void userInput(int& n) {
		std::cout << "Enter the number of circles: ";
		std::cin >> n;
	}
}