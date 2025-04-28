#pragma once

#include "ILogFilter.hpp"

#include <string>
#include <regex>

namespace nf {
	class RegExpLogFilter : public ILogFilter {
	private:
		std::regex pattern;
	public:
		RegExpLogFilter(const std::regex& pattern);

		bool match(const std::string& text) const override;
	};
}