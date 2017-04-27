#ifndef MERGESORT_HH
#define MERGESORT_HH
#include<iostream>

template <typename T>
class sort
{
    T* quicktab=nullptr;
    public:

    void tworzenie (int max)
    {
        quicktab = new int [max];
    }

    void wypelnianie(int max)
    {
        for (int i=0;i<max;i++)
        {
            quicktab[i]=rand()%100000;
        }
    }
    void wypelnianierosnaco(int max)
    {
        for (int i=0;i<max;i++)
        {
            quicktab[i]=i;
        }
    }
    void wypelnianiemalejaco(int max)
    {
        for (int i=0;i<max;i++)
        {
            quicktab[i]=max-i;
        }
    }

    T* zwracanie()
    {
        return quicktab;
    }

    void drukowanie(int max)
    {
        for(int i=0;i<max;i++)
        {
            std::cout << quicktab[i] << " ";
        }
        std::cout<<std::endl;
    }

    void zamiana (int* a, int* b)
    {        //metoda potrzebna do sortowania
        int t=*a;
        *a=*b;
        *b=t;
    }

    int wartosc(int x)
    {
        return x;
    }

    void scalanie (T quicktab[], int l, int m, int h)
    {
        int tmp [h-l];
        int i=l, j=m+1, k=0;;//zmienne pomocnicze
        while (i <= m && j <= h)
        {
            if (quicktab[j] < quicktab[i])
            {
                tmp[k] = quicktab[j];
                j++;
            }
            else
            {
                tmp[k] = quicktab[i];
                i++;
            }
            k++;
        }
        if (i <= m)
        {
            while (i <= m)
            {
                tmp[k] = quicktab[i];
                i++;
                k++;
            }
        }
        else
        {
            while (j <= h)
            {
                tmp[k] = quicktab[j];
                j++;
                k++;
            }
        }

        for (i = 0; i<=(h-l); i++)
        {
            quicktab[l+i] = tmp[i];
        }
    }

    void sortowanie(T A[], int l, int h)
    {
        int srodek;
        if (l < h)
        {
            srodek=(l+h)/2;
            sortowanie(A, l, srodek);//rekurenycjne wywolanie sortowania lewej polowy tablicy
            sortowanie(A, srodek + 1, h);//rekurenycjne wywolanie sortowania prawej polowy tablicy
            scalanie(A, l, srodek, h);
        }

    }

};

#endif
