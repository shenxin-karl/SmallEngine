cmake_minimum_required(VERSION 3.8)
project(win32input)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(win32input
	"Win32Window.h"				"Win32Window.cpp"
	"Win32KeyboardInput.h"		"Win32KeyboardInput.cpp"
	"Win32WindowEventArgs.h"	"Win32WIndowEventArgs.cpp"
	"Win32MouseInput.h"	        "Win32MouseInput.cpp"
	"Win32InputSystemFactory.h"  "Win32InputSystemFactory.cpp"
)

target_include_directories(win32input PUBLIC
	${SmallEngine_SOURCE_DIR}
)