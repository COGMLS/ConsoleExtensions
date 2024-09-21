###########################################################
#
# CMakeLists: ConsoleExtInterface Library
#
###########################################################

cmake_minimum_required(VERSION 3.28)

###########################################################
#
# Define the general solution settings
#
###########################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define if is Windows Environment:

if(WIN32)
	add_compile_definitions(WIN32)
	add_compile_definitions(_WINDOWS)
	add_compile_definitions(_USRDLL)
	add_compile_definitions(_WINDLL)
endif()

if(DebugConsoleExtHelper OR DebugSolution)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

# Defined the project:
project(
			ConsoleExtInterface
			VERSION 0.0.1
			DESCRIPTION "Graphical Console Interface for Console Extensions Solution repository."
		)

###########################################################
#
# Project components an settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ConsoleExtRoot}/Libs/<lib>")
include_directories("${ConsoleExtRoot}/Libs/ErrorReport")

# Define to export the library methods if is Windows:
if(WIN32)
	# Add the export here
	add_compile_definitions(CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS)
endif()

# Define the library build properties:
if (WIN32)
	add_library(
					ConsoleExtInterface
					SHARED
					"dllmain.hpp" "dllmain.cpp"
					"ConsoleExtInterface.hpp" "ConsoleExtInterface.cpp"
				)
else()
	add_library(
					ConsoleExtInterface
					SHARED
					"ConsoleExtInterface.hpp" "ConsoleExtInterface.cpp"
				)
endif()

#link_libraries(${PROJECT_NAME} ConsoleExtErrorReport)

# If necessary, link libraries to this one:
if(DebugConsoleExtHelper)
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
else()
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
endif()
