#include "../inc/iRunnable.hpp"
#include "../inc/Stack.hpp"
#include "../inc/List.hpp"
#include "../inc/Queue.hpp"
#include "../inc/Clock.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

double mean(double tab[],int size)
{
	double x;
	x=0;
	for(int i=0; i<size; i++)
	{
		x=x+tab[i];
	}
	return x/size;
}

//void mierz(int a,int b, iRunnable &x) //a- ilosc elementow, b- ilosc testow, x- obiekt
void mierz(int a,int b,iRunnable &x) //a- ilosc elementow, b- ilosc testow, x- obiekt
{
    double pomiary [20];
	Clock time;
	for(int j=0; j<b; j++)
	{
	    if(x.type()!="Stack")       //sprawdzenie czy element nie jest stosem
        {
            for(int i=0; i<=a; i++)
            {
                if(i!=a)
                {
                    x.add(18); //wrzuca liczbe 18
                }
                else
                {
                    x.add(6); //wrzuca liczbe 6
                }
            }
        }
        else
        {   //jesli jest to dodajemy element ktorego bedziemy szukac na poczatku, zeby byl na samym dnie stosu
            for(int i=0; i<=a; i++) //inaczej zawsze szukalibysmy pierwszego elementu
            {
                if(i==0)
                {
                    x.add(6); //wrzuca liczbe 18
                }
                else
                {
                    x.add(18); //wrzuca liczbe 6
                }
            }
        }
		time.begin();
		x.find_value(6);    //szuka liczby 6
		time.stop();
		pomiary[j]=time.duration();
		x.flush();
	}
	cout <<  x.type()<<endl;
	cout <<a << " elementow ";
	cout << mean(pomiary,b) <<" nanosekund";
	cout << " pomiar wykonany: " << b << " razy"<<endl;
}


int main()
{
	int testy=20;
	List l;
	Stack s;
	Queue q;
	for(int j=1;j<=6;j++)
	{
		if((j!=7)&&(j!=8))
		{
		for(int i=0;i<3;i++)
			{
				if(i==0)
				{
					mierz(pow(10,j),testy,l);
				}
				if(i==1)
				{
					mierz(pow(10,j),testy,s);
				}
				if(i==2)
				{
					mierz(pow(10,j),testy,q);
				}
			}
		}
	}
	return 0;
}
