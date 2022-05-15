#pragma once
#include <sstream>

enum class Error{ NoError, CorruptedArchive };

class ISerializer 
{
public:
	ISerializer(std::stringstream& stream) : _stream(stream) {}
private:
	std::stringstream& _stream;
};