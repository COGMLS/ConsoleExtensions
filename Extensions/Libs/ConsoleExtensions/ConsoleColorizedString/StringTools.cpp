#include "StringTools.hpp"

CONSOLE_EXT_COLOR_STR_LIB_API std::string ConsoleExt::applyStrOptions(const std::string &str, const std::set<ConsoleExt::SgrOptions> &options)
{
	bool resetAttr = false;
	std::string tmpStr;

	if (options.size() > 0)
	{
		if (options.size() == 1 && !options.contains(ConsoleExt::SgrOptions::ResetConsole))
		{
			for (const ConsoleExt::SgrOptions& sgr : options)
			{
				switch (sgr)
				{
					case ConsoleExt::SgrOptions::CustomBackgroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::CustomForegroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::DefaultBackgroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::DefaultForegroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::DefaultUnderlineColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::FontBold:
					{
						break;
					}
					case ConsoleExt::SgrOptions::FontItalic:
					{
						break;
					}
					case ConsoleExt::SgrOptions::FontLight:
					{
						break;
					}
					case ConsoleExt::SgrOptions::FontNormalIntensity:
					{
						break;
					}
					case ConsoleExt::SgrOptions::FontUnderline:
					{
						break;
					}
					case ConsoleExt::SgrOptions::InvertColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::NoOverline:
					{
						break;
					}
					case ConsoleExt::SgrOptions::NoSuperOrSubScript:
					{
						break;
					}
					case ConsoleExt::SgrOptions::NotItalic:
					{
						break;
					}
					case ConsoleExt::SgrOptions::NotUnderlined:
					{
						break;
					}
					case ConsoleExt::SgrOptions::Overline:
					{
						break;
					}
					case ConsoleExt::SgrOptions::PrimaryFont:
					{
						break;
					}
					case ConsoleExt::SgrOptions::StandardBackgroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::StandardForegroundColor:
					{
						break;
					}
					case ConsoleExt::SgrOptions::Subscript:
					{
						break;
					}
					case ConsoleExt::SgrOptions::Superscript:
					{
						break;
					}
					case ConsoleExt::SgrOptions::UseUnderlineColor:
					{
						break;
					}
					default:
					{
						break;
					}
				}
			}
		}
	}

	tmpStr += str;

	if (resetAttr)
	{
		tmpStr += SGR(0);
	}

    return tmpStr;
}
