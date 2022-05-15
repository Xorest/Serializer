#include <String>
#include "Deserializer.h"

Deserializer::Deserializer(std::stringstream& stream)
	: ISerializer(stream)
{
}

Error Deserializer::process(bool& value)
{
	std::string text;
	_stream >> text;
	if (text == "true") 
	{
		value = true;
	}
	else if (text == "false") 
	{
		value = false;
	}
	else 
	{
		return Error::CorruptedArchive;
	}

	return Error::NoError;
}

Error Deserializer::process(uint64_t& value)
{
	try 
	{
		std::string text;
		_stream >> text;
		value = std::stoi(text);
		return Error::NoError;
	}
	catch (...)
	{
		return Error::CorruptedArchive;
	}
}
