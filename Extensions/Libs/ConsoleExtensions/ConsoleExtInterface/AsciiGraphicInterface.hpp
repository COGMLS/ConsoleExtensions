#pragma once

#ifndef ASCII_GRAPHIC_INTERFACE_HPP
#define ASCII_GRAPHIC_INTERFACE_HPP

#ifdef WIN32
	#ifdef CONSOLE_EXTENSIONS_EXPORTS
		#define CONSOLE_EXTENSIONS_API __declspec(dllexport)
	#else
		#define CONSOLE_EXTENSIONS_API __declspec(dllimport)
	#endif //!CONSOLE_EXTENSIONS_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)

	//Remove warning C4566
	#pragma warning (disable : 4566)
#else
	#if __GNUC__ >= 4
		#ifdef CONSOLE_EXTENSIONS_EXPORTS
			#define CONSOLE_EXTENSIONS_API __attribute__((visibility("default")))
		#else
			#define CONSOLE_EXTENSIONS_API __attribute__((visibility("default")))
		#endif //!CONSOLE_EXTENSIONS_EXPORTS
	#else
		#ifdef CONSOLE_EXTENSIONS_EXPORTS
			#define CONSOLE_EXTENSIONS_API
		#else
			#define CONSOLE_EXTENSIONS_API
		#endif //!CONSOLE_EXTENSIONS_EXPORTS
	#endif
#endif // !WIN32

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

#endif // !ASCII_GRAPHIC_INTERFACE_HPP