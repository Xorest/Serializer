#pragma once
#include <iostream>
#include <sstream>
#include "Data.h"

using namespace std;

class Serializer
{
public:
	Serializer(stringstream stream);
	void save(Data data);
};

