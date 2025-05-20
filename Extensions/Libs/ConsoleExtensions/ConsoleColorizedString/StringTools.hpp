#pragma once

#ifndef CONSOLE_EXT_STRING_TOOLS_HPP
#define CONSOLE_EXT_STRING_TOOLS_HPP

#ifdef WIN32
	#ifdef CONSOLE_EXT_COLOR_STR_EXPORTS
		#define CONSOLE_EXT_COLOR_STR_LIB_API __declspec(dllexport)
	#else
		#define CONSOLE_EXT_COLOR_STR_LIB_API __declspec(dllimport)
	#endif //!CONSOLE_EXT_COLOR_STR_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#else
	#if __GNUC__ >= 4
		#ifdef CONSOLE_EXT_COLOR_STR_EXPORTS
			#define CONSOLE_EXT_COLOR_STR_LIB_API __attribute__((visibility("default")))
		#else
			#define CONSOLE_EXT_COLOR_STR_LIB_API __attribute__((visibility("default")))
		#endif //!CONSOLE_EXT_COLOR_STR_EXPORTS
	#else
		#ifdef CONSOLE_EXT_COLOR_STR_EXPORTS
			#define CONSOLE_EXT_COLOR_STR_LIB_API
		#else
			#define CONSOLE_EXT_COLOR_STR_LIB_API
		#endif //!CONSOLE_EXT_COLOR_STR_EXPORTS
	#endif
#endif // !WIN32

#include <set>
#include <string>

#include "EnumColors.hpp"

#include "ConsoleControls.hpp"

namespace ConsoleExt
{
	CONSOLE_EXT_COLOR_STR_LIB_API std::string applyStrOptions (const std::string& str, const std::set<ConsoleExt::SgrOptions>& options);
}

#endif // !CONSOLE_EXT_STRING_TOOLS_HPP