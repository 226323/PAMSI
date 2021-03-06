#ifndef Timer_HPP
#define Timer_HPP
#include <chrono>
using namespace std::chrono;
#include <iostream>
#include "iTimer.hpp"
class Timer : public iTimer
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

	double duration()
	{
		ns = duration_cast<nanoseconds>(end-start);
		return double(ns.count());
	}

};

#endif
