#pragma once

#ifndef COLORSTRING_HPP
#define COLORSTRING_HPP

#include <string>
#include "EnumColors.hpp"

/// @brief Colorize string
/// @param str String to be colorized
/// @param fColor Foreground color string
/// @return Colorized string, using ASCII code
std::string ColorizeString(std::string str, ConsoleForegroundColor fColor);

/// @brief Colorize string
/// @param str String to be colorized
/// @param bColor Background color string
/// @return Colorized string, using ASCII code
std::string ColorizeString(std::string str, ConsoleBackgroundColor bColor);

/// @brief Colorize string
/// @param str String to be colorized
/// @param fColor Foreground color string
/// @param bColor Background color string
/// @return Colorized string, using ASCII code
std::string ColorizeString(std::string str, ConsoleForegroundColor fColor, ConsoleBackgroundColor bColor);

/// @brief Remove the colors from a string (background and foreground)
/// @param str String to be uncolonized
/// @return Return the uncolonized string if is successful, otherwise will return the same string if failed
std::string UnColorizeString(std::string str);

#endif // !COLORSTRING_HPP