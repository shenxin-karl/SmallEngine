cmake_minimum_required(VERSION 3.8)
project(win32input)
set(CMAKE_CXX_STANDARD 20)

add_library(win32inputlib 
	"Win32Window.h"				"Win32Window.cpp"
	"Win32KeyboardInput.h"		"Win32KeyboardInput.cpp"
	"Win32WindowEventArgs.h"	"Win32WIndowEventArgs.cpp"
)

target_include_directories(win32inputlib PUBLIC
	${SmallEngine_SOURCE_DIR}
)