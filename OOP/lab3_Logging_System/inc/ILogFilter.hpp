#pragma once

#include <string>

namespace nf {
	class ILogFilter {
	public:
		virtual bool match(const std::string& text) const = 0;

		virtual ~ILogFilter() = default;
	};
}