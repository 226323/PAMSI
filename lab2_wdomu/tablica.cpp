#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std::chrono;

class tab
{
	int length;        //dlugosc tblicy
	double * tablica;  //dynamiczna tablica
	void powieksz(int); //funkcja powiekszania, przyjmowany argument mowi do ilu zwiekszyc tablice
	int zapas;          //wolne miejsce w tablicy
public:
	tab(int);
	void zapis();      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
	~tab();
	void wypelnijlos(int skala);//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres losowych liczb
	void output();      //wypisuje wartosci tablicy
	int rozmiar();         //zwraca rozmiar tablicy
	void pokazrozmiar();	//wypisuje rozmiar tablicy
	int wezzapas();    //zwraca ilosc wolnego miejsca w tablicy
	friend void testyprogramu(int, int); //zaprzyjazniona funkcja sluzaca do pomiarow
	double srednia(); //funkcja zwracajaca srednia wszystkich elementow tablicy
	//przeciazenia
	double & operator[](int element) {return tablica[element];} //przeciazenie operatora []
};
//
tab::tab(int x){
	length=x;
	zapas =x;
	tablica = new  double [length];

}
//
tab::~tab(){
	delete [] tablica;
}
//
void tab::zapis(){
	int tmp;
	for (int i=0; i<length; i++){
		cout << "podaj element nr " << i+1 << ": ";
		cin >> tmp;
		tablica[i]=tmp;
	}
	zapas=0;
}
//
void tab::wypelnijlos(int skala){
	for (int i=0; i<length; i++){
		tablica[i]=rand() % skala;
	}
	zapas=0;
}
//
void tab::output(){
	for(int i=0; i<length; i++){
		cout << tablica[i]<<" ";
	}
	cout << endl << "thats all" << endl;
}
//
void tab::pokazrozmiar(){
	cout<< endl << "ilosc elementow " << length << endl;
}
//
int tab::rozmiar(){
	return length;
}
//
int tab::wezzapas(){
	return zapas;
}
//
void tab::powieksz(int new_length){
	double * tmp = new double [new_length];
	for (int i=0; i<length; i++){
		tmp[i]=tablica[i];
	}
	// delete [] tablica;
	free(tablica);
	tablica=tmp;
	zapas=new_length-(length-zapas);
	length=new_length;
}
//
double tab::srednia(){
	double x;
	x=0;
	for(int i=0; i<length; i++){
		x=x+tablica[i];
	}
	return x/length;
}
//
/*class czas
{
	double start, end;
	double czasoperacji;
    void begin(){
    	start = clock();
    }
    //
    void stop(){
    	end = clock();
    }
    //
	void zwrocczas(){
		czasoperacji = end-start;
    	cout<< "czas trwania: " << czasoperacji << endl;
	}
	double pomiar(){
		czasoperacji = (end-start);
		return czasoperacji;
	}*/
	class czas
{
	high_resolution_clock::time_point start, end;
	// std::chrono::duration<double> time_span;
	std::chrono::nanoseconds ns;

    void begin(){
    	start = high_resolution_clock::now();
    }
    //
    void stop(){
    	end = high_resolution_clock::now();
    }
    //
	void zwrocczas(){
		ns = duration_cast<nanoseconds>(end-start);
    	cout<<std::fixed<< "czas trwania: " << ns.count() << endl;
	}
	double pomiar(){
		ns = duration_cast<nanoseconds>(end-start);
		return double(ns.count());
	}
	//
	friend void testyprogramu(int, int);
};
	//

//

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
	for(int i=0; i<y; i++){
		t.begin();
		for(int j=0; j<x; j++){
			if(!pomiarx2.zapas){
				pomiarx2.powieksz(2*(pomiarx2.length)); //powiekszenie tablicy dwukrotnie
				j--;
			}
			else{
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
}
//
int main()
{
	double x=10;
	int y=3;
	for (int i=0; i<6; i++){
		cout << "*************" << endl;
		testyprogramu(x, y);
		cout << "-*************" << endl;
		x=x*10;
	}
	return 0;
}
