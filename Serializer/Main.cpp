#include <iostream>
#include <sstream>
#include <assert.h>
#include "Serializer.h"
#include "Deserializer.h"
#include "Data.h"

using namespace std;

int main()
{
    Error err = Error::NoError;
    Data x( 1, true, 2 );
    stringstream stream;
    Serializer serializer(stream);
    err = serializer.save(x);
    assert(err == Error::NoError);

    Data y( 0, false, 0 );
    Deserializer deserializer(stream);
    //err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.A() == y.A());
    assert(x.B() == y.B());
    assert(x.C() == y.C());
}
