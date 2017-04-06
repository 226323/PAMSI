#ifndef iTablica_HPP
#define iTablica_HPP

class iTablica
{
public:
	virtual void zapis()=0;      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
	virtual void wypelnijlos(int skala)=0;//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres losowych liczb
	virtual void output()=0;      //wypisuje wartosci tablicy
	virtual int rozmiar()=0;         //zwraca rozmiar tablicy
	virtual void pokazrozmiar()=0;	//wypisuje rozmiar tablicy
	virtual int wezzapas()=0;    //zwraca ilosc wolnego miejsca w tablicy
	virtual double srednia()=0; //funkcja zwracajaca srednia wszystkich elementow tablicy
	virtual void zamienmiejsca(int a, int b)=0;
	//przeciazenia
	virtual int & operator[](int element)=0; //przeciazenie operatora []
};
#endif
