#pragma once

#ifndef CONSOLEEXT_HPP
#define CONSOLEEXT_HPP

#ifdef WIN32
	#ifdef CONSOLEEXTINTERFACE_EXPORTS
		#define CONSOLEEXTINTERFACE_LIB_API __declspec(dllexport)
	#else
		#define CONSOLEEXTINTERFACE_LIB_API __declspec(dllimport)
	#endif //!CONSOLEEXTINTERFACE_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#endif // !WIN32

#include <iostream>
#include <string>
#include <exception>

#define ESC "\x1B"
#define CSI ESC"["

#define SAVECURSORPOS ESC" 7"
#define RESTORECURSORPOS ESC" 8"

#define SETCURSORPOS(x,y) CSI + std::to_string(y) + ";" + std::to_string(x) + "H";

#define DONT_USE_CHARS

#ifdef DONT_USE_CHARS
	#define BORDER_TOP_LEFT_CORNER				L"\u250F"
	#define BORDER_TOP_RIGHT_CORNER				L"\u2513"
	#define BORDER_BOTTOM_LEFT_CORNER			L"\u2517"
	#define BORDER_BOTTOM_RIGHT_CORNER			L"\u251B"
	#define BORDER_LINE_HORIZONTAL				L"\u2501"
	#define BORDER_LINE_VERTICAL				L"\u2503"
	#define BORDER_CROSS_LINE					L"\u254B"
#else
	#define BORDER_TOP_LEFT_CORNER				L"/"
	#define BORDER_TOP_RIGHT_CORNER				L"\\"
	#define BORDER_BOTTOM_LEFT_CORNER			L"\\"
	#define BORDER_BOTTOM_RIGHT_CORNER			L"/"
	#define BORDER_LINE_HORIZONTAL				L"-"
	#define BORDER_LINE_VERTICAL				L"|"
	#define BORDER_CROSS_LINE					L"+"
#endif // !USE_UNICODE_CHARS

/**
 * @brief Set the console cursor's position
 * @param x Position on X-axis
 * @param y Position on Y-axis
 */
CONSOLEEXTINTERFACE_LIB_API void SetCursorPosition(int x, int y);

/**
 * @brief Draw a border in the console screen
 * @param startPosX Define the start position on X-axis
 * @param startPosY Define the start position on Y-axis
 * @param maxWidth Define the end of the border on X-axis
 * @param maxHeight Define the end of the border on Y-axis
 * @param setCursorPosX Define the cursor position after draw the border position on X-axis
 * @param setCursorPosY Define the cursor position after draw the border position on Y-axis
 * @note startPosX and startPosY need be greater than zero.
 * @note If setCursorPosX or setCursorPosY holds zero or a negative value, the cursor will be restored to last position before draw the border.
 */
CONSOLEEXTINTERFACE_LIB_API void DrawBorder(int startPosX = 1, int startPosY = 1, int maxWidth = 110, int maxHeight = 30, int setCursorPosX = 0, int setCursorPosY = 0);

/**
 * @brief Draw a horizontal line in the console screen
 * @param xStart Start position on X-axis
 * @param yStart Start position on Y-axis
 * @param count How many chars on console screen will be used to the line
 * @param useStartCrossLine Use a cross line mark
 * @param useEndCrossLine Use a end cross line mark
 */
CONSOLEEXTINTERFACE_LIB_API void DrawHorizontalLine(int xStart, int yStart, int count, bool useStartCrossLine, bool useEndCrossLine);

/**
 * @brief Draw a progress bar with a counter and the final value to be reached
 * @param progressBarXPos Define the progress bar position on X-axis
 * @param progressBarYPor Define the progress bar position on Y-axis
 * @param maxWidth Define the maximum characters will be used to progress bar and counter informations
 * @param maxValue Final value that need be reached
 * @param actualValue Actual value in progress bar. NOTE: The progress bar need be called againg to update the console informations
 */
CONSOLEEXTINTERFACE_LIB_API void DrawProgressBar(int progressBarXPos, int progressBarYPor, int maxWidth, int maxValue, int actualValue);

#endif //!CONSOLEEXT_HPP