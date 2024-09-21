#pragma once

#ifndef CONSOLE_EXT_GRAPHIC_INTERFACE_HPP
#define CONSOLE_EXT_GRAPHIC_INTERFACE_HPP

#ifdef WIN32
	#ifdef CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS
		#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API __declspec(dllexport)
	#else
		#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API __declspec(dllimport)
	#endif //!CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#else
	#if __GNUC__ >= 4
		#ifdef CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS
			#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API __attribute__((visibility("default")))
		#else
			#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API __attribute__((visibility("default")))
		#endif //!CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS
	#else
		#ifdef CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS
			#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API
		#else
			#define CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API
		#endif //!CONSOLE_EXT_GRAPHIC_INTERFACE_EXPORTS
	#endif
#endif // !WIN32

#include <iostream>
#include <string>

#include "ConsoleExtException.hpp"

#define ESC "\x1B"
#define ESC_W L"\x1B"

#define CSI ESC"["
#define CSI_W ESC_W L"["

#define CONSOLE_EXT_SAVE_CURSOR_POS ESC" 7"
#define CONSOLE_EXT_SAVE_CURSOR_POS_W ESC_W L" 7"

#define CONSOLE_EXT_RESTORE_CURSOR_POS ESC" 8"
#define CONSOLE_EXT_RESTORE_CURSOR_POS_W ESC_W L" 8"

#define CONSOLE_EXT_SET_CURSOR_POS(x,y) CSI + std::to_string(y) + ";" + std::to_string(x) + "H";
#define CONSOLE_EXT_SET_CURSOR_POS_W(x,y) CSI_W + std::to_wstring(y) + L";" + std::to_wstring(x) + L"H";

#define USE_UNICODE_CHARS

#ifdef USE_UNICODE_CHARS
	#define BORDER_TOP_LEFT_CORNER				"\u250F"
	#define BORDER_TOP_RIGHT_CORNER				"\u2513"
	#define BORDER_BOTTOM_LEFT_CORNER			"\u2517"
	#define BORDER_BOTTOM_RIGHT_CORNER			"\u251B"
	#define BORDER_LINE_HORIZONTAL				"\u2501"
	#define BORDER_LINE_VERTICAL				"\u2503"
	#define BORDER_CROSS_LINE					"\u254B"

	#define BORDER_TOP_LEFT_CORNER_W			L"\u250F"
	#define BORDER_TOP_RIGHT_CORNER_W			L"\u2513"
	#define BORDER_BOTTOM_LEFT_CORNER_W			L"\u2517"
	#define BORDER_BOTTOM_RIGHT_CORNER_W		L"\u251B"
	#define BORDER_LINE_HORIZONTAL_W			L"\u2501"
	#define BORDER_LINE_VERTICAL_W				L"\u2503"
	#define BORDER_CROSS_LINE_W					L"\u254B"
#else
	#define BORDER_TOP_LEFT_CORNER				"/"
	#define BORDER_TOP_RIGHT_CORNER				"\\"
	#define BORDER_BOTTOM_LEFT_CORNER			"\\"
	#define BORDER_BOTTOM_RIGHT_CORNER			"/"
	#define BORDER_LINE_HORIZONTAL				"-"
	#define BORDER_LINE_VERTICAL				"|"
	#define BORDER_CROSS_LINE					"+"

	#define BORDER_TOP_LEFT_CORNER_W			L"/"
	#define BORDER_TOP_RIGHT_CORNER_W			L"\\"
	#define BORDER_BOTTOM_LEFT_CORNER_W			L"\\"
	#define BORDER_BOTTOM_RIGHT_CORNER_W		L"/"
	#define BORDER_LINE_HORIZONTAL_W			L"-"
	#define BORDER_LINE_VERTICAL_W				L"|"
	#define BORDER_CROSS_LINE_W					L"+"
#endif // !USE_UNICODE_CHARS

