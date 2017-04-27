#ifndef Tablica_HPP
#define Tablica_HPP
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include "Node.hpp"
#include "List.hpp"
#include "iTablica.hpp"

class Tablica : public iTablica , public List , public Node
{
	int length;        //dlugosc tblicy
	List * tablica;  //dynamiczna tablica

    public:



Tablica()
{
    List l;
    //char alfabet[]="abcdefghijklmnopqrstuwxyz";
    length=24;
	for(int i=0;i<24;i++)
    {
        tablica[i] = l;
    }
}

~Tablica()
{
	delete [] tablica;
}

void Dodaj(std::string klucz, std::string wartosc)
{
    char alfabet[]="abcdefghijklmnopqrstuwxyz";
	for (int i=0; i<length; i++)
    {
		if(klucz[0]==alfabet[i])
        {
            tablica[i].add(klucz,wartosc);
            return;
        }
    }
    cout<< "Nie udalo sie dodac" << endl;
}

void Znajdz(std::string klucz)
{
    char alfabet[]="abcdefghijklmnopqrstuwxyz";
    for (int i=0; i<length; i++)
    {
		if(klucz[0]==alfabet[i])
        {
            tablica[i].find_key(klucz);
            return;
        }
    }
}

std::string Zwroc(std::string klucz)
{
    char alfabet[]="abcdefghijklmnopqrstuwxyz";
    for (int i=0; i<length; i++)
    {
		if(klucz[0]==alfabet[i])
        {
            return tablica[i].find_value(klucz);
        }
    }
}


void output()
{
	for(int i=0; i<length; i++)
    {
		tablica[i].print();
	}

}

void pokazrozmiar()
{
	cout<< endl << "ilosc kontenerow " << length << endl;
}

int rozmiar()
{
	return length;
}

int wezzapas()
{
	return zapas;
}


std::string operator[](const std::string& a) {return Zwroc(a);}


};


#endif
