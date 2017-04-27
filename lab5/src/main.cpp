#include <iostream>
#include <cstdlib>

#include "klasa.hh"
#include "plus1.hh"
#include "razy2.hh"
#include "ilist.hh"
#include "list.hh"
#include "istack.hh"
#include "iclock.hh"
#include "stack.hh"
#include "node.hh"
#include "iqueue.hh"
#include "queue.hh"
#include "irunnable.hh"
#include "mergesort.hh"

int main() {
srand(time(NULL));
    irunnable<int> badanie;
    badanie.run();

}

/*    int max;
    double roznica;
    int wybor;

    std::cout << "Podaj rozmiar tablicy: " ;
    std::cin >> max;
    while (max<11)  {
       std::cout << "Podaj liczbę większą od 10" << std::endl;
       std::cin >> max;
    }
    std::cout << "Podaj algorytm zwiększania tablicy." << std::endl;
    std::cout << "1 - zwiększanie o 1" << std:: endl;
    std::cout << "2 - zwiększanie przez mnożenie razy 2" << std::endl;
    std::cin >> wybor;
    while (wybor!=1 && wybor!=2)  {
        std::cout << "Podaj liczbę 1 lub 2" << std::endl;
        std::cin >> wybor;
    }

//    std::cout.setf(std::ios::fixed);            //liczenie czasu
//    std)::cout.precision(5);
//    clock_t start, koniec;
    iclock mierzenie;
//    mierzenie.czas();
    mierzenie.start=clock();                                                  //dodane

    if (wybor==1)    {

        dodawanie<float> obiekt1;               //deklarowanie typu
        obiekt1.testplus1(max);
   }

    if (wybor==2)    {
        mnozenie<float> obiekt1;                //deklarowanie typu
        obiekt1.testrazy2(max);
    }

    mierzenie.koniec=clock();
    roznica=(mierzenie.koniec-mierzenie.start)/(double)CLOCKS_PER_SEC;
    std::cout << "Czas wykonywania algorytmu: " << roznica << std::endl;
*/



