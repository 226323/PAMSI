#ifndef iQueue_HPP
#define iQueue_HPP
#include <iostream>
#include "Node.hpp"
#include "iRunnable.hpp"
class iQueue
{
public:
	iQueue(){}
	virtual ~iQueue(){}
	virtual void add(int a)=0;	//dodanie elementu na koniec kolejki
	virtual int get()=0;		//pobiera wartosc z heada
	virtual int get(Node *a)=0;	//zwraca wartosc wezla nr a
	virtual int get_size()=0;	//zwraca rozmiar
	virtual Node* find_value(int a)=0;	//znajduje wartosc a
	virtual void remove(Node *a)=0;		//usuwa wezel nr a
	virtual void print()=0;		//drukuje zawartosc
	virtual bool is_empty()=0;	//sprawdza czy jest pusta
	virtual std::string type()=0;	//zwraca typ
	virtual void flush()=0;		//usuniecie listy
	virtual int end()=0;		//zwraca wartosc elementu z poczatku kolejki
	virtual void push(int a)=0;	//enqueue
	virtual void pop()=0;		//dequeue
};
#endif
