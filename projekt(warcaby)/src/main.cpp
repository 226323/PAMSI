#include "../inc/pionek.hpp"
#include "../inc/lisc.hpp"
#include "../inc/ruch.hpp"
#include "../inc/rozgrywka.hpp"
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include <vector>

int main()
{
  int wybor;
  int glebia=5;
  std::cout << "\t\t WARCABY" << std::endl << std::endl;

  std::cout << "\t\tWybierz rodzaj gry:" << std::endl;
  std::cout << "\t\t1 --> gracz 1 vs gracz 2" << std::endl;
  std::cout << "\t\t2 --> gracz 1 vs komputer" << std::endl << std::endl;
  std::cout << "\t\tWybor:  ";
  std::cin >> wybor;
  std::cout << std::endl << std::endl;
  if(wybor==2)
  {
    while(glebia<1&&glebia>9)
    {
        std::cout << "Wybierz glebokosc minmaxa:(domyslna glebokosc 5)" << std::endl;
        std::cin >> glebia;
    }
  }
  rozgrywka R(glebia);
  R.wyswietl();
  if(wybor==1)
    {
        while((R.pionki_gracza(1)!=0)||(R.pionki_gracza(2)!=0))
        {
            if(R.pionki_gracza(1)==0){ break;}
            R.ruch_gracza(1);
            R.wyswietl();
            if(R.pionki_gracza(2)==0){ break;}
            R.ruch_gracza(2);
            R.wyswietl();
        }
    }
  if(wybor==2)
  {
    while((R.pionki_gracza(1)!=0)||(R.pionki_gracza(2)!=0))
    {
      if(R.pionki_gracza(1)==0){ break;}
      R.ruch_gracza(1);
      R.wyswietl();
      if(R.pionki_gracza(2)==0){ break;}
      R.ruch_komputera(2);
      R.wyswietl();
    }
  }

  if(R.pionki_gracza(1)!=0)
    std::cout << std::endl << "\t\t" << "gracz 1" << " ZWYCIEZA! " << std::endl;
  else {
    if(wybor==1)
      std::cout << std::endl << "\t\t" << "gracz 2" << " ZWYCIEZA! " << std::endl;
    else
      std::cout << std::endl << "\t\t" << "komputer" << " ZWYCIEZA! " << std::endl;
  }
  return 0;
}
