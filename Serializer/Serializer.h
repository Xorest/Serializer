#pragma once
#include <iostream>
#include "ISerializer.h"
#include "Data.h"

using namespace std;

class Serializer : public ISerializer
{
public:
	Serializer(stringstream& stream);
	void save(Data data);
private:
	ostream& _stream;
};

