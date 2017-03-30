#ifndef IQUEUE_HPP
#define IQUEUE_HPP
#include <iostream>
using namespace std;

class Iqueue
{
	public:

	virtual void enqueue(int element)=0;    //dodaje element na początek kolejki
	virtual void remove()=0;                //usuwa element z końca kolejki
	virtual int size()=0;                   //zwraca ilość elementów w kolejce
	virtual int dequeue()=0;                //pobiera i zwraca element z końca kolejki
};

#endif

