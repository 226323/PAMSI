#ifndef iList_HPP
#define iList_HPP
#include <iostream>
#include "Node.hpp"
#include "iRunnable.hpp"
class iList
{
public:
	iList(){};
	virtual ~iList(){};
	virtual void add(int a)=0;	//dodanie elementu na poczatek listy
	virtual int get()=0;		//pobiera wartosc z taila
	virtual int get(Node *a)=0;	//zwraca wartosc wezla nr a
	virtual int get_size()=0;	//zwraca rozmiar
	virtual Node* find_value(int a)=0;	//znajduje wartosc a
	virtual void remove(Node *a)=0;		//usuwa wezel nr a
	virtual void print()=0;		//drukuje zawartosc
	virtual bool is_empty()=0;	//sprawdza czy jest pusty
	virtual std::string type()=0;	//zwraca typ
	virtual void flush()=0;		//usuniecie listy
};
#endif 
