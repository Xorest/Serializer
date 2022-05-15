#include <utility>
#include "Serializer.h"

Serializer::Serializer(std::stringstream& stream)
	: ISerializer(stream)
{
}

Error Serializer::process(bool value)
{
	try
	{
		_stream << (value ? "true" : "false") << separator;
		return Error::NoError;
	}
	catch(...)
	{
		return Error::CorruptedArchive;
	}
}

Error Serializer::process(uint64_t value)
{
	try
	{
		_stream << std::to_string(value) << separator;
		return Error::NoError;
	}
	catch (...) 
	{
		return Error::CorruptedArchive;
	}
}
