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
include_directories("${ConsoleExtRoot}/Libs/ConsoleExtControls")

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
					"AsciiGraphicInterface.hpp"
					"ConsoleExtInterface.hpp" "ConsoleExtInterface.cpp"
				)
else()
	add_library(
					ConsoleExtInterface
					SHARED
					"AsciiGraphicInterface.hpp"
					"ConsoleExtInterface.hpp" "ConsoleExtInterface.cpp"
				)
endif()

set(UseTargetLinkLibs False)

if(UseTargetLinkLibs)
	if (WIN32)
		if(DebugConsoleExtHelper)
			#target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
			target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleExtControls/Debug/ConsoleExtControls.lib)
			target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleReport/Debug/ConsoleExtReport.lib)
		else()
			#target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
			target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleExtControls/Release/ConsoleExtControls.lib)
			target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/ConsoleReport/Release/ConsoleExtReport.lib)
		endif()
	else()
		target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/bin/libConsoleExtControls.so)
		target_link_libraries(ConsoleExtInterface ${CMAKE_SOURCE_DIR}/build/bin/libConsoleExtReport.so)
	endif()
else()
	link_libraries(ConsoleExtInterface ConsoleExtControls)
	link_libraries(ConsoleExtInterface ConsoleExtErrorReport)
endif()
