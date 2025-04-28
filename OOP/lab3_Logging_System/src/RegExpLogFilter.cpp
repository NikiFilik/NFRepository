#include "RegExpLogFilter.hpp"

namespace nf {
	RegExpLogFilter::RegExpLogFilter(const std::regex& pattern) : pattern(pattern) { }

	bool RegExpLogFilter::match(const std::string& text) const {
		return std::regex_search(text, pattern);
	}
}