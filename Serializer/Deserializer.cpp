#include "Deserializer.h"

Deserializer::Deserializer(std::stringstream& stream)
	: ISerializer(stream)
{
}

template<class T>
Error Deserializer::load(T& object)
{
	return Error();
}