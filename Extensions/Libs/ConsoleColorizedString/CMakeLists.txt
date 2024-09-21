###########################################################
#
# CMakeLists: ConsoleExtColorStrings Library
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
			ConsoleExtColorStr
			VERSION 1.6.13
			DESCRIPTION "Color support for std::string and std::wstring for Console Extensions Solution."
		)

###########################################################
#
# Project components an settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ConsoleExtRoot}/Libs/<lib>")

# Define to export the library methods if is Windows:
if(WIN32)
	# Add the export here
	add_compile_definitions(CONSOLE_EXT_COLOR_STR_EXPORTS)
	add_compile_definitions(CONSOLE_EXT_COLOR_WSTR_EXPORTS)
endif()

# Define the library build properties:
if (WIN32)
	add_library(
					ConsoleExtColorStr
					SHARED
					"dllmain.hpp" "dllmain.cpp"
					"ColorString.hpp" "ColorString.cpp"
					"ColorWstring.hpp" "ColorWstring.cpp"
					"ConsoleColorString.hpp"
					"EnumColors.hpp"
				)
else()
	add_library(
					ConsoleExtColorStr
					SHARED
					"ColorString.hpp" "ColorString.cpp"
					"ColorWstring.hpp" "ColorWstring.cpp"
					"ConsoleColorString.hpp"
					"EnumColors.hpp"
				)
endif()

# If necessary, link libraries to this one:
if(DebugConsoleExtHelper)
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Debug/<libfile>.lib)
else()
	#target_link_libraries(ConsoleExtTest ${CMAKE_SOURCE_DIR}/build/Extensions/Libs/<lib>/Release/<libfile>.lib)
endif()
