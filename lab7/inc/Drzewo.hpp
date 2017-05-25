#ifndef DRZEWO_HPP
#define DRZEWO_HPP

#include <string>
#include<iostream>

#include "iTree.hpp"
#include "Lisc.hpp"

class Drzewo : public iTree
{
private:

    Lisc *korzen;

    void usungalaz(Lisc * to_release);
    void LL(Lisc * A);
    void RR(Lisc * A);
    void LR(Lisc * A);
    void RL(Lisc * A);
    void display(Lisc * to_display,int level);

public:
    Drzewo();
    ~Drzewo();
    bool is_empty() const;
    void insert(int x);
    void remove(int x);
    int search(int x);
    void fill(int x);
    void perform_run(unsigned int size, char option);
    void flush();
    void prepare(unsigned int size,char option);
    void print();
};

void Drzewo::usungalaz(Lisc * to_release)
{
    if(to_release)
    {
        usungalaz(to_release->get_lewy());
        usungalaz(to_release->get_prawy());
        delete to_release;
    }
}

void Drzewo::display(Lisc *to_display, int level)
{
    int i;
    if (to_display)
    {
        display(to_display->get_prawy(), level + 1);
        printf("\n");
        if (to_display == korzen)
        {
            std::cout << "korzen -> ";
        }
        for (i = 0; i < level && to_display != korzen; i++)
        std::cout << "        ";
        std::cout << to_display->get_wartosc();
        display(to_display->get_lewy(), level + 1);
    }
}

void Drzewo::LL(Lisc *A)
{
    Lisc *B = A->get_lewy();
    Lisc *p = A->get_rodzic();
    A->set_lewy(B->get_prawy());
    if (A->get_lewy())
    {
        A->get_lewy()->set_rodzic(A);
    }
    B->set_prawy(A);
    B->set_rodzic(p);
    A->set_rodzic(B);
    if (p)
    {
        if (p->get_lewy() == A)
        {
            p->set_lewy(B);
        }
        else
        {
            p->set_prawy(B);
        }
    }
    else
    {
        korzen = B;
    }
    if (B->get_balans() == 1)
    {
        A->set_balans(0);
        B->set_balans(0);
    }
    else
    {
        A->set_balans(1);
        B->set_balans(-1);
    }
}

void Drzewo::RR(Lisc *A)
{
    Lisc *B = A->get_prawy();
    Lisc *p = A->get_rodzic();
    A->set_prawy(B->get_lewy());
    if (A->get_prawy())
    {
        A->get_prawy()->set_rodzic(A);
    }
    B->set_lewy(A);
    B->set_rodzic(p);
    A->set_rodzic(B);
    if (p)
    {
        if (p->get_lewy() == A)
        {
            p->set_lewy(B);
        }
        else
        {
            p->set_prawy(B);
        }
    }
    else
    {
        korzen = B;
    }
    if (B->get_balans() == -1)
    {
        A->set_balans(0);
        B->set_balans(0);
    }
    else
    {
    A->set_balans(-1);
    B->set_balans(1);
    }
}

void Drzewo::LR(Lisc *A)
{
    Lisc *B = A->get_lewy();
    Lisc *C = B->get_prawy();
    Lisc *p = A->get_rodzic();
    B->set_prawy(C->get_lewy());
    if (B->get_prawy())
    {
        B->get_prawy()->set_rodzic(B);
    }
    A->set_lewy(C->get_prawy());
    if (A->get_lewy())
    {
        A->get_lewy()->set_rodzic(A);
    }
    C->set_prawy(A);
    C->set_lewy(B);
    A->set_rodzic(C);
    B->set_rodzic(C);
    C->set_rodzic(p);
    if (p)
    {
        if (p->get_lewy() == A)
        {
            p->set_lewy(C);
        }
        else
        {
            p->set_prawy(C);
        }
    }
    else
    {
        korzen = C;
    }
    if (C->get_balans() == 1)
    {
        A->set_balans(-1);
    }
    else
    {
        A->set_balans(0);
    }
    if (C->get_balans() == -1)
    {
        B->set_balans(1);
    }
    else
    {
        B->set_balans(0);
    }
    C->set_balans(0);
}

