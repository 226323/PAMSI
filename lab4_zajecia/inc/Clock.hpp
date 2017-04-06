#ifndef Clock_HPP
#define Clock_HPP
#include <chrono>
using namespace std::chrono;
#include <iostream>
#include "iClock.hpp"
class Clock : public iClock
{
    public:
	high_resolution_clock::time_point start, end;
	std::chrono::nanoseconds ns;

    void begin()
	{
    	start = high_resolution_clock::now();
    }

    void stop()
	{
    	end = high_resolution_clock::now();
    }

	void duration_out()
	{
		ns = duration_cast<nanoseconds>(end-start);
		cout<<std::fixed<< "Czas trwania: " << ns.count() << endl;
	}

	double duration()
	{
		ns = duration_cast<nanoseconds>(end-start);
		return double(ns.count());
	}

};

#endif
