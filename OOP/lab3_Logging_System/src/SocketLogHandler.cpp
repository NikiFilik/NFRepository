#include "SocketLogHandler.hpp"

#include <iostream>

namespace nf {
	void SocketLogHandler::handle(const std::string& text) {
		std::cout << "SOCKET LOG: " << text << std::endl;
	}
}