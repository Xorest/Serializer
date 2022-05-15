#include "Deserializer.h"

Deserializer::Deserializer(stringstream& stream)
	: ISerializer(stream)
{
}

Error Deserializer::load(Data& data)
{
	return Error::NoError;
}
