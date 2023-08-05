#include <iostream>

#include "../ConsoleColorizedString/ConsoleColorString.hpp"

#define STRING_TEST
//#define WSTRING_TEST

int main()
{
	#ifdef STRING_TEST

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

	#endif // !STRING_TEST

	#ifdef WSTRING_TEST

	std::wcout << L"Starting tests with colorized wide string for consoles..." << std::endl;

	std::wstring w = ColorizeWstring(L"Wide string test", ConsoleForegroundColor::ForeBrightCyan);

	std::wcout << w << std::endl;
	std::wprintf(L"%s", w.c_str());

	std::wcout << ColorizeWstring(L"\nWide string Test 2", ConsoleForegroundColor::ForeBrightMagenta) << std::endl;
	std::wcout << ColorizeWstring(L"\nWide string Test 3", ConsoleBackgroundColor::BackBrightRed) << std::endl;
	std::wcout << ColorizeWstring(L"\nWide string Test 4", ConsoleForegroundColor::ForeBrightCyan, ConsoleBackgroundColor::BackBrightYellow) << " " << std::endl;

	std::wstring w1 = ColorizeWstring(L"\nWide string Test 5", ConsoleForegroundColor::ForeBrightGreen);
	std::wstring w2 = ColorizeWstring(L"\nWide string Test 6", ConsoleBackgroundColor::BackBlue);
	std::wstring w3 = ColorizeWstring(L"\nWide string Test 7", ConsoleForegroundColor::ForeBrightYellow, ConsoleBackgroundColor::BackGray);

	std::wcout << w1 << std::endl;
	std::wcout << w2 << std::endl;
	std::wcout << w3 << std::endl;

	std::wcout << UnColorizeWstring(w1) << std::endl;
	std::wcout << UnColorizeWstring(w2) << std::endl;
	std::wcout << UnColorizeWstring(w3) << std::endl;

	std::wcout << "End of test with wide strings" << std::endl;

	std::wcout << ColorizeWstring(L"\n\n\nPress enter to continue...", ConsoleForegroundColor::ForeRed);
	#pragma warning ( suppress : 6031 ) // Make Visual Studio ignore warning for this test
	std::getchar();

	#endif // !WSTRING_TEST

	return 0;
}