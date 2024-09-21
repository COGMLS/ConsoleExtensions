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

# Defined the project:
project(
			ConsoleExtTest
			VERSION 0.0.1
			DESCRIPTION "Console for Console Extensions Solution repository."
		)

###########################################################
#
# Project components an settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ConsoleExtRoot}/Libs/<lib>")
include_directories("${ConsoleExtRoot}/Libs/ConsoleColorizedString")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtInterface")
include_directories("${ConsoleExtRoot}/Libs/ErrorReport")

# Define the executable properties:
add_executable(
					ConsoleExtTest
					"main.cpp"
				)

#link_libraries(ConsoleExtTest ConsoleExtColorStr)
#link_libraries(ConsoleExtTest ConsoleExtInterface)


if (WIN32)
	if(DebugConsoleExtHelper)
		#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
		target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleExtInterface/Debug/ConsoleExtInterface.lib)
		target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleColorizedString/Debug/ConsoleExtColorStr.lib)
	else()
		#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
		target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleExtInterface/Release/ConsoleExtInterface.lib)
		target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleColorizedString/Release/ConsoleExtColorStr.lib)
	endif()
else()
	target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/bin/libConsoleExtInterface.so)
	target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/bin/libConsoleExtColorStr.so)
endif()
