#include "../inc/Node.hpp"
#include "../inc/List.hpp"
#include "../inc/Map.hpp"
#include "../inc/Timer.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#define POMIARY 20

double srednia(double tablica[])
{
	double x;
	x=0;
	for(int i=0; i<POMIARY; i++)
    {
		x=x+tablica[i];
	}
	return x/POMIARY;
}

void pomiar(int j)
{
    Map obiekt;
	std::ifstream plik;
	double pomiary[POMIARY];
	Timer t;
	std::string klucz, wartosc;
    plik.open("klucze.txt");
    while (!plik.eof())
    {
        plik>>klucz>>wartosc;
        obiekt.dodawanie(klucz, wartosc,j);
    }
    for(int i=0;i<POMIARY;i++)
        {

            plik.close();
            t.begin();
            obiekt.szukanie("goktp",j);
            t.stop();
            pomiary[i]=t.duration();
        }
        //std::cout << "Sredni czas szukania dla haszowania nr " << j << "wynosi: " << srednia(pomiary) << std::endl;
        std::cout << srednia(pomiary) << std::endl;
}

int main()
{
	for(int i=1;i<3;i++)
    {
        pomiar(i);
        std::cout << "zmiana haszowanka xDD"<<std::endl;
    }
	return 0;
}
