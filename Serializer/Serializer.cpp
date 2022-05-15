#include "Serializer.h"

Serializer::Serializer(stringstream& stream)
	: ISerializer(stream)
{
}

Error Serializer::save(const Data& data)
{
	return Error::NoError;
}

