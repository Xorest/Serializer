#pragma once
//it is very big class!!!
#include <iostream>

class Data
{
public:
    Data(uint64_t a, bool b, uint64_t c);
    uint64_t A() const;
    bool B() const;
    uint64_t C() const;
    template <class Serializer>
    int serializer(Serializer& serializer);
private:
    uint64_t _a;
    bool _b;
    uint64_t _c;
};

