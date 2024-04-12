#pragma once

#ifndef COLORWSTRING_HPP
#define COLORWSTRING_HPP

#include <string>
#include "EnumColors.hpp"

/// @brief Colorize string
/// @param wstr String to be colorized
/// @param fColor Foreground color string
/// @return Colorized string, using ASCII code
std::wstring ColorizeWstring(std::wstring wstr, ConsoleForegroundColor fColor);

/// @brief Colorize string
/// @param wstr String to be colorized
/// @param bColor Background color string
/// @return Colorized string, using ASCII code
std::wstring ColorizeWstring(std::wstring wstr, ConsoleBackgroundColor bColor);

/// @brief Colorize string
/// @param wstr String to be colorized
/// @param fColor Foreground color string
/// @param bColor Background color string
/// @return Colorized string, using ASCII code
std::wstring ColorizeWstring(std::wstring wstr, ConsoleForegroundColor fColor, ConsoleBackgroundColor bColor);

/// @brief Remove the colors from a string (background and foreground)
/// @param wstr String to be uncolonized
/// @return Return the uncolonized string if is successful, otherwise will return the same string if failed
std::wstring UnColorizeWstring(std::wstring wstr);

#endif // !COLORWSTRING_HPP