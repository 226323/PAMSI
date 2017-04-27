#include <stack>
#include <iostream>
#include <cstdlib>
#include "node.hh"
#include "istack.hh"
#ifndef STACK_HH
#define STACK_HH


class stack   
    : public istack
    {      
public:

    node* tail;
    node* head;
    int size;
    std::string what;

    stack()    {
        tail=NULL;
        size=0;
        what="stos";
    }
    void push (int max)   {
        node * nowy = new node;

        if (tail==NULL) {
            tail=nowy;
            nowy->prev=NULL;
            nowy->next=NULL;
            nowy->value = 2137;
        }
        else    {
            tail->next=nowy;
            nowy->prev=tail;
            tail=nowy;
            nowy->next=NULL; 
            nowy->value=rand()%10000;
        }

//        nowy->value=rand();
        size++;

    }
   
    void pop(){
        
        if (tail->prev==nullptr && tail->next!=nullptr)  {
            tail->next->prev=nullptr;
//            head=tail->next;
        }

        if (tail->prev!=NULL && tail->next!=NULL) {
            tail->prev->next=tail->next;
            tail->next->prev=tail->prev;
        }
        
        if (tail->next==nullptr && tail->prev!=nullptr) {
            tail->prev->next=nullptr;
            tail=tail->prev;
        }

//      std::cout << "pop";
        size--;
//        delete tail;
    }

    void print()    {
        node* tmp;
        tmp=tail;
        for (int i=size;i>0; i--)   {
            std::cout << tmp-> value << "\n";
            tmp=tmp->prev;
         }
    }
    
    int get_size()  {
        return size;
    }



    node* find_value(int b){
	    	while(size){
		    	if(tail->value==b){
                    std::cout << "znaleziono\n";
				    return tail;
    			} 
                else {
//                    stack::print(); 
//                    std::cout <<"zmniejszanie stosu\n";
                    stack::pop();
                    size--;
                }
    		}
    		std::cout <<"\nbrak\n";
    		return nullptr;
    	}

};

#endif
