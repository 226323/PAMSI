#ifndef iTree_HPP
#define iTree_HPP
#include <iostream>
#include "Lisc.hpp"
#include "Drzewo.hpp"

class iTree
{
public:
	iTree(){}; //konstruktor
    virtual ~iTree(){};    //destruktor
    virtual bool is_empty() const=0;    //sprawdzanie czy drzewo jest puste
    virtual void insert(int x)=0;       //dokładanie wartości do drzewa
    virtual int search(int x)=0;        //wyszukiwanie wartosci w drzewie
    virtual void flush()=0;             //wyczyszczenie drzewa - zostanie sam korzen
    virtual void print()=0;             //wyswietlenie drzewa
};
#endif
