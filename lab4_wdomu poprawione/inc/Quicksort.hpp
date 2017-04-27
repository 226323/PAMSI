#ifndef Quicksort_HPP
#define Quicksort_HPP
#include <iostream>
using namespace std;
#include "Tablica.hpp"

void quicksort(Tablica &a, int p, int r,char pivot)
{
	int piwot;
	int miejscepiwota;
	int i;
	int j;
	switch(pivot)
	{
		case 'p':
			miejscepiwota=p;
			break;

		case 's':
			miejscepiwota=(p+r)/2;
			break;

		case 'k':
			miejscepiwota=r;
			break;
	}
	piwot=a[miejscepiwota];
	j=p;
	for(i=p; i<r; i++)
    {
		if(a[i]<piwot)
        {
			a.zamienmiejsca(i,j);
			j++;
		}
	}
	if(p<(j-1))
    {
        quicksort(a,p,(j-1),pivot);
    }
    if((j+1)<r)
    {
        quicksort(a,(j+1),r,pivot);
    }
}
#endif
/*
void quicksort(Tablica &a, int p, int r,char pivot)
{
	if(p<r)
    {
		int q=partition(a, p, r,pivot);
		quicksort(a, p, q,pivot);
		quicksort(a, q+1, r,pivot);
	}
}
#endif

*/
/*
void quicksort(Tablica &a, int p, int r, char typpiwotu) //p - pierwszy element tabeli r - ostatni element tabeli typpiwotu: p-pierwszr s-srodkowy o-ostatni
{
	int q;			//punkt podzialu
	int piwot;
	if(typpiwotu=='p')
	{
		q=p;
	}
	if(typpiwotu=='s')
	{
		q=((p+r)/2);
	}
	if(typpiwotu=='o')
	{
		q=r;
	}
	piwot=a[q];
	int j=0;
	for(int i=0; i<r; i++)
	{
		if(a[i] < piwot)
		{
			a.zamienmiejsca(i,j);
			j++;
		}
	}
	a[r]=a[j];
	a[j]=piwot;
	if(p<(j-1))
	{
		quicksort(a, p, (j-1), typpiwotu);
	}
	if (j <r)
	{
		quicksort(a, (j+1), r, typpiwotu);
	}
}
#endif*/


/*
int partition(Tablica &tablica, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
    int x = tablica[p];
    int i = p, j = r;
    while (true)
    {
        while (tablica[j] > x)
        {
            j--;
        }
        while (tablica[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            tablica.zamienmiejsca(i,j);
            i++;
            j--;
        }
        else
        {
            return j;
        }
    }
}
void quicksort(Tablica &tablica, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(tablica,p,r);
        quicksort(tablica,0,p);
        quicksort(tablica, p, q-1);
        quicksort(tablica, q+1, r);
    }
}
#endif*/
