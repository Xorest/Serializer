#pragma once
#include <iostream>
#include <sstream>
#include "Data.h"

using namespace std;

enum class Error { NoError };

class Deserializer
{
public:
	Deserializer(stringstream stream);
	Error load(Data& data);
};

