#include <iostream>
#include "Funkcje.h"

// Plik danet.txt
// x    y   pochodna    monotonicznosc

// Dla pierwszego liczę punkt lewostronny
// Dla drugiego licze prawostronny
// Dla reszty centralny

// dane[n][2] + 
double f(matrixD dane, int x) { return 0; }

void Roznicznowanie(matrixD A, int n);

int main()
{  
    matrixD dane;
    pamiecNew(dane, 25, 4);
    read_from_file("dane.txt",dane,25,4);

    wyswietl(dane, 25, 4);

    // Roznicznowanie(dane,25);

    return 0;
}

void Roznicznowanie(matrixD A, int n)
{
    int pochodna = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i < 24)
        {
            //pochodna = 
        }
        else if (i == 0)
        {
            //pochodna = 
        }
        else if (i == 24)
        {
            //pochodna = 
        }
        else
        {
            std::cout << "WTF?";
        }
    }

}