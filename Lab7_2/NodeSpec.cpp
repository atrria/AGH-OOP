#include "NodeSpec.h"

int NodeInt::valInt() const
{
	return ival;
}

NodeInt* NodeInt::clone() const
{
	return new NodeInt(*this);
}

std::string NodeInt::toString() const
{
	return std::to_string(ival);
}

float NodeFloat::valFloat() const
{
	return fval;
}

NodeFloat* NodeFloat::clone() const
{
	return new NodeFloat(*this);
}

std::string NodeFloat::toString() const
{
	return std::to_string(fval);
}

std::string& NodeString::valString()
{
	return sval;
}

NodeString* NodeString::clone() const
{
	return new NodeString(*this);
}

std::string NodeString::toString() const
{
	return sval;
}