#include <iostream>
using namespace std;
#include "../inc/Tablica.hpp"
#include "../inc/Czas.hpp"
#include "../inc/Dane.hpp"

double srednia(double tablica[])
{
	double x;
	x=0;
	for(int i=0; i<20; i++){
		x=x+tablica[i];
	}
	return x/20;
}

int main()
{
	int x=10;
	czas t;
	int i,j;
	double seriad1[20];
	double seriax2[20];
	for (i=0; i<6; i++)
	{
		for(j=0; j<20; j++)
		{
			t.begin();
			tab<double>::wykonajalgorytmdod1(x);
			t.stop();
			seriad1[j]=t.pomiar();
			cout<<" Pomiar +1 dla "<< x << " " << seriad1[j];
			t.begin();
			tab<double>::wykonajalgorytmx2(x);
			t.stop();
			seriax2[j]=t.pomiar();
			cout<<" Pomiar x2 dla "<< x << " " <<  seriax2[j];
			cout << ".-." << endl;
		}
        cout<<endl;
		cout<<"Sredni pomiar +1 dla "<< x << " " <<  srednia(seriad1) << endl;
		cout<<"Sredni pomiar x2 dla "<< x << " " <<  srednia(seriax2) << endl;
		x=x*10;
	}

	return 0;
}
