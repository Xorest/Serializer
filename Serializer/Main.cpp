#include <iostream>
#include <sstream>
#include <assert.h>
#include "Serializer.h"
#include "Deserializer.h"

using namespace std;



int main()
{
    Data x{ 1, true, 2 };
    stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);

    Data y{ 0, false, 0 };
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}
