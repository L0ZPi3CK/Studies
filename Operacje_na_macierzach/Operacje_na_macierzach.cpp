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
void wypelnij(matrix& b, const int& m_, const int& n_, const int& w);
void wyswietl(matrix& c, const int& m_, const int& n_);
void wypelniej_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ);
void read_from_file(string nazwaPliku, matrix& b, const int& m_, const int& n_);
void save_to_file(string nazwaPliku, matrix& b, const int& m_, const int& n_);

void dodawanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
void odejmowanie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_);
void mnozenie(matrix& w, matrix& a, matrix& b, const int& m_, const int& n_, const int& k_);
void mnozenie(matrix& w, matrix& a, const int& m_, const int& n_, const int & number);
void transponowanie(matrix& w, matrix& a, const int& m_, const int& n_);


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

	matrix A,B,C,D,E,F,G,H,I,J,K,W1,W2,W3;
	int m = 3;
	int n = 5;
	int e = 4;

	pamiecNew(W1, m, n);	
	pamiecNew(W2, n, e);	
	pamiecNew(W3, e, m);

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
	std::cout << "\nMacierz C: \n";
	wyswietl(C, n, e);
	std::cout << "\nMacierz H: \n";
	wyswietl(H, n, e);
	std::cout << "\nMacierz I: \n";
	wyswietl(I, n, n);
	*/

	dodawanie(W1, A, B, m, n);
	std::cout << "\nMacierz A + B: \n";
	wyswietl(W1, m, n);
	save_to_file("L1a.txt",W1, m, n);

	odejmowanie(W2, C, D, n, e);
	std::cout << "\nMacierz C - D: \n";
	wyswietl(W2, n, e);
	save_to_file("L1b.txt", W2, n, e);

	mnozenie(W2, E, n, e, 6);
	std::cout << "\nMacierz E * 6: \n";
	wyswietl(W2, n, e);
	save_to_file("L1c.txt", W2, n, e);

	mnozenie(W2, H, I, n, e, e);
	std::cout << "\nMacierz H * I: \n";
	wyswietl(W2, n, e);
	save_to_file("L1d.txt", W2, n, e);

	transponowanie(W3, G, m, e);
	std::cout << "\nMacierz G^T: \n";
	wyswietl(W3, e, m);
	save_to_file("L1e.txt", W3, e, m);

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

	pamiecDel(W1, m, n);
	pamiecDel(W2, n, e);
	pamiecDel(W3, e, m);
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