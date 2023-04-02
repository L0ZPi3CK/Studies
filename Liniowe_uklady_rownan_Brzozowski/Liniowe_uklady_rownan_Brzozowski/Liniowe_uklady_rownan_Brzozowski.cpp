#include "Funkcje.h"
#include <iostream>

void eliminacja_Gaussa(matrixD& c, int n);

int main()
{
    matrixD aG;
    pamiecNew(aG, 5, 6);
    read_from_file("array_gauss.txt",aG, 5, 6);
    wyswietl(aG, 5, 6);

    eliminacja_Gaussa(aG, 5);

}

void eliminacja_Gaussa(matrixD& c, int n)
{
    double* x = new double[n];


    for (int s = 0; s < n - 1; s++)
    {
        for (int i = s + 1; i < n; i++)
        {
            for (int j = s + 1; j < n + 1; j++)
            {
                c[i][j] = c[i][j] - ((c[i][s] / c[s][s]) * c[s][j]);
            }
        }
    }
    
    x[n - 1] = (c[n - 1][n] / c[n - 1][n - 1]);

    // n-2?
    for (int i = n-2; i >= 0; i--)
    {
        double suma = 0;

        for (int s = i+1; s < n; s++)
        {
            suma = (suma + (c[i][s] * x[s]));
        }
        x[i] = ((c[i][n] - suma) / c[i][i]);
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }

}
