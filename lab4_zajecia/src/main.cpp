#include "../inc/Tablica.hpp"
#include "../inc/Clock.hpp"
#include "../inc/Quicksort.hpp"
#include <cstdlib>
#include<iostream>
using namespace std;


int main()
{
    Tablica a(10);
	srand(time(NULL));
	Clock t;
	a.wypelnijlos(30);
	a.output();
	t.begin();
	quicksort(a,0,a.rozmiar());
	t.stop();
	a.output();
	cout << "Czas sortowania: " << t.duration() <<" nanosekund"<< endl;
	return 0;
}
