#include "ConsoleLogHandler.hpp"

#include <iostream>

namespace nf {
	void ConsoleLogHandler::handle(const std::string& text) {
		std::cout << "CONSOLE LOG: " << text << std::endl;
	}
}