#pragma once
#include "ISerializer.h"

class Deserializer : public ISerializer
{
public:
	explicit Deserializer(std::stringstream& stream);
	template<class T>
	Error load(T& object) 
	{
		return object.deserialize(*this);
	}
	template <class... ArgsT>
	Error operator()(ArgsT&... args)
	{
		return process(args...);
	}
private:
	Error process(bool& value);
	Error process(uint64_t& value);
	template <class T>
	Error process(T& value)
	{
		return Error::CorruptedArchive;
	}
	template <class T, class... ArgsT>
	Error process(T& value, ArgsT&... args)
	{
		try
		{
			process(value);
			process(args...);
			return Error::NoError;
		}
		catch (...)
		{
			return Error::CorruptedArchive;
		}
	}
};

