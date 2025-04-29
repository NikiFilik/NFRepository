cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME LoggingSystem)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
	"inc/"
)

add_executable("${PROJECT_NAME}" 
	src/main.cpp

	inc/ILogFilter.hpp
	inc/SimpleLogFilter.hpp src/SimpleLogFilter.cpp
	inc/RegExpLogFilter.hpp src/RegExpLogFilter.cpp

	inc/ILogHandler.hpp
	inc/FileLogHandler.hpp src/FileLogHandler.cpp
	inc/SocketLogHandler.hpp src/SocketLogHandler.cpp
	inc/ConsoleLogHandler.hpp src/ConsoleLogHandler.cpp

	inc/Logger.hpp src/Logger.cpp
)