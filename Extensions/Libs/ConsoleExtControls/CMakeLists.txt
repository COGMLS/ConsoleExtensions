###########################################################
#
# CMakeLists: ConsoleExtConsoleControls Library
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
			ConsoleExtControls
			VERSION 1.0.0
			DESCRIPTION "Console Controls to Console Extensions Solution."
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
	add_compile_definitions(CONSOLE_EXT_CONSOLE_CONTROLS_EXPORTS)
endif()

# Define the library build properties:
if (WIN32)
	add_library(
					ConsoleExtControls
					SHARED
					"dllmain.hpp" "dllmain.cpp"
					"AsciiControls.hpp"
					"ConsoleControls.hpp"
					"LowLevelControls.hpp" "LowLevelControls.cpp"
				)
else()
	add_library(
					ConsoleExtControls
					SHARED
					"AsciiControls.hpp"
					"ConsoleControls.hpp"
					"LowLevelControls.hpp" "LowLevelControls.cpp"
				)
endif()

link_libraries(ConsoleExtControls ConsoleExtErrorReport)

# If necessary, link libraries to this one:
if(DebugConsoleExtHelper)
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
else()
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
endif()
