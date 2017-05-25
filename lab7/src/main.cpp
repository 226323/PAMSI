#include "../inc/Lisc.hpp"
#include "../inc/Drzewo.hpp"
#include "../inc/Timer.hpp"
#include <cstdlib>
#include <ctime>
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

int main()
{
	Drzewo d;
	double pomiary[POMIARY];
	Timer t;
	int i,j,tmp;
	for(j=1;j<=10;j++)
    {
        tmp=j*100000;
        for(i=0;i<POMIARY;i++)
        {
            d.fill(tmp);
            t.begin();
            d.search(1);
            t.stop();
            d.flush();
            pomiary[i]=t.duration();
        }
        cout << "Wynik pomiary dla " << tmp << " elementów w drzewie to " << srednia(pomiary) << endl;
    }
	return 0;
}
