#ifndef ISTACK_HPP
#define ISTACK_HPP
#include <iostream>
using namespace std;

class Istack
{
	public:

	virtual void push(int element)=0;   //dodaje element na szczyt stosu
	virtual void remove()=0;            //kasuje element ze szczytu stosu
	virtual int size()=0;               //zwraca ilość elementów na stosie
	virtual int pop()=0;                //pobiera i zwraca element ze szczytu stosu
};

#endif

