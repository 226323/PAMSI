#ifndef DANE_HPP
#define DANE_HPP
#include <iostream>
using namespace std;

template<typename T>

class Dane
{
	public:

	virtual void zapis()=0;														//Wypelnianie reczne
	virtual void wypelnijlos(int skala)=0;									//Wypelnienie losowo
	virtual void output()=0;	 											//Wypisanie calej zawartosci na std::cout
	virtual int rozmiar()=0;												//Zwrocenie rozmiaru
	virtual int wezzapas()=0;												//Zwrocenie wolnego miejsca w elemencie
	virtual int powieksz(int nowa)=0;									//Zmienianie rozmiaru elementu
	//virtual static void wykonajalgorytmdod1(int x)=0;
	//virtual static void wykonajalgorytmx2(int x)=0;
	virtual T& operator[](int element)=0;									//Dostep do elementu po indeksie
};

#endif
