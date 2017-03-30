#ifndef IQUEUE_HPP
#define IQUEUE_HPP
#include <iostream>
using namespace std;

class Iclock
{
    public:

    virtual void begin()=0;
    virtual void stop()=0;
    virtual void time()=0;
    virtual double pomiar()=0;
};
#endif
