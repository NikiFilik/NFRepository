cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME lab6)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
	"inc/"
	"ext/"
)

add_executable("${PROJECT_NAME}" 
	main.cpp

	inc/Editor.hpp src/Editor.cpp

	inc/Command.hpp

	inc/KeyCommand.hpp src/KeyCommand.cpp
	inc/VolumeUpCommand.hpp src/VolumeUpCommand.cpp
	inc/VolumeDownCommand.hpp src/VolumeDownCommand.cpp
	inc/MediaPlayerCommand.hpp src/MediaPlayerCommand.cpp

	inc/CommandFactory.hpp src/CommandFactory.cpp

	inc/Keyboard.hpp src/Keyboard.cpp

	inc/KeyboardStateSaver.hpp src/KeyboardStateSaver.cpp

	ext/json.hpp
)

file(COPY "output.txt" DESTINATION "/")
file(COPY "keyboardState.json" DESTINATION "/")