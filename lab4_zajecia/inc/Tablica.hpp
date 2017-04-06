#ifndef Tablica_HPP
#define Tablica_HPP
#include <iostream>
using namespace std;
#include <cstdlib>
#include "iTablica.hpp"

class Tablica : public iTablica
{
	int length;        //dlugosc tblicy
	int * tablica;  //dynamiczna tablica
	int zapas;          //wolne miejsce w tablicy

	void powieksz(int new_length)
{
	int * tmp = new int [new_length];
	for (int i=0; i<length; i++)//funkcja powiekszania, przyjmowany argument mowi do ilu zwiekszyc tablice
    {
		tmp[i]=tablica[i];
	}
	delete [] tablica;
	tablica=tmp;
	zapas=new_length-(length-zapas);
	length=new_length;
}

public:

Tablica(int x)
{
	length=x;
	zapas =x;
	tablica = new  int [x];

}

~Tablica()
{
	delete [] tablica;
}

void zapis()
{
	int tmp;
	for (int i=0; i<length; i++)
    {
		cout << "podaj element nr " << i+1 << ": ";
		cin >> tmp;
		tablica[i]=tmp;
	}
	zapas=0;
}

void wypelnijlos(int skala)
{
	for (int i=0; i<length; i++)
    {
		tablica[i]=rand() % skala;
	}
	zapas=0;
}

void output()
{
	for(int i=0; i<length; i++)
    {
		cout << tablica[i]<<" ";
	}
	cout << endl << "Wyswietlilem wszystko." << endl;
}

void pokazrozmiar()
{
	cout<< endl << "ilosc elementow " << length << endl;
}

int rozmiar()
{
	return length;
}

int wezzapas()
{
	return zapas;
}

double srednia()
{
	double x;
	x=0;
	for(int i=0; i<length; i++)
    {
		x=x+tablica[i];
	}
	return x/length;
}

void zamienmiejsca(int a, int b)
{
	int tmp;
    tmp=tablica[a];
    tablica[a]=tablica[b];
    tablica[b]=tmp;
}

int & operator[](int element) {return tablica[element];}

};

/*
void testyprogramu(int x, int y){ //funckja wykonujaca pomiary czasu, x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	czas t;
	tab pomiardod1(1); //inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania o 1
	tab pomiarx2(1);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
	tab wynikidod1(y); //inicjalizacja tablicy do ktorej zapisane zostana czasoperacji dla powiekszania o 1
	tab wynikix2(y);   //inicjalizacja tablicy do ktorej zapisane zostana czasoperacji dla powiekszania razy dwa
	for(int i=0; i<y; i++)
	{
		t.begin();       //rozpoczecie mierzenia czasu
		for(int j=0; j<x; j++)
		{

			if(!pomiardod1.zapas)
			{ 							 //jesli nie ma miejsca tablica zostanie powiekszona o 1
				pomiardod1.powieksz((pomiardod1.length)+1); //powiekszenie tablicy o 1
				j--; 					 //zmniejszenie licznika petli w celu nie wyjscia poza zaalokowana pamiec dla tablicy
			}
			else
			{
				pomiardod1[j]=rand (); // uzupelnienie wolnego miejsca o losowa liczbe
				pomiardod1.zapas--;     // ilosc miejsc wolnych zmniejsza sie o 1
			}
		}
		t.stop();        //koniec pomiaru czasu
		wynikidod1[i]=t.pomiar(); //wpisanie wyniku do tablicy
	}
	for(int i=0; i<y; i++)
        {
		t.begin();
		for(int j=0; j<x; j++)
            {
			if(!pomiarx2.zapas)
			{
				pomiarx2.powieksz(2*(pomiarx2.length)); //powiekszenie tablicy dwukrotnie
				j--;
			}
			else
			{
				pomiarx2[j]=rand ();
				pomiarx2.zapas--;
			}
		}
		t.stop();
		wynikix2[i]=t.pomiar();
	}

	cout<< "wyniki dla " << x << " elementow." << endl;
	cout<< "+1" << endl;
	wynikidod1.output();
	cout<< "srednia: " << wynikidod1.srednia();
	cout << endl;
	cout<< "x2" << endl;
	wynikix2.output();
	cout<< "srednia: " << wynikix2.srednia();
	cout << endl;
}*/
#endif
