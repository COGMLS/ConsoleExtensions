#pragma once

#ifndef CONSOLE_EXT_VERSION_TOOLS_HPP
#define CONSOLE_EXT_VERSION_TOOLS_HPP

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

#include "ConsoleExtVersion.hpp"
#include <string>
#include <cstring>

/**
 * @brief Console Extensions
 */
namespace ConsoleExt
{
	/**
	 * @brief Console Extensions Version number
	 */
	struct Version
	{
		unsigned int major;
		unsigned int minor;
		unsigned int patch;
		unsigned int revision;
		unsigned long long build;
		char* type;
	};

	/**
	 * @brief Get the Console Extensions Library version
	 * @return Return a Version struct
	 */
	CONSOLE_EXTENSIONS_API inline ConsoleExt::Version getLibVersion()
	{
		Version v;
		v.major = CONSOLE_EXT_MAJOR_VERSION;
		v.minor = CONSOLE_EXT_MINOR_VERSION;
		v.patch = CONSOLE_EXT_PATCH_VERSION;
		v.revision = CONSOLE_EXT_REVISION_NUMBER;
		v.build = CONSOLE_EXT_BUILD_NUMBER;
		v.type = new char[std::strlen(CONSOLE_EXT_BUILD_TYPE)];
		std::strcpy(v.type, CONSOLE_EXT_BUILD_TYPE);
		return v;
	}

	/**
	 * @brief Transform the struct Version into a string version
	 * @param version Console Extensions Version struct
	 * @param showBuild Show the build number.
	 * @param showType Show the build type.
	 * @return Return a string version.
	 */
	CONSOLE_EXTENSIONS_API inline std::string getVersionStr (ConsoleExt::Version version, bool showBuild, bool showType)
	{
		std::string s;
		s = std::to_string(version.major) + "." + std::to_string(version.minor) + "." + std::to_string(version.patch);

		if (showType && !(std::strcmp(version.type, "release") == 0 || std::strcmp(version.type, "RELEASE") == 0))
		{
			s += "-" + std::string(version.type);
		}

		if (version.revision > 0)
		{
			s += "." + std::to_string(version.revision);
		}

		if (showBuild)
		{
			s += " build " + std::to_string(version.build);
		}

		return s;
	}
}

#endif // !CONSOLE_EXT_VERSION_TOOLS_HPP