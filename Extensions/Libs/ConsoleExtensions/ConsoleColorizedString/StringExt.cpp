#include "StringExt.hpp"

std::string ConsoleExt::String::applyAsciiOptions()
{
    return std::string();
}

ConsoleExt::String::String()
{

}

ConsoleExt::String::String(std::string value)
{
	this->data = value;
}

ConsoleExt::String::String(std::string value, std::set<ConsoleExt::SgrOptions> options)
{
	this->data = value;

	for (ConsoleExt::SgrOptions option : options)
	{
		switch (option)
		{
			case ConsoleExt::SgrOptions::ResetConsole:
			default:
			{
				if (option >= ConsoleExt::SgrOptions::StandardForegroundColor && option < ConsoleExt::SgrOptions::CustomForegroundColor)
				{
					option = ConsoleExt::SgrOptions::StandardForegroundColor;
				}

				if (option >= ConsoleExt::SgrOptions::StandardBackgroundColor && option < ConsoleExt::SgrOptions::CustomBackgroundColor)
				{
					option = ConsoleExt::SgrOptions::StandardBackgroundColor;
				}

				this->options.insert(option);
				break;
			}
		}
	}
}

ConsoleExt::String::String(const ConsoleExt::String &other)
{
	this->data = other.data;
	this->options = other.options;
}

ConsoleExt::String::String(ConsoleExt::String &&other) noexcept
{
	this->data = std::move(other.data);
	this->options = std::move(other.options);
}

ConsoleExt::String::~String()
{
}

void ConsoleExt::String::setOption(ConsoleExt::SgrOptions option)
{
	if (!this->hasOption(option) && option != ConsoleExt::SgrOptions::ResetConsole)
	{
		if (option >= ConsoleExt::SgrOptions::StandardForegroundColor && option < ConsoleExt::SgrOptions::CustomForegroundColor)
		{
			option = ConsoleExt::SgrOptions::StandardForegroundColor;
		}

		if (option >= ConsoleExt::SgrOptions::StandardBackgroundColor && option < ConsoleExt::SgrOptions::CustomBackgroundColor)
		{
			option = ConsoleExt::SgrOptions::StandardBackgroundColor;
		}

		this->options.insert(option);
	}
}

bool ConsoleExt::String::hasOption(ConsoleExt::SgrOptions option)
{
	for (ConsoleExt::SgrOptions i : this->options)
	{
		if (i == option)
		{
			return true;
		}
	}

	return false;
}

void ConsoleExt::String::remOption(ConsoleExt::SgrOptions option)
{
	this->options.erase(option);
}

std::set<ConsoleExt::SgrOptions> ConsoleExt::String::getOptions()
{
    return this->options;
}

std::string ConsoleExt::String::getRawString()
{
    return this->data;
}

std::string ConsoleExt::String::getFormattedString()
{
    return std::string();
}

void ConsoleExt::String::setRawString(std::string value)
{
	this->data = value;
}

ConsoleExt::String &ConsoleExt::String::operator=(const ConsoleExt::String &other)
{
    this->data = other.data;
	this->options = other.options;
	return *this;
}

ConsoleExt::String &ConsoleExt::String::operator=(const std::string &other)
{
    this->data = other;
	return *this;
}

ConsoleExt::String &ConsoleExt::String::operator=(ConsoleExt::String &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	this->data = std::move(other.data);
	this->options = std::move(other.options);
	return *this;
}

ConsoleExt::String &ConsoleExt::String::operator=(std::string &&other) noexcept
{
    if (this->data == other)
	{
		return *this;
	}

	this->data = std::move(other);
	return *this;
}

ConsoleExt::String &ConsoleExt::String::operator+=(const ConsoleExt::String &other)
{
    this->data += other.data;
	return *this;
}

bool ConsoleExt::String::operator==(const ConsoleExt::String &other)
{
    return this->data == other.data && this->options == other.options;
}
