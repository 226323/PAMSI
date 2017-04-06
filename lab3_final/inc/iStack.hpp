#ifndef iStack_HPP
#define iStack_HPP
#include <iostream>
#include "Node.hpp"
#include "iRunnable.hpp"

class iStack 
{
public:
	iStack(){}
	virtual ~iStack(){}
	virtual void add(int a)=0;	//dodanie elementu na koniec kolejki
	virtual int get()=0;		//pobiera wartosc z heada
	virtual int get(Node *a)=0;	//zwraca wartosc wezla nr a
	virtual int get_size()=0;	//zwraca rozmiar
	virtual Node* find_value(int a)=0;	//znajduje wartosc a
	virtual void remove(Node *a)=0;		//usuwa wezel nr a
	virtual void print()=0;		//drukuje zawartosc
	virtual bool is_empty()=0;	//sprawdza czy jest pusta
	virtual std::string type()=0;	//zwraca typ
	virtual void flush()=0;		//usuniecie stosu
	virtual void push(int a)=0;	//wklada wartosc na szczyt stosu
	virtual void pop()=0;		//zdejmuje wartosc ze szczytu stosu	
};
#endif
