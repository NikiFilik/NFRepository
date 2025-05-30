#pragma once

#include "ILogHandler.hpp"

#include <string>

namespace nf {
	class ConsoleLogHandler : public ILogHandler {
	public:
		void handle(const std::string& text) override;
	};
}