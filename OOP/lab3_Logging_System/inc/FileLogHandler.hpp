#pragma once

#include "ILogHandler.hpp"

#include <string>
#include <fstream>

namespace nf {
	class FileLogHandler : ILogHandler {
	private:
		std::ofstream out;
	public:
		FileLogHandler(const std::string filename);
		void handle(const std::string& text) override;
	};
}