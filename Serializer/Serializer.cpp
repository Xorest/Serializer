#include <utility>
#include "Serializer.h"

Serializer::Serializer(std::stringstream& stream)
	: ISerializer(stream)
{
}

Error Serializer::process(bool isBool)
{
	try
	{
		_stream << (isBool ? "true" : "false") << separator;
		return Error::NoError;
	}
	catch(...)
	{
		return Error::CorruptedArchive;
	}
}
