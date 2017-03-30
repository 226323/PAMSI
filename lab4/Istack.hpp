#ifndef ISTACK_HPP
#define ISTACK_HPP
#include <iostream>
using namespace std;

class Istack
{
	public:

	virtual void push(int element)=0;
	virtual void remove(int position)=0;
	virtual int size()=0;
	virtual int pop(int position)=0;
};

#endif

