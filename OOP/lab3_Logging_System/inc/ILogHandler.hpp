#pragma once

#include <string>

namespace nf {
	class ILogHandler {
	public:
		virtual void handle(const std::string& text) = 0;
	};
}