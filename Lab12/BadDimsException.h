#pragma once
#include <string>
#include <stdexcept>

struct BadDimsException : std::runtime_error
{
	BadDimsException(std::string exception): std::runtime_error(exception) {}
};
