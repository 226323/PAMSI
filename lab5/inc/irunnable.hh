#include <iostream>
#include <cstdlib>
#include "mergesort.hh"
#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH

template <typename D>
class irunnable
    : public dodawanie<D>, mnozenie<D>, iclock, stack, sort<D>
    {
    public:
    void run()  {
     int max;
    double roznica;
    int wybor;

    max=10000;
    /*while (max<11)  {
       std::cout << "Podaj liczbę większą od 10" << std::endl;
       std::cin >> max;
    }*/
    std::cout << "Podaj algorytm." << std::endl;
    std::cout << "1 - zwiększanie tablicy o 1" << std:: endl;
    std::cout << "2 - zwiększanie tablicy przez mnożenie razy 2" << std::endl;
    std::cout << "3 - Przeszukiwanie stosu \n";
    std::cout << "4 - Przeszukiwanie listy \n";
    std::cout << "5 - Przeszukiwanie kolejki \n";
    std::cout << "6 - merge sort \n";
    std::cin >> wybor;


    while (wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5 && wybor!=6)  {
        std::cout << "Podaj liczbę 1 lub 2" << std::endl;
        std::cin >> wybor;
    }

//    std::cout.setf(std::ios::fixed);            //liczenie czasu
//    std)::cout.precision(5);
//    clock_t start, koniec;
    iclock mierzenie;
//    mierzenie.czas();
//    mierzenie.start=clock();                                                  //dodane

//    if (wybor==1)    {

    switch (wybor)  {


    case 1:
    {
        dodawanie<D> obiekt1;
        mierzenie.start=clock();
        obiekt1.testplus1(max);
    break;
    }

   // if (wybor==2)    {
    case 2:
    {
        mnozenie<D> obiekt1;
        mierzenie.start=clock();
        obiekt1.testrazy2(max);
    break;
    }

    case 3:
        {
        stack obiekt1;
        std::cout << "tworzenie stosu\n";
        for (int i=0; i<max;i++)    {
        obiekt1.push(max);
        }
        //  for (int i=0; i<max;i++)    {
       // std::cout << "\ndrukowanie stosu\n";
//        obiekt1.print();
    //    }
        //std::cout << "irrun test 1 \n";
        /*
        std::cout << "\nzdejmowanie i drukowanie\n";
        for (int i=0; i<max;i++)    {
        std::cout << "\npętla\n\n";
        obiekt1.pop();
   //     std::cout << "pop \n";
    //    stack::size=stack::size-1;
        obiekt1.print();
    }   */
    //    mierzenie.start=clock();
        std::cout << "\nwyszukiwanie\n";
        mierzenie.start=clock();
        obiekt1.find_value(2137);

//        obiekt1.find_value(2137);
    break;
    }

    case 4:
    {
        list obiekt1;
        std::cout << "tworzenie listy \n";
        for (int i=0; i<max; i++)   {
            obiekt1.add(max);
        }
   //     obiekt1.print();
        mierzenie.start=clock();
        obiekt1.find_value(2137);
    break;
    }

    case 5:
    {

        queue obiekt1;
        std::cout << "tworzenie kolejki \n";
        for (int i=0;i<max;i++) {
            if (i!=(max-1))   {
                obiekt1.enqueue(1);
          }
            else    {
                obiekt1.enqueue(2);
            }
       }

        //obiekt1.print();
        mierzenie.start=clock();
        std::cout << "testirun ";
        obiekt1.find_value(2137);
    break;
    }



  /*
    case 6:
    {
        sort<D> obiekt1;
        std::cout << std::endl;
        obiekt1.tworzenie(max);
        std::cout << "wypelnianie "<< std::endl;
        obiekt1.wypelnianie(max);
        std::cout << "test" << std::endl;
        obiekt1.przepisywanie(obiekt1.zwracanie(max),max);
        //obiekt1.drukuj_tablice_sortowania(max);
    break;
    }
*/

    case 6:
    {
        while(max<=100000)
        {
        for(int i=0;i<3;i++)
        {
            sort<D> obiekt1;
            obiekt1.tworzenie(max);
            if(i==0)
            {
                obiekt1.wypelnianie(max);
            }
            if(i==1)
            {
                obiekt1.wypelnianierosnaco(max);
            }
            if(i==2)
            {
                obiekt1.wypelnianiemalejaco(max);
            }
            mierzenie.start=clock();
            obiekt1.sortowanie(obiekt1.zwracanie(),0, max);
            mierzenie.koniec=clock();
            roznica=(mierzenie.koniec-mierzenie.start)/(double)CLOCKS_PER_SEC;
            std::cout << roznica << "  " ;
        }
        std::cout << std::endl;
        max+=10000;
        }

    }
    break;

    }
    roznica=(mierzenie.koniec-mierzenie.start)/(double)CLOCKS_PER_SEC;
    std::cout << "Czas wykonywania algorytmu: " << roznica << std::endl;

    }

    };



#endif
