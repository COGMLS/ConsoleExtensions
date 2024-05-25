#include "ConsoleExtInterface.hpp"

void SetCursorPosition(int x, int y)
{
	std::string s = SETCURSORPOS(x, y);
	std::cout << s;
}

void DrawBorder(int startPosX, int startPosY, int maxWidth, int maxHeight, int setCursorPosX, int setCursorPosY)
{
	//int maxHeight = 30;
	//int maxWidth = 110;

	if (startPosX <= 0 || startPosY <= 0)
	{
		std::exception e("Start position parameter(s) is/are less than 1!");
		std::wcerr << e.what() << std::endl;
	}

	if (startPosX >= maxWidth || startPosY >= maxHeight)
	{
		std::exception e("Start position parameter(s) is/are equal to maximum value(s)!");
		std::wcerr << e.what() << std::endl;
	}

	std::wcout << SAVECURSORPOS;

	int actualCursorPosX = 0;
	int actualCursosPosY = 0;

	for (int y = startPosY; y <= maxHeight; y++)
	{
		for (int x = startPosX; x <= maxWidth; x++)
		{
			SetCursorPosition(x, y);

			// Make a complete draw on first and last console lines:
			if (y == startPosY || y == maxHeight)
			{
				if (x == startPosX && y == startPosY)
				{
					std::wcout << BORDER_TOP_LEFT_CORNER; // Top Left corner (original symbol: u250F)
				}
				else if (x == maxWidth && y == startPosY)
				{
					std::wcout << BORDER_TOP_RIGHT_CORNER;    // Top right corner (original symbol: u2513)
				}
				else if (x == startPosX && y == maxHeight)
				{
					std::wcout << BORDER_BOTTOM_LEFT_CORNER;    // Bottom left corner (original symbol: u2517)
				}
				else if (x == maxWidth && y == maxHeight)
				{
					std::wcout << BORDER_BOTTOM_RIGHT_CORNER; // Bottom right corner (original symbol: u251B)
				}
				else
				{
					std::wcout << BORDER_LINE_HORIZONTAL; // Line on top and bottom (original symbol: u2501)
				}
			}
			else
			{
				// Make a border side draw
				if (x == startPosX || x == maxWidth)
				{
					std::wcout << BORDER_LINE_VERTICAL; // Right and left column (original symbol: u2503)
				}
			}
		}
	}

	if (setCursorPosX >= 1 && setCursorPosX <= maxWidth)
	{
		actualCursorPosX = setCursorPosX;
	}

	if (setCursorPosY >= 1 && setCursorPosY <= maxHeight)
	{
		actualCursosPosY = setCursorPosY;
	}

	if (setCursorPosX >= 1 && setCursorPosY >= 1)
	{
		SetCursorPosition(actualCursorPosX, actualCursosPosY);
	}
	else
	{
		std::wcout << RESTORECURSORPOS;
	}
}

void DrawHorizontalLine(int xStart, int yStart, int count, bool useStartCrossLine, bool useEndCrossLine)
{
	if (xStart <= 0)
	{
		xStart = 1;
	}

	if (yStart <= 0)
	{
		yStart = 1;
	}

	if (count < 0)
	{
		std::exception e("Count out of range!");
		std::wcerr << e.what() << std::endl;
	}

	std::wcout << SAVECURSORPOS;

	SetCursorPosition(xStart, yStart);

	for (int i = xStart; i <= count; i++)
	{
		if (useStartCrossLine && i == xStart)
		{
			std::wcout << BORDER_CROSS_LINE;
		}
		else if (useEndCrossLine && i == count)
		{
			std::wcout << BORDER_CROSS_LINE;
		}
		else
		{
			std::wcout << BORDER_LINE_HORIZONTAL;
		}
	}

	std::wcout << RESTORECURSORPOS;
}

void DrawProgressBar(int progressBarXPos, int progressBarYPos, int maxWidth, int maxValue, int actualValue)
{
	std::wcout << SAVECURSORPOS;

	SetCursorPosition(progressBarXPos, progressBarYPos);

	// The progress bar should look like: [*****    ] | (###|###)

	std::wstring p0 = L"[";
	std::wstring p1 = L"] | (";
	std::wstring p2 = L"|";
	std::wstring p3 = L")";
	std::wstring actualValStr = std::to_wstring(actualValue);
	std::wstring maxValStr = std::to_wstring(maxValue);

	std::wstring info = p1 + actualValStr + p2 + maxValStr + p3;

	// Adapte the progress bar and progress bar informations
	int maxInfoSize = p0.size() + p1.size() + p2.size() + p3.size() + 2 * maxValStr.size(); // Use 2 maxValue to reserve the char space when actualSize is equal.

	// Progress bar chars reserved:
	int usableProgressBar = maxWidth - maxInfoSize;

	//int tmpMaxWidthUsed = maxValue + maxInfoSize;

	// Generate the progress bar proportion based on maxWidth and usableProgressBar info:

	/**
	 * maxValue (100%) = usableProgressBar
	 * 
	 * actualValue = actualValue / maxValue
	 * chars2Render = actualVar * usableProgressBar
	*/

	float valPerChar = (float)maxValue / (float)usableProgressBar;

	// Redefine the actualValue based on usableProgressBar value:

	float actualValPercent = static_cast<float>(actualValue) / static_cast<float>(maxValue);
	float chars2Render = actualValPercent * usableProgressBar;
	actualValue = static_cast<int>(chars2Render);

	// Redefine the maxValue presentation with the proportion:
	maxValue = usableProgressBar;

	// Clean the console line segment
	for (int i = (maxWidth - progressBarXPos); i < maxWidth; i++)
	{
		std::wcout << L" ";
	}

	SetCursorPosition(progressBarXPos, progressBarYPos);

	// Draw the progress bar:

	std::wcout << L"[";

	for (int i = 0; i <= maxValue; i++)
	{
		if (i <= actualValue)
		{
			std::wcout << L"\u25a0";
			//std::wprintf(L"%lc", '\u25a0');
		}
		else
		{
			std::wcout << L" ";
		}
	}

	std::wcout << info;

	std::cout << RESTORECURSORPOS;
}