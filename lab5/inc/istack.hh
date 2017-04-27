#include <stack>
#include <iostream>
#include "node.hh"
#include <cstdlib>

#ifndef ISTACK_HH
#define ISTACK_HH


/*struct element
    {
    int dane;
    element *nastepny;
    };

*/
class istack   
    {  
    public:                          //klasa istack
    /*node* tail;
    node* head;
    int size;
    std::string what;
*/

    //stack();
//    virtual void get(int pozycja)=0;        //pobieranie ze stosu
//    virtual int size()=0;                   //rozmiar stosu
    virtual void push(int element)=0;                   //umieszczanie nowego elementu na stosie
    virtual void pop()=0;//node* tail)=0;                    //pobieranie elementu ze stosu
    virtual int get_size()=0;
    virtual void print()=0;
    virtual node* find_value(int b)=0;
    };

 /*   istack::istack()    {
        tail=NULL;
        size=0;
        what="stos";
    } */
/*
    void istack::push (int a)   {
        node * nowy = new node;

        if (tail==NULL) {
            tail=nowy;
            nowy->prev=NULL;
            nowy->next=NULL;
        }
        else    {
            tail->next=nowy;
            nowy->prev=tail;
            tail=nowy;
            nowy->next=NULL; 
        }

        nowy->value=a;
        size++;

    }
    
    void istack::pop(node *a)   {
        
        if (a->prev==nullptr && a->next!=nullptr)  {
            a->next->prev=nullptr;
            head=a->next;
        }
   
        if (a->prev!=NULL && a->next!=NULL) {
            a->prev->next=a->next;
            a->next->prev=a->prev;
        }

        size --;
        delete a;
    }

    void istack::print()    {
        node* tmp;
        tmp=tail;

        for (int i=size;i>0; i--)   {
            std::cout << tmp-> value << "\n";
            tmp=tmp->prev;
        }
    }

    int istack::get_size()  {
        return size;
    }
*/
/*
    void push(element **S) {
        element *temp = new element;
        std::cin >> temp -> dane;
        temp->nastepny=*S;
        *S=temp;
    }

    int pop(element *S) {
        element *temp;
        if (S!=NULL) {
            return S->dane;
        }
    }

*/
/*
class klasa_czas        //ponieważ czas mierzyłem bez tworzenia dodatkowej klasy czas nie póki co tworzę pustą klasę, na którą później przeniosę mierzenie czasu wykonywania algorytmu
                        
{
};

class stack 
    : public istack, klasa_czas
    {
    public:    
    void get(int pozycja)=0;        //pobieranie ze stosu
    int size()=0;                   //rozmiar stosu
    void push(int element)=0;                   //umieszczanie nowego elementu na stosie
    int pop(int pozycja)=0;                    //pobieranie elementu ze stosu
    

    void push(element **S) {
        element *temp = new element;
        std::cin >> temp -> dane;
        temp->nastepny=*S;
        *S=temp;
    }

    int pop(element *S) {
        element *temp;
        if (S!=NULL) {
            return S->dane;
        }
    }
   

                    

    };*/

//tak, podzielę to wszystko na moduły ale na labach chciałem mieć to w jednym pliku, by mieć wszystko obok i wiedzieć co do czego

/*
irunable

istack czasy push pop size

stack z istack ma brać metody 
mierzenie czasu
istack, by dziedziczył po iclocku

stack wykonaj

dom:
implementacja stos kolejka lista
zmierzenie czasu operacji find ("ma mieć tyletam elementów") na samym końcu i w losowym miejscu

O(n)
=/=O(1)
=/=O(n^2)
10^9
*/


#endif
