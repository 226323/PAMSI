#include "../inc/Node.hpp"
#include "../inc/List.hpp"
#include "../inc/Tablica.hpp"
#include "../inc/Timer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	Tablica t;
	int kupa;
	std::string cos1,cos2;
	while(kupa!="0")
	{
	    cout << "1 dodanie elementu, 2 znalezienie elementu";
	    cin >> kupa;
		switch(kupa)
		{
        case 1:
            cout << "Podaj klucz: ";
            cin >> cos1;
            cout << "Podaj wartosc: ";
            cin >> cos2;
            t.add(cos1,cos2);
            break;

        case 2:
            cout << "Podaj szukany klucz: ";
            cin >> cos1;
            cout << "Wartosc szukanego klucza to: " << t[cos1];
		}
	}
	return 0;
}
