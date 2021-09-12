cmake_minimum_required(VERSION 3.8)
project(input)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("win32")
add_library(inputlib INTERFACE
	"IWindow.h"				"IkeyboardInput.h" 
	"IHandleWindowEvent.h"  "IMouseInput.h" 
	"IWindowEventArgs.h"
)

target_include_directories(inputlib INTERFACE
	${SmallEngine_SOURCE_DIR}
)

IF (WIN32)
	SET(LINK_LIBRARY "win32inputlib")
ENDIF()

target_link_libraries(inputlib INTERFACE
	${LINK_LIBRARY}
)