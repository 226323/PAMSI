#ifndef LISC_HPP
#define LISC_HPP

#include<iostream>



class Lisc
{

private:
  int wartosc;
  Lisc *lewy;
  Lisc *prawy;
  Lisc *rodzic;
  int balans;

public:

    Lisc()
    {
        wartosc=0;
        lewy=nullptr;
        prawy=nullptr;
        rodzic=nullptr;
        balans=0;
    }

    Lisc(int x)
    {
        wartosc=x;
        lewy=nullptr;
        prawy=nullptr;
        rodzic=nullptr;
        balans=0;
    }

    ~Lisc() {}

    int get_balans()
    {
        return balans;
    }

    int get_wartosc()
    {
        return wartosc;
    }

    Lisc *get_prawy()
    {
        return prawy;
    }

    Lisc *get_lewy()
    {
        return lewy;
    }

    Lisc *get_rodzic()
    {
        return rodzic;
    }

    void set_balans(int x)
    {
        balans = x;
    }

    void set_wartosc(int x)
    {
        wartosc = x;
    }

    void set_rodzic(Lisc &x)
    {
        rodzic = &x;
    }

    void set_lewy(Lisc &x)
    {
        lewy = &x;
    }

    void set_prawy(Lisc &x)
    {
        prawy = &x;
    }

    void set_wartosc(int *x)
    {
        wartosc = *x;
    }

    void set_rodzic(Lisc *x)
    {
        rodzic = x;
    }

    void set_lewy(Lisc *x)
    {
        lewy = x;
    }

    void set_prawy(Lisc *x)
    {
        prawy = x;
    }

bool has_lewy()
{
    if (lewy == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool has_prawy()
{
    if (prawy == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool has_rodzic()
{
    if (rodzic == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_external()
{
    if ((!has_lewy()) && (!has_prawy()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

};

#endif
