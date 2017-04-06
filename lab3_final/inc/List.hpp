#ifndef List_HPP
#define List_HPP
#include <iostream>
using namespace std;
#include "iList.hpp"
#include "Node.hpp"


class List : public iList, public iRunnable
{
public:
	Node *head;	//wskaznik na poczatek
	Node *tail;	//wskaznik na koniec
	int size;	//rozmiar
	string what;//typ
public:
	List()
	{
		head=nullptr;
		tail=nullptr;
		size=0;
		what = "List";
	}

	void add(int a)
	{
		Node * new_ = new Node; //stworzenie nowego wezla
		if (head==nullptr)
		{        //jesli lista jest pusta
			head=new_;
			tail=new_;
			new_->prev=nullptr;
			new_->next=nullptr;
		}
		else
		{
			tail->next=new_;
			new_->prev=tail;
			tail=new_;
			new_->next=nullptr;
		}
		new_->value=a;
		size++;
	}

	void remove(Node *a)
	{
		if(a->prev==nullptr && a->next!=nullptr)
		{	//jesli mamy do czynienia z headem
			a->next->prev=nullptr;
			head=a->next;
		}
		if(a->prev!=nullptr && a->next!=nullptr)
		{	//gdy jestesmy w srodku
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==nullptr && a->prev!=nullptr)
		{	//jesli mamy do czynienia z tailem
			a->prev->next=nullptr;
			tail=a->prev;
		}
		size--;
		delete a;
	}

	Node* find_value(int a)
	{
		Node* tmp;
		tmp=head;
		while(tmp!=nullptr)
		{ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->value==a)
			{
				return tmp;
			}
			tmp=tmp->next;
		}
		cout <<"Brak szukanego elementu";
		return nullptr;
	}

	void print()
	{
		Node* tmp;
		tmp=head;
		for(int i=0; i<size; i++)
		{
			cout<< tmp->value << "\n";
			tmp=tmp->next;
		}
	}

	int get_size()
	{
		return size;
	}

	int get()
	{
		return tail->value;
	}

	int get(Node *a)
	{
		return a->value;
	}

	bool is_empty()
	{
		if(!size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string type()
	{
		return what;
	}

	void flush()
	{
		while(size)
		{
			remove(tail);
		}
	}
};
#endif


