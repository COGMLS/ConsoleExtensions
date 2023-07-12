#include <iostream>

#include "../ConsoleColorizedString/ConsoleColorString.hpp"

int main()
{
	std::cout << "Starting tests with colorized string for consoles..." << std::endl;

	std::string t = ColorizeString("String test", ConsoleForegroundColor::ForeBrightCyan);

	std::cout << t << std::endl;
	std::printf("%s", t.c_str());

	std::cout << ColorizeString("\nTest 2", ConsoleForegroundColor::ForeBrightMagenta) << std::endl;
	std::cout << ColorizeString("\nTest 3", ConsoleBackgroundColor::BackBrightRed) << std::endl;
	std::cout << ColorizeString("\nTest 4", ConsoleForegroundColor::ForeBrightCyan, ConsoleBackgroundColor::BackBrightYellow) << " " << std::endl;

	std::string y1 = ColorizeString("\nTest 5", ConsoleForegroundColor::ForeBrightGreen);
	std::string y2 = ColorizeString("\nTest 6", ConsoleBackgroundColor::BackBlue);
	std::string y3 = ColorizeString("\nTest 7", ConsoleForegroundColor::ForeBrightYellow, ConsoleBackgroundColor::BackGray);

	std::cout << y1 << std::endl;
	std::cout << y2 << std::endl;
	std::cout << y3 << std::endl;

	std::cout << UnColorizeString(y1) << std::endl;
	std::cout << UnColorizeString(y2) << std::endl;
	std::cout << UnColorizeString(y3) << std::endl;

	std::cout << "End of test" << std::endl;

	std::cout << ColorizeString("\n\n\nPress enter to continue...", ConsoleForegroundColor::ForeRed);
	#pragma warning ( suppress : 6031 ) // Make Visual Studio ignore warning for this test
	std::getchar();

	return 0;
}