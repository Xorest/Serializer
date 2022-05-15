#pragma once
#include "ISerializer.h"

class Serializer : public virtual ISerializer
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
	Error process(bool isBool);
	template <class T>
	Error process(T&& value)
	{
		try
		{
			_stream << value << separator;
			return Error::NoError;
		}
		catch (...)
		{
			return Error::CorruptedArchive;
		}
	}
	template <class T, class... ArgsT>
	Error process(T&& value, ArgsT&&... args) 
	{
		try
		{
			_stream << value << separator;
			process(std::forward<ArgsT>(args)...);
			return Error::NoError;
		}
		catch (...)
		{
			return Error::CorruptedArchive;
		}
	}
};

