#include "ILogFilter.hpp"
#include "ILogHandler.hpp"

#include "RegExpLogFilter.hpp"
#include "SimpleLogFilter.hpp"

#include "ConsoleLogHandler.hpp"
#include "FileLogHandler.hpp"

#include "Logger.hpp"

int main() {
    nf::SimpleLogFilter errorFilter("error");
    nf::RegExpLogFilter criticalFilter(std::regex("critical|error"));

    nf::ConsoleLogHandler consoleHandler;
    nf::FileLogHandler fileHandler("log.txt");

    nf::Logger logger(std::vector<nf::ILogFilter*> {&errorFilter, &criticalFilter}, std::vector<nf::ILogHandler*> {&consoleHandler, &fileHandler});

    logger.log("System started");
    logger.log("A critical error");
    logger.log("An error occurred");
    logger.log("Warning message");

	return 0;
}