void Drzewo::RL(Lisc *A)
{
    Lisc *B = A->get_prawy();
    Lisc *C = B->get_lewy();
    Lisc *p = A->get_rodzic();
    B->set_lewy(C->get_prawy());
    if (B->get_lewy())
    {
        B->get_lewy()->set_rodzic(B);
    }
    A->set_prawy(C->get_lewy());
    if (A->get_prawy())
    {
        A->get_prawy()->set_rodzic(A);
    }
    C->set_lewy(A);
    C->set_prawy(B);
    A->set_rodzic(C);
    B->set_rodzic(C);
    C->set_rodzic(p);
    if (p)
    {
        if (p->get_lewy() == A)
        {
            p->set_lewy(C);
        }
        else
        {
            p->set_prawy(C);
        }
    }
    else
    {
        korzen = C;
    }
    if (C->get_balans() == -1)
    {
        A->set_balans(1);
    }
    else
    {
        A->set_balans(0);
    }
    if (C->get_balans() == 1)
    {
        B->set_balans(-1);
    }
    else
    {
        B->set_balans(0);
    }
    C->set_balans(0);
}

void Drzewo::insert(int x)
{
    Lisc *w;
    Lisc *p;
    Lisc *r;
    bool t;
    w = new Lisc(x);
    p = korzen;
    if (!p)
    {
        korzen = w;
    }
    else
    {
        while (true)
        {
            if (x < p->get_wartosc())
            {
                if (!p->get_lewy())
                {
                    p->set_lewy(w);
                    break;
                }
                p = p->get_lewy();
            }
            else
            {
                if (!p->get_prawy())
                {
                    p->set_prawy(w);
                    break;
                }
            p = p->get_prawy();
            }
        }
        w->set_rodzic(p);
        if (p->get_balans())
        {
            p->set_balans(0);
        }
        else
        {
            if (p->get_lewy() == w)
            {
                p->set_balans(1);
            }
            else
            {
                p->set_balans(-1);
            }
            r = p->get_rodzic();
            t = false;
            while (r)
            {
                if (r->get_balans())
                {
                    t = true;
                    break;
                }
                if (r->get_lewy() == p)
                {
                    r->set_balans(1);
                }
                else
                {
                    r->set_balans(-1);
                }
                p = r;
                r = r->get_rodzic();
            }
            if (t)
            {
                if (r->get_balans() == 1)
                {
                    if (r->get_prawy() == p)
                    {
                        r->set_balans(0);
                    }
                    else
                    {
                        if (p->get_balans() == -1)
                        {
                            LR(r);
                        }
                        else
                        {
                            LL(r);
                        }
                    }
                }
                else
                {
                    if (r->get_lewy() == p)
                    {
                        r->set_balans(0);
                    }
                    else
                    {
                        if (p->get_balans() == 1)
                        {
                            RL(r);
                        }
                        else
                        {
                            RR(r);
                        }
                    }
                }
            }
        }
    }
}

Drzewo::Drzewo()
{
    korzen=nullptr;
}

Drzewo::~Drzewo()
{
    usungalaz(korzen);
    korzen = nullptr;
}

bool Drzewo::is_empty() const
{
    if(korzen) return false;
    else return true;
}

int Drzewo::search(int x)
{
    Lisc* p =korzen;
    while(p && p->get_wartosc() !=x)
    {
        if(x < p->get_wartosc())
        {
            p=p->get_lewy();
        }
        else
        {
            p=p->get_prawy();
        }
    }
    if(p)
    {
        return p->get_wartosc();
    }
    else
    {
        return 0;
    }
}

void Drzewo::fill(int x)
{
    for(int i=1;i<=x;i++)
    {
        insert(i);
    }
}

void Drzewo::flush()
{

    if(korzen)
    {
        usungalaz(korzen);
        korzen=nullptr;
    }
}

void Drzewo::print()
{
    display(korzen, 1);
}


#endif
