#pragma once

#ifndef CONSOLE_EXT_DATA_TYPES_HPP
#define CONSOLE_EXT_DATA_TYPES_HPP

#ifdef WIN32
	#ifdef CONSOLE_EXTENSIONS_EXPORTS
		#define CONSOLE_EXTENSIONS_API __declspec(dllexport)
	#else
		#define CONSOLE_EXTENSIONS_API __declspec(dllimport)
	#endif //!CONSOLE_EXTENSIONS_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
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

namespace ConsoleExt
{
	/**
	 * @brief Console Coordinates
	 */
	struct Coordinates
	{
		unsigned int x;		// Console Coordinate X
		unsigned int y;		// Console Coordinate Y
	};

	/**
	 * @brief Color Data Struct
	 */
	struct ColorData
	{
		unsigned char r;	// Color channel: Red
		unsigned char g;	// Color channel: Green
		unsigned char b;	// Color channel: Blue
	};
}

#endif // !CONSOLE_EXT_DATA_TYPES_HPP