#include <iostream>
#include <fstream> // Writes
#include <istream> // Reads
#include <string>
#include <random>

/*
#include <cstdlib>
#include <ctime>
*/

using namespace std;

typedef int** matrix;
typedef double** matrixD;

void pamiecNew(matrix& b, const int& m_, const int& n_);
void pamiecDel(matrix& b, const int& m_, const int& n_);
int wypelnij(matrix& b, const int& m_, const int& n_, const int& w);
int wyswietl(matrix& c, const int& m_, const int& n_);
int wypelniej_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ);
int read_from_file(string nazwaPliku, matrix& b, const int& m_, const int& n_);

int dodawanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
int odejmowanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
int mnozenie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);

int main() 
{
	// STEP 1
	/*
	matrix A,B;
	int m = 3;
	int n = 4;

	cout << "Macierz A: \n";

	pamiecNew(A, m, n);
	wypelnij(A, m, n, 1);
	wyswietl(A, m, n);
	pamiecDel(A, m, n);
	
	cout << "Macierz B: \n";

	pamiecNew(B, m, m);
	wypelnij(B, m, m, 1);
	wyswietl(B, m, m);
	pamiecDel(B, m, m);

	cout << "Macierz B: \n";

	pamiecNew(B, m, m);
	wypelniej_los(B,m,m,1,5);
	wyswietl(B, m, m);
	pamiecDel(B, m, m);
	*/

	// STEP 2

	matrix A,B,C,D,E,F,G,H,I,J,K,W1,W2;
	int m = 3;
	int n = 5;
	int e = 4;

	pamiecNew(W1, m, n);	
	pamiecNew(W2, n, e);	

	pamiecNew(A, m, n);	//mA
	pamiecNew(B, m, n);	//mB
	pamiecNew(C, n, e);	//mC
	pamiecNew(D, n, e);	//mC
	pamiecNew(E, n, e);	//mC
	pamiecNew(G, n, e);	//mC
	pamiecNew(H, n, e);	//mC
	pamiecNew(I, n, n);	//mC
	pamiecNew(J, n, n);	//mC
	pamiecNew(K, e, e);	//mC
	

	read_from_file("mA.txt", A, m, n);
	read_from_file("mB.txt", B, m, n);
	read_from_file("mC.txt", C, n, e);
	read_from_file("mD.txt", D, n, e);
	read_from_file("mE.txt", E, n, e);
	read_from_file("mG.txt", G, n, e);
	read_from_file("mH.txt", H, n, e);
	read_from_file("mI.txt", I, n, n);
	read_from_file("mJ.txt", J, n, n);
	read_from_file("mK.txt", K, e, e);

	/*
	std::cout << "\nMacierz A: \n";
	wyswietl(A, m, n);
	std::cout << "\nMacierz B: \n";
	wyswietl(B, m, n);
	*/
	std::cout << "\nMacierz C: \n";
	wyswietl(C, n, e);
	std::cout << "\nMacierz D: \n";
	wyswietl(D, n, e);
	

	dodawanie(W1, A, B, m, n);
	std::cout << "\nMacierz A+B: \n";
	wyswietl(W1, m, n);

	odejmowanie(W2, C, D, n, e);
	std::cout << "\nMacierz C-D: \n";
	wyswietl(W2, n, e);




	pamiecDel(A, m, n);
	pamiecDel(B, m, n);
	pamiecDel(C, n, e);
	pamiecDel(D, n, e);
	pamiecDel(E, n, e);
	pamiecDel(G, n, e);
	pamiecDel(H, n, e);
	pamiecDel(I, n, n);
	pamiecDel(J, n, n);
	pamiecDel(K, e, e);
	return 0;
}


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

int wypelnij(matrix& b, const int& m_, const int& n_, const int& w)	// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			b[i][j] = w;
		}
	}
	return 0;
}

int wyswietl(matrix& c, const int& m_, const int& n_)// void possible
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			cout << "\t" << c[i][j];
		}
		cout << endl;
	}
	return 0;
}

int wypelniej_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ)
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
	return 0;
}

int read_from_file(string nazwaPliku, matrix& b, const int& m_, const int& n_)
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
	return 0;
}

int dodawanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = a[i][j] + b[i][j];
		}
	}
	return 0;
}

int odejmowanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_)
{
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			w[i][j] = a[i][j] - b[i][j];
		}
	}
	return 0;
}

int mnozenie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_)
{
	// Bruh
	int sum = 0;
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			sum = a[i][j] * b[j][i]; // +
			

		}

		for (int n = 0; n < m_; ++n)
		{
			w[i][n] = sum;
		}
	}
	return 0;
}