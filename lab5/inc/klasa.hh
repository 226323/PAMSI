#include <iostream>
#ifndef KLASA_HH
#define KLASA_HH
    template <typename T>
    class tab
     {
    public:
    int x;
    int xi;
    T* tablica=nullptr; 
    T* tablica1;

    int xm;
    T* tablica2x;    

    void tworzenie();    
    void wypelnianie();
    void wyswietlanie();
    void destruktor();
    void nowatabplus1();
    void tab1natab2();
    void nowatabplus1del();
    void wyswietlanie1();
    void destruktor1();
    void tab2natab1();
    void wypelnianie_plus1();

    void nowatabx2();
    void nowatabx2del();
    void tab1natab2x();
    void tab2xnatab1(); 
    void wypelnianie2x();
    
    };

    template <typename T>                       //konstruktor tablicy (1)
    void tab<T>::tworzenie()    {
        tablica = new T [x];
    }
    
    template <typename T>                       //destruktor tablicy (1)
    void tab<T>::destruktor()  {
        delete [] tablica;
    }

    template <typename T>                       //tworzenie tablicy (2) o 1 większej od tablicy (1)
    void tab<T>::nowatabplus1()    {
        tablica1 = new T [xi];
    }
    
    template <typename T>                       //destruktor tablicy (2)
    void tab<T>::destruktor1()    {
        delete [] tablica1;
    }


    template <typename T>                       //wypełnianie tablicy (1)
    void tab<T>::wypelnianie()   {
    for (int i=0; i<x;i++){
        tablica[i]=rand();
        }
    }
    
    template <typename T>                       //wypełnianie pustej komórki tablicy (2)
    void tab<T>::wypelnianie_plus1()    {
    tablica[x-1]=rand();
    }    

 
    template <typename T>                       //przepisywanie tablicy (1) na tablicę (2)
    void tab<T>::tab1natab2()     {
    for (int i=0;i<x;i++)   {
        tablica1[i]=tablica[i];
        }
    }   
    template <typename T>                       //przepisywanie tablicy (2) na tablicę (1)
    void tab<T>::tab2natab1()   {
    for (int i=0;i<xi;i++)  {
        tablica[i]=tablica1[i];
        }
    }
    
    template <typename T>                       //destruktor tablicy (2)
    void tab<T>::nowatabplus1del()  {
        delete [] tablica1;
    }
 
    template <typename T>                       //wyświetlanie tablicy (1)
    void tab<T>::wyswietlanie()  {              //potrzebne było tylko do testów czy algorytm działa poprawnie
    for (int i=0;i<x;i++)   {
        std::cout << tablica[i];
        std::cout << std::endl;
        }
    }    
    
    template <typename T>                       //wyświetlanie tablicy (2)
    void tab<T>::wyswietlanie1()  {
    for (int i=0;i<xi;i++)   {
        std::cout << tablica1[i];
        std::cout << std::endl;
        }
    }    
    

    template <typename T>                       //konstruktor tablicy (3), dwukrotnie większej od tablicy (1) 
    void tab<T>::nowatabx2()    {
        tablica2x = new T [xm];
    }

    template <typename T>                       //destruktor tablicy (3)
    void tab<T>::nowatabx2del() {
        delete [] tablica2x;
    }

    template <typename T>                       //przepisywanie tablicy (1) na tablicę (3)
    void tab<T>::tab1natab2x()  {
    for (int i=0;i<x;i++)   {
        tablica2x[i] = tablica[i];
        }
    }

    template <typename T>                       //przepisywanie tablicy (3) na tablicę (1)
    void tab<T>::tab2xnatab1()  {
    for (int i=0;i<xm;i++)  {
        tablica[i]=tablica2x[i];
        }
    }

    template <typename T>                       //wypełnianie pustych po powiększeniu komórek tablicy
    void tab<T>::wypelnianie2x()    {
        for (int i=x/2;i<xm;i++)    {
            tablica[i]=rand();
        }
    }



#endif
