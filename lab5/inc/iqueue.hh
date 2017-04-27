#include <iostream>

#ifndef IQUEUE_HH
#define IQUEUE_HH

class iqueue   {            //klasa iqueue

    public:
    
    virtual void enqueue(int element)=0;        //tworzenie kolejnego elementu kolejki
//    virtual void remove()=0;                    //usuwanie kolejki
//    virtual void size()=0;                      //długość kolejki
//    virtual void dequeue()=0;                   //usuwanie z kolejki, z drugiej strony
};

#endif
