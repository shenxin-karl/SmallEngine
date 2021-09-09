cmake_minimum_required(VERSION 3.8)
project(utility)
set(CMAKE_CXX_STANDARD 20)

add_library(utilitylib STATIC
	"Time.cpp"		"CommonDeclare.h" 
	"Singleton.hpp" 
	"Image.h"		"Image.cpp" 
	"Log.h"			"Log.cpp"
)

target_include_directories(utilitylib PUBLIC
	${SmallEngine_SOURCE_DIR}/library
)