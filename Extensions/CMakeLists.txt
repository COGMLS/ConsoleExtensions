###########################################################
#
# CMakeLists: Extensions Solution
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
set(ConsoleExtRoot ${CMAKE_CURRENT_LIST_DIR})

# Define if will set the project debug definition:
set(DebugConsoleExtHelper True)

# Define if is Windows Environment:

if(WIN32)
	add_compile_definitions(WIN32)
endif()

if(DebugConsoleExtHelper OR DebugSolution)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

# Define the project solution:
project(ConsoleExtensionsHelper VERSION 0.0.1 DESCRIPTION "Complete solution for Console Extensions repository.")

###########################################################
#
# Sub projects:
#
###########################################################

add_subdirectory("Libs")
add_subdirectory("Console")