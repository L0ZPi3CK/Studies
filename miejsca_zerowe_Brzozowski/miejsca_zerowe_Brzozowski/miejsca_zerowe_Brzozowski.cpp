#include <iostream>
#include "Funkcje.h"

double funcFx(double x);
void metoda_Bisekcji(double a, double b, int m, double exp_result);

int main()
{
    metoda_Bisekcji(0, 9, 10, 1.88965);
}

double funcFx(double x)
{
    return 1.4 * (x * x * x) - 268 * x + 497;
}

void metoda_Bisekcji(double a, double b, int m, double exp_result)
{
    double x1 = a, x2 = b;
    double xi = 0;

    for (int i = 0; i < m; i++)
    {
        xi = (x1 + x2) / 2;
        if (funcFx(x1) * funcFx(xi) < 0)
        {
            x2 = xi;
        }
        else
            x1 = xi;
    }

    cout << "xi: " << xi;
    cout << "\nExpected result: " << (xi - exp_result) << endl;


}