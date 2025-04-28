#include "SimpleLogFilter.hpp"

namespace nf {
	SimpleLogFilter::SimpleLogFilter(const std::string& pattern) : pattern(pattern) { }

	bool SimpleLogFilter::match(const std::string& text) const {
		return text.find(pattern) == std::string::npos;
	}
}