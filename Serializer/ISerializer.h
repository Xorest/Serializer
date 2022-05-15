#pragma once
#include <sstream>

enum class Error{ NoError, CorruptedArchive };

class ISerializer 
{
public:
	ISerializer(std::stringstream& stream) : _stream(stream) {}
protected:
	static constexpr char separator = ' ';
	std::stringstream& _stream;
};