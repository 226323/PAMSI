#ifndef Stack_HPP
#define Stack_HPP
#include <iostream>
using namespace std;
#include "iStack.hpp"
#include "Node.hpp"

class Stack : public iStack, public iRunnable
{
	Node* tail; //wskaznik na ostatni element stosu
	int size;
	string what; //typ
public:
	Stack()
	{
		tail=nullptr;
		size=0;
		what="Stack";
	}

	void add(int a)
	{
		Node * new_ = new Node; //stworzenie nowego wezla
		if (tail==nullptr)
		{        //sprawdzenie czy stos jest pusty
			tail=new_;
			new_->prev=nullptr;     //przypisanie wlasciwych wskznikow do wezla
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
		{
			a->next->prev=nullptr;
		}
		if(a->prev!=nullptr && a->next!=nullptr)
		{ //jesli a znajduje sie w srodku stosu
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==nullptr && a->prev!=nullptr)
		{  //jesli a to tail
			a->prev->next=nullptr;
			tail=a->prev;
		}
		size--;
		delete a;

	}

	void push(int a)
	{
		add(a);
	}

	void pop()
	{
		if(!size)
		{
			cout << "Nie ma nic do wyrzucenia\n";
		}
		else
		{
			remove(tail);
		}
	}

	int top()
	{
		return tail->value;
	}

	Node* find_value(int a)
	{
		while(size)
        {
			if(tail->value==a)
			{
				return tail;
			}
			pop();
		}
		cout <<"Brak szukanego elementu";
		return nullptr;
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

	void print()
	{
		Node* tmp;
		tmp=tail;
		for(int i=size; i>0; i--)
		{
			cout << tmp->value << "\n";
			tmp=tmp->prev;
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
