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
	std::chrono::milliseconds ms;

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
		ms = duration_cast<milliseconds>(end-start);
		cout<<std::fixed<< "Czas trwania: " << ms.count() << endl;
	}

	double duration()
	{
		ms = duration_cast<milliseconds>(end-start);
		return double(ms.count());
	}

};

#endif
