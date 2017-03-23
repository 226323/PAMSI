#include <iostream>
#include"Dane.hpp"
using namespace std;
#ifndef TABLICA_HPP
#define TABLICA_HPP

template <typename T>

class tab : public Dane<T>
{
public:

	int length;        //dlugosc tblicy
	T* tablica;  //dynamiczna tablica
	int zapas;          //wolne miejsce w tablicy

tab(int x)
{
	length=x;
	zapas =x;
	tablica = new  T [length];

}

~tab()
{
	delete [] tablica;
}

void zapis()      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
{
	T tmp;
	for (int i=0; i<length; i++)
	{
		cout << "podaj element nr " << i+1 << ": ";
		cin >> tmp;
		tablica[i]=tmp;
	}
	zapas=0;
}

void wypelnijlos(int skala)//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres losowych liczb
{
	for (int i=0; i<length; i++)
	{
		tablica[i]=rand() % skala;
	}
	zapas=0;
}

void output()		//wypisuje wartosci tablicy
{
	for(int i=0; i<length; i++)
	{
		cout << tablica[i]<<" ";
	}
	cout << endl << "thats all" << endl;
}

int rozmiar()		//zwraca rozmiar tablicy
{
	return length;
}

int wezzapas()    //zwraca ilosc wolnego miejsca w tablicy
{
	return zapas;
}

int powieksz(int nowa)
{ 		//funkcja powiekszania, przyjmowany argument mowi do ilu zwiekszyc tablice
	T* tmp=new T[nowa];
	for (int i=0; i<length; i++)
	{
		tmp[i]=tablica[i];
	}
	free(tablica);
	tablica=tmp;
	zapas=nowa-(length-zapas);
	length=nowa;
	return 0;
}

static void wykonajalgorytmdod1(int x)
{ //funckja wykonujaca pomiary czasu, x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	tab pomiardod1(10); //inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania o 1
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
}

static void wykonajalgorytmx2(int x)
{
	tab pomiarx2(10);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
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
}

//przeciazenia
T& operator[](int element) {return tablica[element];} //przeciazenie operatora []

};

#endif