namespace ConsoleExt
{
	/**
	 * @brief Set the console cursor's position
	 * @param x Position on X-axis
	 * @param y Position on Y-axis
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void SetCursorPosition(int x, int y);
	
	/**
	 * @brief Set the console cursor's position
	 * @param x Position on X-axis
	 * @param y Position on Y-axis
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void SetCursorPositionW(int x, int y);

	/**
	 * @brief Draw a border in the console screen
	 * @param startPosX Define the start position on X-axis
	 * @param startPosY Define the start position on Y-axis
	 * @param maxWidth Define the end of the border on X-axis
	 * @param maxHeight Define the end of the border on Y-axis
	 * @param CONSOLE_EXT_SET_CURSOR_POSX Define the cursor position after draw the border position on X-axis
	 * @param CONSOLE_EXT_SET_CURSOR_POSY Define the cursor position after draw the border position on Y-axis
	 * @note startPosX and startPosY need be greater than zero.
	 * @note If CONSOLE_EXT_SET_CURSOR_POSX or CONSOLE_EXT_SET_CURSOR_POSY holds zero or a negative value, the cursor will be restored to last position before draw the border.
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawBorder(int startPosX = 1, int startPosY = 1, int maxWidth = 110, int maxHeight = 30, int CONSOLE_EXT_SET_CURSOR_POSX = 0, int CONSOLE_EXT_SET_CURSOR_POSY = 0);

	/**
	 * @brief Draw a border in the console screen
	 * @param startPosX Define the start position on X-axis
	 * @param startPosY Define the start position on Y-axis
	 * @param maxWidth Define the end of the border on X-axis
	 * @param maxHeight Define the end of the border on Y-axis
	 * @param CONSOLE_EXT_SET_CURSOR_POSX Define the cursor position after draw the border position on X-axis
	 * @param CONSOLE_EXT_SET_CURSOR_POSY Define the cursor position after draw the border position on Y-axis
	 * @note startPosX and startPosY need be greater than zero.
	 * @note If CONSOLE_EXT_SET_CURSOR_POSX or CONSOLE_EXT_SET_CURSOR_POSY holds zero or a negative value, the cursor will be restored to last position before draw the border.
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawBorderW(int startPosX = 1, int startPosY = 1, int maxWidth = 110, int maxHeight = 30, int CONSOLE_EXT_SET_CURSOR_POSX = 0, int CONSOLE_EXT_SET_CURSOR_POSY = 0);

	/**
	 * @brief Draw a horizontal line in the console screen
	 * @param xStart Start position on X-axis
	 * @param yStart Start position on Y-axis
	 * @param count How many chars on console screen will be used to the line
	 * @param useStartCrossLine Use a cross line mark
	 * @param useEndCrossLine Use a end cross line mark
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawHorizontalLine(int xStart, int yStart, int count, bool useStartCrossLine, bool useEndCrossLine);

	/**
	 * @brief Draw a horizontal line in the console screen
	 * @param xStart Start position on X-axis
	 * @param yStart Start position on Y-axis
	 * @param count How many chars on console screen will be used to the line
	 * @param useStartCrossLine Use a cross line mark
	 * @param useEndCrossLine Use a end cross line mark
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawHorizontalLineW(int xStart, int yStart, int count, bool useStartCrossLine, bool useEndCrossLine);

	/**
	 * @brief Draw a progress bar with a counter and the final value to be reached
	 * @param progressBarXPos Define the progress bar position on X-axis
	 * @param progressBarYPor Define the progress bar position on Y-axis
	 * @param maxWidth Define the maximum characters will be used to progress bar and counter informations
	 * @param maxValue Final value that need be reached
	 * @param actualValue Actual value in progress bar. NOTE: The progress bar need be called again to update the console informations
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawProgressBar(int progressBarXPos, int progressBarYPor, int maxWidth, int maxValue, int actualValue);

	/**
	 * @brief Draw a progress bar with a counter and the final value to be reached
	 * @param progressBarXPos Define the progress bar position on X-axis
	 * @param progressBarYPor Define the progress bar position on Y-axis
	 * @param maxWidth Define the maximum characters will be used to progress bar and counter informations
	 * @param maxValue Final value that need be reached
	 * @param actualValue Actual value in progress bar. NOTE: The progress bar need be called again to update the console informations
	 */
	CONSOLE_EXT_GRAPHIC_INTERFACE_LIB_API void DrawProgressBarW(int progressBarXPos, int progressBarYPor, int maxWidth, int maxValue, int actualValue);
}

#endif //!CONSOLE_EXT_GRAPHIC_INTERFACE_HPP