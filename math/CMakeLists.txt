cmake_minimum_required(VERSION 3.8)
project(math)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(math "swizzle.hpp" "vec.hpp" "VecConcept.hpp" "test.cpp")

target_include_directories(math PUBLIC
	${SmallEngine_SOURCE_DIR}/
)