#ifndef Quicksort_HPP
#define Quicksort_HPP
#include <iostream>
using namespace std;
#include "Tablica.hpp"

int podziel(Tablica &a,int p,int r) //p - piwot(miejsce startu)  r - element odniesienia
{
    int wartosc=a[r];
    int i=r-1;
    cout <<"robie cos1" << endl;
    for(int j=p; j<=(r-1); j++)
    {
		if(a[j]<wartosc)
		{
			i++;
			a.zamienmiejsca(i+1, j);
			cout <<"robie cos" << endl;
		}
	}
	a.zamienmiejsca((i+1), r);
return i+1;
}

void quicksort(Tablica &a, int p, int r)
{
	if(p<r)
    {
		int q=podziel(a, p, r);
		quicksort(a, p, q-1);
		cout<<"kappa"<< endl;
		quicksort(a, q+1, r);
	}
}
#endif
