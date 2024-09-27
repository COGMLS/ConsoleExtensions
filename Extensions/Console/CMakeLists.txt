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
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleColorizedString")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleExtInterface")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ErrorReport")
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtensions/ConsoleExtControls")

# Define the executable properties:
add_executable(
					ConsoleExtTest
					"main.cpp"
				)

###########################################################
# WARNING: About the linking libraries for the Console:
# --------------------------------------------------------
# For some reason, the methods in the libraries are not
# recognized directly, resulting in LINK2019 with MSVC or
# "undefined referece to" in GCC, but the methods are generated
# and exported. To mitigate this problem, set as "True" the
# CMake variable "UseTargetLinkLibs" to link then manually.
###########################################################

set(UseTargetLinkLibs True)

if(UseTargetLinkLibs)
	if (WIN32)
		if(DebugConsoleExtHelper)
			#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
			target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/ConsoleExtensions.lib)
		else()
			#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
			target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/ConsoleExtensions.lib)
		endif()
	else()
		#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/bin/lib<libName>.so)
		target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/bin/libConsoleExtensions.so)
	endif()
else()
	link_libraries(ConsoleExtTest ConsoleExtensions)
endif()