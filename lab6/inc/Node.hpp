#ifndef Node_HPP
#define Node_HPP
#include <iostream>
#include <string>
#include <cstdlib>

class Node
{
    public:
	Node *prev; //wskaznik na poprzedni wezel
	Node *next; //wskaznik na nastepny wezel
	std::string key;  //zawartosc wezla
	std::string value;
	Node()
	{        //konstruktor
		prev=NULL;
		next=NULL;
		key="nic";
		value="nic";
	}

	std::string get_value()
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
	friend class Map;
};

#endif
