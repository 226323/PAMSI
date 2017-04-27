#include <cstdlib>
#include "node.hh"
#include "ilist.hh"

#ifndef LIST_HH
#define LIST_HH

class list
    : public ilist
    {
    public:

        node* head;
        node* tail;
        int size;
        std::string what;

        
        list()  {
//        head=NULL;
        tail=NULL;
        size=0;
        what="lista";
        }



        void add (int max)  {
        
            node * nowy = new node;
        
            if  (tail==NULL)    {
                tail=nowy;
                nowy->prev=NULL;
                nowy->next=NULL;
                nowy->value=2137;
            }
            else    {
                tail->next=nowy;
                nowy->prev=tail;
                tail=nowy;
                nowy->next=NULL;
                nowy->value=rand()%10000;
            }

        size++;
        
    }


    void remove()   {

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

    }

    void print()    {
        node* tmp;
        tmp=tail;
        for (int i=size;i>0;i--)    {
            std::cout << tmp-> value << "\n";
            tmp=tmp->prev;
        }
    }


    node* find_value(int b) {
        node* tmp;
        tmp=tail;
//        while (!=NULL)    {
        for (int i=size; i>0;i--)   {
            if (tmp->value==b)   {
            std::cout << "znaleziono \n";        
            return tmp;

            }

            else    {
            //    std::cout << i << "\n";
                tmp=tmp->prev;
            }     
//            return tmp;
            
//            head=head->next;
        }

        std::cout << "nie znaleziono ";
        return nullptr;
    }



};

 




#endif
