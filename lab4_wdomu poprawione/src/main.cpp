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

double pomiar(int elem, char piwot,int i)
{
    int tmp=elem;
	Timer t;
    srand(time(NULL));
    Tablica a(tmp);
    switch(i)
    {
    case 0:
        a.wypelnijlos(100000);
        break;

    case 1:
        a.wypelnijrosnaco();
        break;

    case 2:
        a.wypelnijmalejaco();
        break;
    }
    t.begin();
    quicksort(a,0,a.rozmiar()-1,piwot);
    t.stop();
    return t.duration();
}

int main()
{
    double pomiary[POMIARY];
    string piwotto;
    string kolejnosc;
    char piwot;
    kolejnosc="losowo";
    for(int j=1;j<=10;j++)
    {
        for(int l=0;l<3;l++)
        {
            switch(l)
            {
            case 0:
                piwot='p';
                piwotto="poczatku";
                break;

            case 1:
                piwot='s';
                piwotto="srodku";
                break;

            case 2:
                piwot='k';
                piwotto="koncu";
                break;
            }
            for(int i=0;i<3;i++)
            {
                switch(i)
                {
                case 0:
                    kolejnosc="losowo";
                    break;

                case 1:
                    kolejnosc="rosnaco";
                    break;

                case 2:
                    kolejnosc="malejaco";
                    break;
                }

                for(int k=0;k<POMIARY;k++)
                {
                    pomiary[k]=pomiar(10000*j,piwot,i);
                }
                cout << srednia(pomiary) << "   ";
            }
        }

        cout << endl;

    }
	return 0;
}
