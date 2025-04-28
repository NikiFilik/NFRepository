#pragma once

#include "ILogFilter.hpp"

#include <string>

namespace nf {
	class SimpleLogFilter : public ILogFilter {
	private:
		std::string pattern;
	public:
		SimpleLogFilter(const std::string& pattern);

		bool match(const std::string& text) const override;
	};
}