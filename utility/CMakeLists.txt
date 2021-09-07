cmake_minimum_required(VERSION 3.8)
project(utility)
set(CMAKE_CXX_STANDARD 20)

add_executable(utility
	"Timer.cpp" 
	"CommonDeclare.h" 
	"Singleton.hpp" 
	"Image.h" 
	 
	"Image.cpp" 
 "Log.h" "Log.cpp")

target_include_directories(utility PUBLIC
	${PROJECT_SOURCE_DIR}/../libary/stb
)