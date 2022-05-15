#include <utility>
#include "Serializer.h"

Serializer::Serializer(std::stringstream& stream)
	: ISerializer(stream)
{
}

template<class T>
Error Serializer::save(T& object)
{
	return object.serializer(*this);
}

template<class ...ArgsT>
Error Serializer::operator()(ArgsT ...args)
{
	return process(args...);
}

Error Serializer::process(bool isBool)
{
	try
	{
		_stream << (isBool ? "true" : "false") << separator;
		return Error::NoError;
	}
	catch(...)
	{
		return Error::CorruptedArchive;
	}
}

template <class T>
Error Serializer::process(T&& value) 
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

template<class T, class ...ArgsT>
Error Serializer::process(T&& value, ArgsT&& ...args)
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


