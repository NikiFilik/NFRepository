#pragma once

#include "ILogHandler.hpp"

#include <string>

namespace nf {
	class SyslogLogHandler : public ILogHandler {
	public:
		void handle(const std::string& text) override;
	};
}