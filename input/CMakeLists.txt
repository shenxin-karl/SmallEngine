cmake_minimum_required(VERSION 3.8)
project(input)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("win32")
add_library(input 
	"IWindow.h"					"IkeyboardInput.h" 
	"IHandleWindowEvent.h"  	"IMouseInput.h" 
	"IWindowEventArgs.h"		"test.cpp"
	"InputSystem.h"				"InputSystem.cpp"
)

target_include_directories(input PUBLIC
	${SmallEngine_SOURCE_DIR}
)

IF (WIN32)
	SET(LINK_LIBRARY "win32input")
ENDIF()

target_link_libraries(input PRIVATE
	${LINK_LIBRARY}
)