#ifndef iList_HPP
#define iList_HPP
#include <iostream>
#include "Node.hpp"
#include "List.hpp"

class iList
{
public:
	iList(){};
	virtual ~iList(){};
	virtual void add(std::string klucz,std::string wartosc)=0;	//dodanie elementu na poczatek listy
	virtual void find_key(std::string a)=0;
	virtual std::string get_value(std::string a)=0;
	virtual void remove(Node *a)=0;		//usuwa wezel nr a
	virtual void print()=0;		//drukuje zawartosc
	virtual void flush()=0;		//usuniecie listy
};
#endif
