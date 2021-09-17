cmake_minimum_required(VERSION 3.8)
project(utility)
set(CMAKE_CXX_STANDARD 20)

add_library(utility STATIC
	"Time.cpp"		"CommonDeclare.h" 
	"Singleton.hpp"		"MemoryStatistics.hpp"
	"Image.h"			"Image.cpp" 
	"Log.h"			"Log.cpp"
	"SEngineAlloctor.hpp"
)

target_include_directories(utility PUBLIC
	${SmallEngine_SOURCE_DIR}
)