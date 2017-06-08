#ifndef iMap_HPP
#define iMap_HPP
#include <iostream>

class iMap
{
    public:
    virtual int hashowanie1(std::string klucz)=0; //funkcja konwertująca string na numer miejsca w tabeli
    virtual int hashowanie2(std::string klucz)=0; //funkcja konwertująca string na numer miejsca w tabeli
    virtual void dodawanie(std::string klucz, std::string wartosc,int typhaszowania)=0; //dodawanie nowego elementu do tablicy
    virtual void szukanie(std::string klucz,int typhaszowania)=0; //wyszukiwanie elementu
    virtual void flush()=0; //czyszczenie tablicy
};
#endif
