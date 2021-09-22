cmake_minimum_required(VERSION 3.8)
project(container)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(container 
	"IntrusiveList.hpp" "sstd.hpp" 
	"typelist.hpp" "test.cpp"
)

target_include_directories(container PUBLIC
	${SmallEngine_SOURCE_DIR}
)

