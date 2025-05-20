#pragma once

#ifndef CONSOLE_EXT_STRING_EXT_CLASS_HPP
#define CONSOLE_EXT_STRING_EXT_CLASS_HPP

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

#include <string>
#include <set>
#include <ostream>
#include <istream>

#include "EnumColors.hpp"

#include "AsciiControls.hpp"
#include "AsciiSGR.hpp"

namespace ConsoleExt
{
	class CONSOLE_EXTENSIONS_API String
	{
		private:

			std::string data;
			std::set<ConsoleExt::SgrOptions> options;

			std::string applyAsciiOptions();
		
		public:

			//
			// Constructors and Destructor:
			//

			String();

			String (std::string value);

			String (std::string value, std::set<ConsoleExt::SgrOptions> options);

			String (const ConsoleExt::String& other);

			String (ConsoleExt::String&& other) noexcept;

			~String();

			//
			// Options controls:
			//

			void setOption (ConsoleExt::SgrOptions option);

			bool hasOption (ConsoleExt::SgrOptions option);

			void remOption (ConsoleExt::SgrOptions option);

			std::set<ConsoleExt::SgrOptions> getOptions();

			//
			// String data methods:
			//

			std::string getRawString();

			std::string getFormattedString();

			void setRawString (std::string value);

			//
			// Operators:
			//

			ConsoleExt::String& operator= (const ConsoleExt::String& other);
			ConsoleExt::String& operator= (const std::string& other);

			ConsoleExt::String& operator= (ConsoleExt::String&& other) noexcept;
			ConsoleExt::String& operator= (std::string&& other) noexcept;

			ConsoleExt::String& operator+= (const ConsoleExt::String& other);
			
			bool operator== (const ConsoleExt::String& other);

			friend inline ConsoleExt::String operator+ (ConsoleExt::String& lhs, const ConsoleExt::String& rhs)
			{
				return lhs += rhs;
			}

			friend inline std::ostream& operator<< (std::ostream& os, const ConsoleExt::String& str)
			{
				return os;
			}

			friend inline std::istream& operator>> (std::istream& is, ConsoleExt::String& str)
			{
				return is;
			}
	};
}

#endif // !CONSOLE_EXT_STRING_EXT_CLASS_HPP