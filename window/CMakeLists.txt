cmake_minimum_required(VERSION 3.8)
project(window)
set(CMAKE_CXX_STANDARD 20)

SET(BUILD_TARGET "IWindow.h")
IF (WIN32)
	SET(BUILD_TARGET "Win32Window.h" "Win32Window.cpp")
ENDIF()

add_executable(window ${BUILD_TARGET})
target_include_directories(window PUBLIC
	${PROJECT_SOURCE_DIR}/../utility
)