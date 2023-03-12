#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

typedef int** matrix;
typedef double** matrixD;
												/*DECLARATIONS*/

// For int** matrix;
void pamiecNew(matrix& b, const int& m_, const int& n_);
void pamiecDel(matrix& b, const int& m_, const int& n_);
void wypelnij(matrix& b, const int& m_, const int& n_, const int& w);
void wyswietl(matrix& c, const int& m_, const int& n_);
void wypelniej_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ);
void read_from_file(string nazwaPliku, matrix& b, const int& m_, const int& n_);
void save_to_file(string nazwaPliku, matrix& b, const int& m_, const int& n_);

// For double** matrixD;
void pamiecNew(matrixD& b, const int& m_, const int& n_);
void pamiecDel(matrixD& b, const int& m_, const int& n_);
void wypelnij(matrixD& b, const int& m_, const int& n_, const int& w);
void wyswietl(matrixD& c, const int& m_, const int& n_);
void wypelniej_los(matrixD& b, const int& m_, const int& n_, const int& minZ, const int& maxZ);
void read_from_file(string nazwaPliku, matrixD& b, const int& m_, const int& n_);
void save_to_file(string nazwaPliku, matrixD& b, const int& m_, const int& n_);
double macierz_odwrotna_kwadratowa(matrixD& w, const matrix& a, const int& n_);

// Functions for int** matrix
void dodawanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
void odejmowanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
void mnozenie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_, const int& k_);
void mnozenie(matrix& w, matrix& a, const int& m_, const int& n_, const int& number);
void transponowanie(matrix& w, matrix& a, const int& m_, const int& n_);

// Functions for double** matrixD;
double wyznacznik_kwadratowy(matrixD& a, const int& m_);


// INTERPOLACJA
void interp_lag(const int& n, double* x, double* y);
void inter_tryg(const int& n, const int& m, double* x, double* y, matrixD X, matrixD XT, double* a);
double f(double x);
double xi(int n, int i);
double Fi(int j, double x);

															/*DEFINITIONS*/

// ###################################################################################################

void pamiecNew(matrix& b, const int& m_, const int& n_)
{
	b = new int* [m_];
	for (int i = 0; i < m_; i++)
	{
		b[i] = new int[n_];
	}
}

void pamiecDel(matrix& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		delete[]b[i];
	}
	delete[]b;
}

void wypelnij(matrix& b, const int& m_, const int& n_, const int& w)	// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			b[i][j] = w;
		}
	}
}

void wyswietl(matrix& c, const int& m_, const int& n_)// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			cout << "\t" << c[i][j];
		}
		cout << endl;
	}
}

void wypelniej_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ)
{
	int zakres = maxZ - minZ + 1;
	srand(time(NULL));
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			b[i][j] = rand() % zakres + minZ;
		}
	}
}

void read_from_file(string nazwaPliku, matrix& b, const int& m_, const int& n_)
{
	ifstream plikA;
	plikA.open(nazwaPliku.c_str());

	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			plikA >> b[i][j];
		}
	}
	plikA.close();
}

void save_to_file(string nazwaPliku, matrix& b, const int& m_, const int& n_)
{
	ofstream plikA;
	plikA.open(nazwaPliku);

	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			plikA << b[i][j] << "\t";
		}
		plikA << "\n";
	}

	plikA.close();
}

// ###################################################################################################

void pamiecNew(matrixD& b, const int& m_, const int& n_)
{
	b = new double* [m_];
	for (int i = 0; i < m_; i++)
	{
		b[i] = new double[n_];
	}
}

void pamiecDel(matrixD& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		delete[]b[i];
	}
	delete[]b;
}

void wypelnij(matrixD& b, const int& m_, const int& n_, const int& w)	// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			b[i][j] = w;
		}
	}
}

void wyswietl(matrixD& c, const int& m_, const int& n_)// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			cout << "\t" << c[i][j];
		}
		cout << endl;
	}
}

void wypelniej_los(matrixD& b, const int& m_, const int& n_, const int& minZ, const int& maxZ)
{
	int zakres = maxZ - minZ + 1;
	srand(time(NULL));
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			b[i][j] = rand() % zakres + minZ;
		}
	}
}

void read_from_file(string nazwaPliku, matrixD& b, const int& m_, const int& n_)
{
	ifstream plikA;
	plikA.open(nazwaPliku.c_str());

	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			plikA >> b[i][j];
		}
	}
	plikA.close();
}

void save_to_file(string nazwaPliku, matrixD& b, const int& m_, const int& n_)
{
	ofstream plikA;
	plikA.open(nazwaPliku);

	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			plikA << b[i][j] << "\t";
		}
		plikA << "\n";
	}

	plikA.close();
}

// ############################################################################

void dodawanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = a[i][j] + b[i][j];
		}
	}
}

void odejmowanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = a[i][j] - b[i][j];
		}
	}
}

