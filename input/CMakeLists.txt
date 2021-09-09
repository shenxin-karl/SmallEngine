cmake_minimum_required(VERSION 3.8)
project(input)
set(CMAKE_CXX_STANDARD 20)

SET(BUILD_TARGET "IWindow.h")
IF (WIN32)
	SET(BUILD_TARGET "Win32Window.h" "Win32Window.cpp")
ENDIF()

add_library(inputlib ${BUILD_TARGET})
target_include_directories(inputlib PUBLIC
	${SmallEngine_SOURCE_DIR}
)
