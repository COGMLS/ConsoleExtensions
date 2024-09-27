###########################################################
#
# CMakeLists: Console Extensions Solution Library
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

project(
			ConsoleExtHelperLibs
			VERSION 0.0.1
			DESCRIPTION "Helper Solution to compile all extension libraries for Console Extensions Solution repository."
		)

###########################################################
#
# Sub projects:
#
###########################################################

add_subdirectory("ConsoleExtensions")