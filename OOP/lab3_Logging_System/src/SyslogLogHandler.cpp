#include "SyslogLogHandler.hpp"

#include <iostream>

namespace nf {
	void SyslogLogHandler::handle(const std::string& text) {
		std::cout << "SYSLOG LOG: " << text << std::endl;
	}
}