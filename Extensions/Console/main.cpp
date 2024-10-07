#ifdef WIN32
	#include "Windows.h"
#endif // !WIN32

#include <iostream>
#include <thread>
#include <chrono>
#include <locale>
#include "ConsoleExtInterface.hpp"
#include "ConsoleColorString.hpp"
#include "ConsoleControls.hpp"

#define STRING_TEST
//#define WSTRING_TEST

using namespace ConsoleExt;
using namespace ConsoleExt::LowLevel;

int main (int argc, const char* argv[], const char* argp[])
{
	//std::locale loc1("en_US.utf8");
	std::locale loc2("pt_BR.utf8");
	std::locale::global(loc2);
	
	#ifdef WIN32
	SetConsoleOutputCP(65001);
	#endif // !WIN32

	#ifdef WIN32
	std::system("cls");
	#else
	std::system("clear");
	#endif // !WIN32

	int mainReturn = 0;

	#ifdef STRING_TEST
	
	DrawBorder(1, 1, 110, 30, 0, 0);
	SetCursorPosition(5, 2);

	std::wcout << L"Project Drive Manager Console" << std::endl;

	DrawHorizontalLine(1, 3, 110, true, true);

	DrawHorizontalLine(1, 6, 12, true, false);
	
	SetCursorPosition(5, 5);
	std::cout << "Test 1";

	DrawHorizontalLine(6, 6, 12, false, false);

	DrawBorder(10, 10, 50, 20, 0, 0);

	ConsoleExt::LowLevel::Bell();

	using namespace std::chrono_literals;

	for (int i = 0; i <= 100; i++)
	{
		DrawProgressBar(2, 25, 50, 100, i);
		std::this_thread::sleep_for(50ms);
	}
	
	SetCursorPosition(1, 130);

	std::cout << "\nStarting tests with colorized string for consoles..." << std::endl;

	std::string t = ColorizeString("String test", ConsoleForegroundColor::ForeBrightCyan);

	std::cout << t << std::endl;
	std::printf("%s\n", t.c_str());

	std::cout << std::endl << ColorizeString("Test 2", ConsoleForegroundColor::ForeBrightMagenta) << std::endl;
	std::cout << std::endl << ColorizeString("Test 3", ConsoleBackgroundColor::BackBrightRed) << std::endl;
	std::cout << std::endl << ColorizeString("Test 4", ConsoleForegroundColor::ForeBrightCyan, ConsoleBackgroundColor::BackBrightYellow) << " new test with color string" << std::endl;

	std::string y1 = ColorizeString("Test 5", ConsoleForegroundColor::ForeBrightGreen);
	std::string y2 = ColorizeString("Test 6", ConsoleBackgroundColor::BackBlue);
	std::string y3 = ColorizeString("Test 7", ConsoleForegroundColor::ForeBrightYellow, ConsoleBackgroundColor::BackGray);

	std::cout << std::endl << y1 << std::endl;
	std::cout << std::endl << y2 << std::endl;
	std::cout << std::endl << y3 << std::endl;

	std::cout << std::endl << UnColorizeString(y1) << std::endl;
	std::cout << UnColorizeString(y2) << std::endl;
	std::cout << UnColorizeString(y3) << std::endl;

	unsigned int color = 0xe5bf1f;
	unsigned int color2 = 0xda34c0;

	t = ColorizeString("New test with custom colors", color, false);
	std::cout << std::endl<< t << std::endl;

	t = ColorizeString("New test with custom colors 2", color, true);
	std::cout << std::endl<< t << std::endl;

	t = ColorizeString("New test with custom foreground and background colors", color, color2);
	std::cout << std::endl<< t << std::endl;

	unsigned int endColor = 0xFF0000;
	unsigned int endColorB = 0xFFFFFF;

	t = ColorizeString("End of test", endColor, endColorB);
	std::cout << std::endl << t << " Last with hexadecimal colors." << std::endl;
	
	ConsoleExt::ColorData pressEnterColor;
	ConsoleExt::ColorData pressEnterColorB;

	pressEnterColor.r = 0;
	pressEnterColor.g = 0;
	pressEnterColor.b = 0;

	pressEnterColorB.r = 255;
	pressEnterColorB.g = 255;
	pressEnterColorB.b = 255;

	t = ColorizeString("Test press", pressEnterColor, pressEnterColor);
	std::cout << t << std::endl;

	t = ColorizeString("\n\n\nPress enter to continue...", ConsoleForegroundColor::ForeRed, ConsoleBackgroundColor::BackGray);
	std::cout << t;
	t = ColorizeString("Press enter to continue...", pressEnterColor, pressEnterColorB);
	std::cout << std::endl << std::endl << std::endl << t;
	#pragma warning ( suppress : 6031 ) // Make Visual Studio ignore warning for this test
	std::getchar();

	#endif // !STRING_TEST

	#ifdef WSTRING_TEST

	DrawBorderW(1, 1, 110, 30, 0, 0);
	SetCursorPositionW(5, 2);

	std::wcout << L"Project Drive Manager Console" << std::endl;

	DrawHorizontalLineW(1, 3, 110, true, true);

	DrawHorizontalLineW(1, 6, 12, true, false);
	
	SetCursorPositionW(5, 5);
	std::wcout << L"Test 1";

	DrawHorizontalLineW(6, 6, 12, false, false);

	DrawBorderW(10, 10, 50, 20, 0, 0);

	using namespace std::chrono_literals;

	for (int i = 0; i <= 100; i++)
	{
		DrawProgressBarW(2, 25, 50, 100, i);
		std::this_thread::sleep_for(50ms);
	}
	
	SetCursorPositionW(1, 130);

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