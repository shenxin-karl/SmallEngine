cmake_minimum_required(VERSION 3.8)
project(input)
set(CMAKE_CXX_STANDARD 20)

SET(BUILD_TARGET "IWindow.h" "IkeyboardInput.h" "IHandleWindowEvent.h" "IMouseInput.h")
IF (WIN32)
	SET(BUILD_TARGET "win32/Win32Window.h"			"win32/Win32Window.cpp")
	SET(BUILD_TARGET "win32/Win32KeyboardInput.h"	"win32/Win32KeyboardInput.cpp")
	SET(BUILD_TARGET "win32/Win32WindowEventArgs.h" "win32/Win32WIndowEventArgs.cpp")
ENDIF()

add_library(inputlib ${BUILD_TARGET})
target_include_directories(inputlib PUBLIC
	${SmallEngine_SOURCE_DIR}
)
