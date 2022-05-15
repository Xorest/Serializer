#pragma once
#include "ISerializer.h"

class Serializer : public virtual ISerializer
{
public:
	explicit Serializer(std::stringstream& stream);
	template <class T>
	Error save(T& object);
	template <class... ArgsT>
	Error operator()(ArgsT... args);
private:
	Error process(bool isBool);
	template <class T>
	Error process(T&& value);
	template <class T, class... ArgsT>
	Error process(T&& value, ArgsT&&... args);
};

