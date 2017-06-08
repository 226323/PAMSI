#ifndef Map_HPP
#define Map_HPP
#include <iostream>
#include <string>
#include "List.hpp"
#include "Node.hpp"
#include "iMap.hpp"
#define ROZMIAR 1000

class Map : public iMap
{
    private:

	List tab[ROZMIAR];

    public:

    int hashowanie1(std::string klucz)
    {
        int h;
        h=(int)klucz[0];
        return h % ROZMIAR;
    }

    int hashowanie2(std::string klucz)
    {
        int h=0;
        for(unsigned int i=0; i<klucz.length(); i++)
        {
			h=h+((int)klucz[i]);
        }
        return h % ROZMIAR;
    }

	void dodawanie(std::string klucz, std::string wartosc,int typhaszowania)
	{
	    if(typhaszowania==1)
        {
            tab[hashowanie1(klucz)].add(klucz,wartosc);
        }
        if(typhaszowania==2)
        {
            tab[hashowanie2(klucz)].add(klucz,wartosc);
        }
	}

	void szukanie(std::string klucz,int typhaszowania)
	{
        if(typhaszowania==1)
        {
            std::cout<< "Klucz: " << klucz << " Wartosc: " << tab[hashowanie1(klucz)].get_value(klucz) << std::endl;
        }
        if(typhaszowania==2)
        {
            std::cout<< "Klucz: " << klucz << " Wartosc: " << tab[hashowanie2(klucz)].get_value(klucz) << std::endl;
        }
	}

	void flush()
	{
	    for(int i=0;i<ROZMIAR;i++)
        {
            tab[i].flush();
        }
	}

};
#endif
