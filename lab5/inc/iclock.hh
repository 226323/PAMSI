#include <iostream>
#include <cstdlib>

#ifndef ICLOCK_HH
#define ICLOCK_HH


class iclock   {
public:
    
    clock_t start, koniec;

    void czas() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    }    


};


#endif
