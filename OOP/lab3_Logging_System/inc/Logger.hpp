#pragma once

#include "ILogFilter.hpp"
#include "ILogHandler.hpp"
#include <string>
#include <vector>

namespace nf {
    class Logger {
    private:
        std::vector<ILogFilter*> filters;
        std::vector<ILogHandler*> handlers;
    public:
        Logger(std::vector<ILogFilter*> filters, std::vector<ILogHandler*> handlers);

        void log(const std::string& text);
    };
}