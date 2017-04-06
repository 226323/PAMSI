#ifndef Node_HPP
#define Node_HPP
#include <iostream>

class Node 
{
	Node *prev; //wskaznik na poprzedni wezel
	Node *next; //wskaznik na nastepny wezel
	int value;  //zawartosc wezla
public:
	Node()
	{        //konstruktor
		prev=NULL;
		next=NULL;
		value=0;
	}

	int get_value()
	{
		return value;
	}

	Node* get_next()
	{
		return next;
	}

	Node* get_prev()
	{
		return prev;
	}
	friend class List; 
	friend class Queue;
	friend class Stack;
};

#endif
