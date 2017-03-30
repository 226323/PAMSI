#ifndef ILIST_HPP
#define ILIST_HPP
#include <iostream>
using namespace std;

class Ilist
{
	public:

	virtual void add(int element, int position)=0;  //dodaje element na wskazanej pozycji
	virtual void remove(int position)=0;            //usuwa element ze wskazanej pozycji
	virtual int size()=0;                           //zwraca ilość elementów listy
	virtual int get(int position)=0;                //pobiera i zwraca wartość elementu ze wskazanej pozycji
	virtual int find(int element)=0;                //znajduje element o podanej wartości i zwraca jego pozycję
};

#endif
