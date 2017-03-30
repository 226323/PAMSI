#include <iostream>
using namespace std;
#include "Istack.hpp"
#include "Iclock.hpp"
#ifndef STOS_HPP
#define STOS_HPP

#define MAX 1000

class Stack : public Istack, public Iwykonywalny
{
    int tab[MAX];
    int length;

public:

    Stack();
    ~Stack();
    void push(int element);
    void remove()=0;
    int size()=0;
    int pop()=0;
    int& operator[](int element) {return tab[element];}

    void wykonaj
};


Stack::Stack
{
    length=0;
}

Stack::~Stack
{
    delete tab[];
}

void Stack::push(int element)
{
    tab[length]=element;
    length++;
}

void Stack::remove()
{
    if(length==0)
    {
        cout<<"Brak elementów na stosie nie ma co usuwać."<<endl;
    }
    else
    {
        length--;
    }
}

int Stack::size()
{
    return length;
}

int Stack::pop()
{
    if(length==0)
    {
        cout<<"Brak elementów na stosie nie ma co pobierać."<<endl;
        return ERROR;
    }
    else
    {
        int tmp;
        tmp=tab[length];
        length--;
        return tmp;
    }
}
