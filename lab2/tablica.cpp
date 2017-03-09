#include <iostream>
using namespace std;


class tab
{
	int szer;
	int wys;
	int ** tablica;

public:
	tab(int, int);
	~tab();
	void zapis();
	void odczyt();
	int ilekolumn();
	int ilewierszy();
	void rozmiar();
	void dodajelem();
	void usunelem();

private:
	void zmienrozmiar( int nowaszer, int nowawys);
};
//
tab::tab(int x, int y){
	szer=x;
	wys=y;
	tablica = new  int * [szer];
	for (int i=0; i<szer; i++){
		tablica[i]= new int[wys];
	}
}
//
tab::~tab(){
	for (int i=0; i<szer; i++){
		delete [] tablica[i];
	}
	delete [] tablica;
}
//
void tab::zapis(){
	int tmp;
	for (int i=0; i<wys; i++){
		for (int j=0; j<szer; j++){
			cout << "wiersz: " << i+1 << " kolumna: "  << j+1  << endl <<"wartość: ";
			cin >> tmp;
			tablica[j][i]=tmp;
			cout << endl;
		}
	}
}
//
void tab::odczyt(){
	for(int i=0; i<wys; i++){
		for(int j=0; j<szer; j++){
			cout << tablica[j][i]<<" ";
		}
		cout << endl;
	}
}
//
void tab::rozmiar(){
	cout<< endl << "ilosc wierszy: " << wys << endl << "ilosc kolumn: " << szer << endl;
}
//
int tab::ilekolumn(){
	return szer;
}
//
int tab::ilewierszy(){
	return wys;
}
//
void tab::zmienrozmiar(int nowaszer, int nowawys){
	int ** tmp = new int * [nowaszer];
	for (int i=0; i<nowawys; i++){
		tmp[i]= new int[nowawys];
	}
	for (int i=0; i<wys; i++){
		for (int j=0; j<szer; j++){
			tmp[i][j]=tablica[i][j];
			cout << endl;
		}
	}
	tablica=tmp;
	szer=nowaszer;
	wys=nowawys;
}
//
void tab::dodajelem()
{
	int x,y,tmp;
	int wartosc;
	tmp=0;
	cout<<"Podaj adres komorki,kolumna:";
	cin>> x;
	cout<<"Wiersz:";
	cin>> y;
	if(x>szer)
	{
		tmp=3;
	}
	if(y>szer)
	{
		tmp=tmp+1;
	}
	if(tmp==1)
	{
		zmienrozmiar(szer,y);
	}
	if(tmp==3)
	{
		zmienrozmiar(x,wys);
	}
	if(tmp==4)
	{
		zmienrozmiar(x,y);
	}
	cout<<"Podaj wartosc:";
	cin>>wartosc;
	tablica[x][y]=wartosc;
}
//
void tab::usunelem()
{
	int x,y;
	int wartosc;
	cout<<"Podaj adres komorki,kolumna:";
	cin>> x;
	cout<<"Wiersz:";
	cin>> y;
	if((x>szer)||(y>szer))
	{
		cout<<"Podano adres spoza zakresu tablicy";
	}
	else
	{
		cout<<tablica[x][y];
	}
}

int main(){
	int x,y;
		cout<<"ilosc kolumn: ";
		cin>> x;
		cout<<"ilosc wierszy: ";
		cin>> y;
		tab tablica(x, y);
		tablica.zapis();
		tablica.odczyt();
		tablica.rozmiar();
		tablica.dodajelem();
		tablica.usunelem();
	return 0;
}
