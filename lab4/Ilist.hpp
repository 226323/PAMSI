#ifndef ILIST_HPP
#define ILIST_HPP
#include <iostream>
using namespace std;

class Ilist
{
	public:

	virtual void add(int element, int position)=0;
	virtual void remove(int position)=0;
	virtual int size()=0;
	virtual int get(int position)=0;
	virtual int find(int element)=0;
};

#endif
