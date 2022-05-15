#pragma once
#include "ISerializer.h"

class Deserializer : public virtual ISerializer
{
public:
	explicit Deserializer(std::stringstream& stream);
	template<class T>
	Error load(T& object);
};

