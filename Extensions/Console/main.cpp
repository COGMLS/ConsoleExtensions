#ifdef WIN32
	#include "Windows.h"
#endif // !WIN32

#include <iostream>
#include <thread>
#include <chrono>
#include <locale>
#include "ConsoleExtInterface.hpp"
#include "ConsoleColorString.hpp"

//#define STRING_TEST
#define WSTRING_TEST

using namespace ConsoleExt;

int main (int argc, const char* argv[], const char* argp[])
{
	//std::locale loc1("en_US.utf8");
	std::locale loc2("pt_BR.utf8");
	std::locale::global(loc2);
	
	#ifdef WIN32
	SetConsoleOutputCP(65001);
	#endif // !WIN32

	int mainReturn = 0;

	DrawBorderW();
	SetCursorPositionW(5, 2);

	std::wcout << L"Project Drive Manager Console" << std::endl;

	DrawHorizontalLineW(1, 3, 110, true, true);

	DrawHorizontalLineW(1, 6, 12, true, false);
	
	SetCursorPositionW(5, 5);
	std::wcout << L"Test 1";

	DrawHorizontalLineW(6, 6, 12, false, false);

	DrawBorderW(10, 10, 50, 20);

	using namespace std::chrono_literals;

	for (int i = 0; i <= 100; i++)
	{
		DrawProgressBarW(2, 25, 50, 100, i);
		std::this_thread::sleep_for(50ms);
	}
	
	SetCursorPositionW(1, 130);

	#ifdef STRING_TEST

	std::cout << "\nStarting tests with colorized string for consoles..." << std::endl;

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

	std::wcout << L"\nStarting tests with colorized wide string for consoles..." << std::endl;

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

	return mainReturn;
}