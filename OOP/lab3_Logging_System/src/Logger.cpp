#include "Logger.hpp"

namespace nf {
    Logger::Logger(std::vector<ILogFilter*> filters, std::vector<ILogHandler*> handlers) : 
        filters(filters), handlers(handlers) { }

    void Logger::log(const std::string& text) {
        bool passed = true;

        for (ILogFilter*& filter : filters) {
            if (!filter->match(text)) {
                passed = false;
                break;
            }
        }

        if (passed) {
            for (ILogHandler*& handler : handlers) {
                handler->handle(text);
            }
        }
    }
}