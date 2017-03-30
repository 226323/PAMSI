#ifndef IQUEUE_HPP
#define IQUEUE_HPP
#include <iostream>
using namespace std;

class Iqueue
{
	public:

	virtual void enqueue(int element)=0;
	virtual void remove(int position)=0;
	virtual int size()=0;
	virtual int dequeue(int position)=0;
};

#endif

