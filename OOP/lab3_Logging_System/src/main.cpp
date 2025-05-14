#include "ILogFilter.hpp"
#include "ILogHandler.hpp"

#include "RegExpLogFilter.hpp"
#include "SimpleLogFilter.hpp"

#include "ConsoleLogHandler.hpp"
#include "FileLogHandler.hpp"
#include "SocketLogHandler.hpp"
#include "SyslogLogHandler.hpp"

#include "Logger.hpp"

int main() {
    nf::SimpleLogFilter errorFilter("error");
    nf::RegExpLogFilter emailFilter(std::regex("([a-zA-Z0-9_+.-]+)@([a-z-]+)\.([a-z]+)"));

    nf::ConsoleLogHandler consoleHandler;
    nf::FileLogHandler fileHandler("log.txt");
    nf::SocketLogHandler socketHandler;
    nf::SyslogLogHandler syslogHandler;

    nf::Logger logger(
        std::vector<nf::ILogFilter*> {&errorFilter, &emailFilter}, 
        std::vector<nf::ILogHandler*> {&consoleHandler, &fileHandler, &socketHandler, &syslogHandler}
    );

    logger.log("System started");
    logger.log("A critical error");
    logger.log("User test@test.com sent message");
    logger.log("User noob@test.com created an error");
    logger.log("Warning message");

	return 0;
}