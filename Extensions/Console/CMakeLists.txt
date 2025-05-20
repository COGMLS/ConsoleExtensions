###########################################################
#
# CMakeLists: Console Extensions Example
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
endif()

if(WIN32)
	add_compile_definitions(_CONSOLE)
endif()

if(DebugConsoleExtHelper OR DebugSolution)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

set(ConsoleExtTestRoot ${CMAKE_CURRENT_LIST_DIR})

# Defined the project:
project(
			ConsoleExtTest
			VERSION 0.5.0
			DESCRIPTION "Console for Console Extensions Solution repository."
		)

###########################################################
#
# Project components an settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ConsoleExtRoot}/Libs/<lib>")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleColorizedString")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleDataTypes")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleExtControls")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleExtInterface")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ErrorReport")
#target_include_directories(ConsoleExtensions PUBLIC "${ConsoleExtRoot}/Libs/ConsoleExtensions")

# Define the executable properties:
add_executable(
					ConsoleExtTest
					"main.cpp"
				)

target_link_libraries(ConsoleExtTest ConsoleExtensions)