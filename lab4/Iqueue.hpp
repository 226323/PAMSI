#ifndef IQUEUE_HPP
#define IQUEUE_HPP
#include <iostream>
using namespace std;

class Iqueue
{
	public:

	virtual void enqueue(int element)=0;
	virtual void remove()=0;
	virtual int size()=0;
	virtual int dequeue()=0;
};

#endif

