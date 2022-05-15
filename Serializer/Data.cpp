#include "Data.h"

Data::Data(uint64_t a, bool b, uint64_t c)
	: _a(a),
	  _b(b),
	  _c(c)
{
}

uint64_t Data::A() const
{
	return _a;
}

bool Data::B() const
{
	return _b;
}

uint64_t Data::C() const
{
	return _c;
}
