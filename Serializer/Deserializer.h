#pragma once
#include "ISerializer.h"
#include "Data.h"

using namespace std;

class Deserializer : public ISerializer
{
public:
	Deserializer(stringstream& stream);
	Error load(Data& data);
};

