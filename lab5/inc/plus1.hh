#include <iostream>
#include <cstdlib>
#include "klasa.hh"
#include "iclock.hh"
#ifndef PLUS1_HH
#define PLUS1_HH

template <typename D>
class dodawanie                             //podklasa, dziedzicząca główną klasę 
    : public tab<D>           
                                //implementacja algorytmu zwiększania tablicy o 1 
    {
public:
    void testplus1(int max)    {
        srand(time(NULL));
        tab<D> obiekt;
        obiekt.x=10;
        obiekt.xi=(obiekt.x)+1;
            obiekt.tworzenie();
            obiekt.wypelnianie();
        while (obiekt.x<max) {
            obiekt.nowatabplus1();
            obiekt.tab1natab2();
    //        obiekt.wyswietlanie();
            obiekt.destruktor();
            obiekt.x++;
            obiekt.tworzenie();
            obiekt.tab2natab1();
            obiekt.wypelnianie_plus1();
            obiekt.nowatabplus1del();
//            obiekt.wyswietlanie();
            obiekt.xi++;
       }
        std::cout << "koniec testu algorytmu zwiększania o 1" << std::endl;
    }
};
#endif
