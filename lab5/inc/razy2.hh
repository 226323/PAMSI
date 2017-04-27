#include <iostream>
#include <cstdlib>
#include "klasa.hh"

#ifndef RAZY2_HH
#define RAZY2_HH

template <typename M>
class mnozenie                  //podklasa, dziedzicząca główną klasę
    : public tab<M>             
    {
public:
    void testrazy2(int max) {       //implementacja algorytmu zwiększającego tablicę razy dwa
        srand(time(NULL));
        tab<M> obiekt;
        obiekt.x=10;
        obiekt.xm=(obiekt.x)*2;
        
        obiekt.tworzenie();
        obiekt.wypelnianie();

        while (obiekt.x<max) {
            obiekt.nowatabx2();
            obiekt.tab1natab2x();
            obiekt.destruktor();
            obiekt.x=(obiekt.x)*2;
            obiekt.tworzenie();
            obiekt.tab2xnatab1();
            obiekt.wypelnianie2x();
      //      obiekt.wyswietlanie();
            obiekt.xm=(obiekt.xm)*2;
        }

        std::cout << "Koniec testu algorytmu zwiększania razy 2" << std::endl;

    }

};

#endif
