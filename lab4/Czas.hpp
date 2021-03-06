#include <iostream>
#include "Iclock.hpp"
#include <chrono>
using namespace std::chrono;

class czas : public Iclock
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

	void time()
	{
		ns = duration_cast<nanoseconds>(end-start);
    	cout<<std::fixed<< "czas trwania: " << ns.count() << endl;
	}

	double pomiar()
	{
		ns = duration_cast<nanoseconds>(end-start);
		return double(ns.count());
	}

};
