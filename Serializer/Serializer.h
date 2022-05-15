#pragma once
#include "ISerializer.h"

class Serializer : public ISerializer
{
public:
	explicit Serializer(std::stringstream& stream);
	template <class T>
	Error save(T& object)
	{
		return object.serialize(*this);
	}
	template <class... ArgsT>
	Error operator()(ArgsT... args)
	{
		return process(args...);
	}
private:
	static constexpr char separator = ' ';
	Error process(bool value);
	Error process(uint64_t value);
	template <class T>
	Error process(T&& value)
	{
		return Error::CorruptedArchive;
	}
	template <class T, class... ArgsT>
	Error process(T&& value, ArgsT&&... args) 
	{
		try
		{
			process(value);
			process(std::forward<ArgsT>(args)...);
			return Error::NoError;
		}
		catch (...)
		{
			return Error::CorruptedArchive;
		}
	}
};