/*
	m_ - number of rows of the matrix a
	n_ - number of columns of the matrix a || number of rows of the matrix b
	k_ - number of columns of the matrix b
*/
void mnozenie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_, const int& k_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = 0;
		}
	}

	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			for (int s = 0; s < k_; s++)
			{
				w[i][j] += a[i][s] * b[s][j];
			}
		}
	}
}

void mnozenie(matrix& w, matrix& a, const int& m_, const int& n_, const int& number)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = a[i][j] * number;
		}
	}
}

void transponowanie(matrix& w, matrix& a, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[j][i] = a[i][j];
		}
	}
}

double wyznacznik_kwadratowy(matrixD& a, const int& m_)
{
	double det = a[0][0];
	for (unsigned short s = 0; s < m_ - 1; ++s)
	{
		for (unsigned short i = s + 1; i < m_; ++i)
		{
			for (unsigned short j = s + 1; j < m_; j++)
			{
				a[i][j] = a[i][j] - ((a[i][s] / a[s][s]) * a[s][j]);
			}
		}
		det = det * a[s + 1][s + 1];
	}
	return det;
}

double macierz_odwrotna_kwadratowa(matrixD& w, const matrix& a, const int& n_)
{
	matrixD B;
	pamiecNew(B, n_, 2 * n_);

	for (unsigned short i = 0; i < n_; ++i)
	{
		for (unsigned short j = 0; j < n_; ++j)
		{
			B[i][j] = a[i][j];
		}
	}

	for (unsigned short i = 0; i < n_; ++i)
	{
		for (unsigned short j = 0; j < n_; ++j)
		{
			B[i][j + n_] = 0;
		}
	}

	for (unsigned short i = 0; i < n_; ++i)
	{
		B[i][i + n_] = 1;
	}

	wyswietl(B, n_, 2 * n_);
	std::cout << "\n\n";

	for (unsigned short s = 0; s < n_; s++)
	{
		double c = B[s][s];
		double d;
		B[s][s] = B[s][s] - 1;
		for (unsigned short j = s + 1; j < 2 * n_; j++)
		{
			d = B[s][j] / c;
			for (unsigned short i = 0; i < n_; i++)
			{
				B[i][j] = B[i][j] - d * B[i][s];
			}
		}
	}

	for (int i = 0; i < n_; i++)
	{
		for (int j = 0; j < n_; j++)
		{
			w[i][j] = B[i][j + n_];
		}
	}
	//pamiecDel(B, n_, 2 * n_);
	return 0;
}

// INTERPOLACJA
double f(double x)
{
	return ((1.33 * (x * x)) - 4.89 * x + 1.94);
}

double xi(int n, int i)
{
	return ((2 * i * M_PI) / (2 * n + 1));
}

double Fi(int j, double x)
{
	if (j == 0)
	{
		return 1.0 / sqrt(2);
	}
	else
	{
		if (j % 2 == 1)
		{
			return sin(((j + 1) / 2) * x);
		}
		else
		{
			return cos(((j + 1) / 2) * x);
		}
	}
}

void interp_lag(const int& n, double* x, double* y)
{
	double a, b, c;

	a = (y[0] / ((x[0] - x[1]) * (x[0] - x[2]))) + ((y[1] / ((x[1] - x[0]) * (x[1] - x[2])))) + ((y[2] / ((x[2] - x[0]) * (x[2] - x[1]))));
	b = -(y[0] * (x[1] + x[2])) / ((x[0] - x[1]) * (x[0] - x[2])) - ((y[1] * (x[0] + x[2])) / ((x[1] - x[0]) * (x[1] - x[2]))) - ((y[2] * (x[0] + x[1]))) / ((x[2] - x[0]) * (x[2] - x[1]));
	c = (y[0] * x[1] * x[2]) / ((x[0] - x[1]) * (x[0] - x[2])) + (y[1] * x[0] * x[2]) / ((x[1] - x[0]) * (x[1] - x[2])) + (y[2] * x[0] * x[1]) / ((x[2] - x[0]) * (x[2] - x[1]));
	cout << "\nWspolcznynnik a: " << a;
	cout << "\nWspolcznynnik b: " << b;
	cout << "\nWspolcznynnik c: " << c;

}

void inter_tryg(const int& n, const int& m, double* x, double* y, matrixD X, matrixD XT, double* a)
{
	for (int i = 0; i < m; i++)
	{
		x[i] = xi(n, i);
		y[i] = f(x[i]);
	}

	for (int i = 0; i < m; i++)
	{
		cout << setprecision(3) << x[i] << "\t";
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		cout << setprecision(3) << y[i] << "\t";
	}

	// Fill matrix X
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			X[i][j] = Fi(j, x[i]);
		}
	}

	cout << "Macierz X: " << endl;
	wyswietl(X, m, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			XT[j][i] = (2.0 / m) * X[i][j];
		}
	}

	cout << "Prawidlowe wyniki: " << endl;

	for (int i = 0; i < m; i++)
	{
		a[i] = 0;
		for (int j = 0; j < m; j++)
		{
			a[i] += XT[i][j] * y[j];
		}
		cout << setprecision(5) << "a[" << i << "] = " << a[i] << "\t";
	}
	cout << endl;
}
