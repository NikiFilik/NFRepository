#include "FileLogHandler.hpp"

namespace nf {
	FileLogHandler::FileLogHandler(const std::string filename) {
		out.open(filename, std::ios::app);
	}

	void FileLogHandler::handle(const std::string& text) {
		if (out.is_open()) {
			out << text << std::endl;
		}
	}
}