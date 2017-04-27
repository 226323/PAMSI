#ifndef List_HPP
#define List_HPP
#include <iostream>
using namespace std;
#include <string>
#include "iList.hpp"
#include "Node.hpp"


class List : public iList
{
public:
	Node *head;	//wskaznik na poczatek
	Node *tail;	//wskaznik na koniec
	int size;	//rozmiar
public:
	List()
	{
		head=nullptr;
		tail=nullptr;
		size=0;
    }

	void add(std::string klucz,std::string wartosc)
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
		new_->key=klucz;
		new_->value=wartosc;
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

	void find_key(std::string a)
	{
		Node* tmp;
		tmp=head;
		while(tmp!=nullptr)
		{ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->key==a)
			{
				cout << "Wartosc dla klucza "<< a << " to " << tmp->value <<endl;
			}
			tmp=tmp->next;
		}
		cout <<"Brak szukanego elementu";
	}

    std::string get_value(std::string a)
	{
		Node* tmp;
		tmp=head;
		while(tmp!=nullptr)
		{ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->key==a)
			{
				return tmp->value;
			}
			tmp=tmp->next;
		}
		cout <<"Brak szukanego elementu";
	}

	void print()
	{
		Node* tmp;
		tmp=head;
		for(int i=0; i<size; i++)
		{
			cout<< "Klucz: " << tmp->key << " wartosc klucza: " << tmp->value << "\n";
			tmp=tmp->next;
		}
	}

	int get_size()
	{
		return size;
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


	void flush()
	{
		while(size)
		{
			remove(tail);
		}
	}
};
#endif


