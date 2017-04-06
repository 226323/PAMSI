#ifndef Queue_HPP
#define Queue_HPP
#include <iostream>
#include "Node.hpp"
#include "iQueue.hpp"
using namespace std;

class Queue : public iQueue, public iRunnable
{
	Node *head; //wskaznik na poczatek
	Node *tail; //wskaznik na koniec
	int size;    //rozmiar
	string what; //typ
public:
	Queue()
	{
		head=nullptr;
		tail=nullptr;
		size=0;
		what="Queue";
	}

	void add(int a)
	{
		Node * new_ = new Node; //stworzenie nowego wezla
		if (!size)
		{        //sprawdzenie czy kolejka jest pusta
			head=new_;
			tail=new_;
			new_->prev=nullptr;     //przypisanie wlasciwych wskznikow do wezla
			new_->next=nullptr;
		} else
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
		{  //jesli a jest na poczatku kolejki
			a->next->prev=nullptr;
			head=a->next;
		}
		if(a->prev!=nullptr && a->next!=nullptr)
		{ //jesli a znajduje sie w srodku stosu
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==nullptr && a->prev!=nullptr)
		{  //jesli na koncu
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
			cout << "Kolejka pusta\n";
		} else
		{
			remove(head);
		}
	}

	int end()
	{
		return head->value;
	}

	Node* find_value(int a)
	{
		while(size)
		{
			if(head->value==a)
			{
				return head;
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
		return head->value;
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
		} else
		{
			return false;
		}
	}

	void print()
	{
		Node* tmp;
		tmp=head;
		for(int i=0; i<size; i++)
		{
			cout << tmp->value << "\n";
			tmp=tmp->next;
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
