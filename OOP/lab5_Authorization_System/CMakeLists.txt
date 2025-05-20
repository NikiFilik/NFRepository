cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME AuthorizationSystem)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
	"inc/"
	"ext/"
)

add_executable("${PROJECT_NAME}" 
	src/main.cpp

	inc/User.hpp src/User.cpp

	inc/IDataRepository.hpp

	inc/DataRepository.hpp 

	inc/IAuthService.hpp

	inc/AuthService.hpp src/AuthService.cpp

	ext/json.hpp
)

file(COPY "users.json" DESTINATION "/")
file(COPY "auth.json" DESTINATION "/")