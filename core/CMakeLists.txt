cmake_minimum_required(VERSION 3.8)
project(core)
set(CMAKE_CXX_STANDARD 20)

add_executable(core 
	"main.cpp"				"IRuntimeMoudle.h" 
	"IApplication.h"	
	"Win32Application.cpp"	"Win32Application.h"
)

target_include_directories(core PUBLIC
	${CMAKE_PROJECT_NAME}/utility
	${SmallEngine_SOURCE_DIR}
)

target_link_libraries(core PUBLIC
	input
	utility
)


