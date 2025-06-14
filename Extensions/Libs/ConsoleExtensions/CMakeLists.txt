﻿###########################################################
#
# CMakeLists: Console Extensions Unified Library
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

# Define current project base working directory location:
set(ConsoleExtLibRoot ${CMAKE_CURRENT_LIST_DIR})

# Define if is Windows Environment:

if(WIN32)
	add_compile_definitions(WIN32)
	add_compile_definitions(_WINDOWS)
	add_compile_definitions(_USRDLL)
	add_compile_definitions(_WINDLL)
endif()

if(DebugConsoleExtLib OR DebugConsoleExtHelper OR DebugSolution)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

# Defined the project:
project(
			ConsoleExtensions
			VERSION 1.0.0
			DESCRIPTION "Console Extensions Library Solution."
		)

###########################################################
#
# Project components an settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ConsoleExtLibRoot}/Libs/<lib>")
include_directories("${ConsoleExtLibRoot}")
include_directories("${ConsoleExtLibRoot}/ConsoleColorizedString")
include_directories("${ConsoleExtLibRoot}/ConsoleDataTypes")
include_directories("${ConsoleExtLibRoot}/ConsoleExtControls")
include_directories("${ConsoleExtLibRoot}/ConsoleExtInterface")
include_directories("${ConsoleExtLibRoot}/ErrorReport")

# Define to export the library methods if is Windows:
# Add the export here
add_compile_definitions(CONSOLE_EXTENSIONS_EXPORTS)

# Define the library build properties:
if (WIN32)
	add_library(
					ConsoleExtensions
					SHARED
					"dllmain.hpp" "dllmain.cpp"
					# Console Extensions Version:
					"ConsoleExtVersion.hpp"
					"ConsoleExtVersionTools.hpp"
					# Console Data Types:
					"ConsoleDataTypes/ConsoleDataTypes.hpp"
					# Console Colorized String:
					"ConsoleColorizedString/ColorString.hpp" "ConsoleColorizedString/ColorString.cpp"
					"ConsoleColorizedString/ColorWstring.hpp" "ConsoleColorizedString/ColorWstring.cpp"
					"ConsoleColorizedString/ConsoleColorString.hpp"
					"ConsoleColorizedString/EnumColors.hpp"
					"ConsoleColorizedString/StringExt.hpp" "ConsoleColorizedString/StringExt.cpp"
					"ConsoleColorizedString/StringTools.hpp" "ConsoleColorizedString/StringTools.cpp"
					# Console Ext Controls:
					"ConsoleExtControls/AsciiControls.hpp"
					"ConsoleExtControls/AsciiSGR.hpp"
					"ConsoleExtControls/ConsoleControls.hpp"
					"ConsoleExtControls/LowLevelControls.hpp" "ConsoleExtControls/LowLevelControls.cpp"
					# Console Ext Interface:
					"ConsoleExtInterface/AsciiGraphicInterface.hpp"
					"ConsoleExtInterface/ConsoleExtInterface.hpp" "ConsoleExtInterface/ConsoleExtInterface.cpp"
					# Error Report:
					"ErrorReport/ConsoleExtException.hpp"
				)
else()
	add_library(
					ConsoleExtensions
					SHARED
					# Console Extensions Version:
					"ConsoleExtVersion.hpp"
					"ConsoleExtVersionTools.hpp"
					# Console Data Types:
					"ConsoleDataTypes/ConsoleDataTypes.hpp"
					# Console Colorized String:
					"ConsoleColorizedString/ColorString.hpp" "ConsoleColorizedString/ColorString.cpp"
					"ConsoleColorizedString/ColorWstring.hpp" "ConsoleColorizedString/ColorWstring.cpp"
					"ConsoleColorizedString/ConsoleColorString.hpp"
					"ConsoleColorizedString/EnumColors.hpp"
					"ConsoleColorizedString/StringExt.hpp" "ConsoleColorizedString/StringExt.cpp"
					"ConsoleColorizedString/StringTools.hpp" "ConsoleColorizedString/StringTools.cpp"
					# Console Ext Controls:
					"ConsoleExtControls/AsciiControls.hpp"
					"ConsoleExtControls/AsciiSGR.hpp"
					"ConsoleExtControls/ConsoleControls.hpp"
					"ConsoleExtControls/LowLevelControls.hpp" "ConsoleExtControls/LowLevelControls.cpp"
					# Console Ext Interface:
					"ConsoleExtInterface/AsciiGraphicInterface.hpp"
					"ConsoleExtInterface/ConsoleExtInterface.hpp" "ConsoleExtInterface/ConsoleExtInterface.cpp"
					# Error Report:
					"ErrorReport/ConsoleExtException.hpp"
				)
endif()

