#include <cstdlib>
#include "node.hh"
#include "iqueue.hh"

#ifndef QUEUE_HH
#define QUEUE_HH

class queue
    : public iqueue
    {
public: 
    node* head;
    node* tail;
    int size;
    std::string what;

    queue() {
//    head=NULL;
    tail=NULL;
    size=0;
    what="kolejka";
    }

    void enqueue(int b)   {
        node * nowy = new node;

           
        if (b==1)    {


            if (tail==NULL)  {
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
        }
       

        if (b==2)    {
    
                tail->next=nowy;
                nowy->prev=tail;
                tail=nowy;
                nowy->next=NULL;
                nowy->value=rand()%10000;
    
            }
         
        size++;

    }

    void print()    {
        node* tmp;
        tmp=tail;
        for (int i=size;i>0;i--)    {
            std::cout << tmp->value << "\n";
            tmp=tmp->prev;    
        } 

    }    


    void remove()   {
        if (tail->prev==nullptr && tail->next!=nullptr)    {
            tail->next->prev=nullptr;
            //tail=tail->prev;
        }

        if (tail->prev!=nullptr && tail->next!=nullptr) {
            tail->prev->next=tail->next;
            tail->next->prev=tail->prev->prev;
        }

        if (tail->next==nullptr && tail->prev!=nullptr) {
            tail->prev->prev=nullptr;
            tail=tail->prev;
        }
    size--;
    delete tail->prev;
  //  tail->prev=tail;
    }

    node* find_value(int b)  {
        for (int i=size; i>0;i--)   {
            if (tail->value==b) {
                std::cout << "znaleziono ";
               return tail;
            }
            remove(); 
            }
        return nullptr;
       

    }



    };

#endif
