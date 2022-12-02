#include "../ConsoleColorString.hpp"

std::string ColorizeString(std::string str, ConsoleForegroundColor fColor)
{
	std::string temp = "";
	temp = "\033[" + std::to_string(fColor) + 'm';
	temp += str;
	temp += "\033[0m";

	return temp;
}

std::string ColorizeString(std::string str, ConsoleBackgroundColor bColor)
{
	std::string temp = "";
	temp = "\033[" + std::to_string(bColor) + 'm';
	temp += str;
	temp += "\033[0m";

	return temp;
}

std::string ColorizeString(std::string str, ConsoleForegroundColor fColor, ConsoleBackgroundColor bColor)
{
	std::string temp = "";
	temp = "\033[" + std::to_string(bColor) + ';' + std::to_string(fColor) + 'm';
	temp += str;
	temp += "\033[0m";

	return temp;
}

std::string UnColorizeString(std::string str)
{
	std::string temp = "";

	bool foundedInitMark = false;
	bool foundedInitMarkEnd = false;
	bool foundedFinalMark = false;
	bool foundedFinalMarkEnd = false;
	
	int IndexStart = 0;
	int IndexEnd = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (!foundedInitMark && !foundedFinalMarkEnd && !foundedFinalMark && !foundedFinalMarkEnd)
		{
			if (str[i] == '\033')
			{
				foundedInitMark = true;
			}
		}

		if (foundedInitMark && !foundedInitMarkEnd)
		{
			if (str[i] == 'm')
			{
				foundedInitMarkEnd = true;
				IndexStart = i + 1;
			}
		}

		if (foundedInitMark && foundedInitMarkEnd && !foundedFinalMark && !foundedFinalMarkEnd)
		{
			if (str[i] == '\033')
			{
				foundedFinalMark = true;
				IndexEnd = i - 1;
			}
		}

		if (foundedFinalMark && !foundedFinalMarkEnd)
		{
			if (str[i] == 'm')
			{
				foundedFinalMarkEnd = true;
			}
		}
	}

	if (foundedInitMark && foundedInitMarkEnd && foundedFinalMark && foundedFinalMarkEnd && (IndexEnd < str.size()))
	{
		for (int i = IndexStart; i <= IndexEnd; i++)
		{
			temp += str[i];
		}

		return temp;
	}
	else
	{
		//return "Fail" + std::to_string(IndexStart) + ';' + std::to_string(IndexEnd);
		return str;
	}
}