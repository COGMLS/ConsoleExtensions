#pragma once

#ifndef COLORWSTRING_HPP
#define COLORWSTRING_HPP

#ifdef WIN32
	#ifdef CONSOLEEXTCOLORSTR_EXPORTS
		#define CONSOLEEXT_COLORSTR_LIB_API __declspec(dllexport)
	#else
		#define CONSOLEEXT_COLORSTR_LIB_API __declspec(dllimport)
	#endif //!CONSOLEEXTCOLORSTR_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#endif // !WIN32

#include <string>
#include "EnumColors.hpp"

/**
 * @brief Colorize wide string
 * @param wstr Wide string to be colorized
 * @param fColor Foreground color string
 * @return Colorized wide string, using ASCII code
 */
CONSOLEEXT_COLORSTR_LIB_API std::wstring ColorizeWstring(std::wstring wstr, ConsoleForegroundColor fColor);

/**
 * @brief Colorize wide string
 * @param wstr Wide string to be colorized
 * @param bColor Background color string
 * @return Colorized wide string, using ASCII code
 */
CONSOLEEXT_COLORSTR_LIB_API std::wstring ColorizeWstring(std::wstring wstr, ConsoleBackgroundColor bColor);

/**
 * @brief Colorize wide string
 * @param wstr Wide string to be colorized
 * @param fColor Foreground color string
 * @param bColor Background color string
 * @return Colorized wide string, using ASCII code
 */
CONSOLEEXT_COLORSTR_LIB_API std::wstring ColorizeWstring(std::wstring wstr, ConsoleForegroundColor fColor, ConsoleBackgroundColor bColor);

/**
 * @brief Remove the colors from a wide string (background and foreground)
 * @param wstr Wide string to be uncolonized
 * @return Return the uncolonized string if is successful, otherwise will return the same string if failed
 */
CONSOLEEXT_COLORSTR_LIB_API std::wstring UnColorizeWstring(std::wstring wstr);

#endif // !COLORWSTRING_HPP