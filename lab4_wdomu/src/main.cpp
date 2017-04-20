#include "../inc/Tablica.hpp"
#include "../inc/Timer.hpp"
#include "../inc/Quicksort.hpp"
#include <cstdlib>
#include <cmath>
#include <chrono>
#include<iostream>
using namespace std;
#define POMIARY 1

double srednia(double tablica[])
{
	double x;
	x=0;
	for(int i=0; i<1; i++)
    {
		x=x+tablica[i];
	}
	return x/POMIARY;
}

int main()
{
    Tablica a(10);
    int tmp,piwot;
    string piwotto;
    string kolejnosc;
	Timer t;
	double pomiary[POMIARY];
    srand(time(NULL));
    for(int j=1;j<=10;j++)
    {
        for(int l=0;l<3;l++)
        {
            switch(l)
            {
            case 0:
                piwot=0;
                piwotto="poczatku";
                break;

            case 1:
                piwot=a.rozmiar()/2;
                piwotto="srodku";
                break;

            case 2:
                piwot=a.rozmiar()-1;
                piwotto="koncu";
                break;
            }
            tmp=1000*j;
            a.powieksz(tmp);
            for(int i=0;i<3;i++)
            {
                for(int k=0;k<POMIARY;k++)
                {
                    switch(i)
                    {
                    case 0:
                        a.wypelnijlos(100);
                        kolejnosc="losowo";
                        break;

                    case 1:
                        a.wypelnijrosnaco();
                        kolejnosc="rosnaco";
                        break;

                    case 2:
                        a.wypelnijmalejaco();
                        kolejnosc="malejaco";
                        break;
                    }
                    t.begin();
                    quicksort(a,piwot,a.rozmiar());
                    t.stop();
                    pomiary[k]=t.duration();
                }
                cout << "Średni czas sortowania z piwotem umieszczonym na " << piwotto << " dla " << tmp << " elementów ulozonych " << kolejnosc << " to " << srednia(pomiary) << " nanosekund."<< endl;
            }
        }
    }
	return 0;
}
