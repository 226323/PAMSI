#include <iostream>

#ifndef NODE_HH
#define NODE_HH


class node   {           

    public:
    node *prev;
    node *next;
    int value;

    node()  {
        prev=NULL;
        next=NULL;
        value=0;
    }

    int get_value() {
        return value;
    }

    friend class ilist;
    friend class iqueue;
    friend class istack;

};

#endif
