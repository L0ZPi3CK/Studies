#include "Funkcje.h"

void aproksymacja_f1z(matrixD& b, const int& n, matrixD& p);

int main()
{
	// APROKSYMACJA 1 ZMIENNEJ

	/*
	matrixD A,p1;
	
	int n = 8; // Liczba punktow do analizy
	int m = 2; // 1 - kolumna wartosc x, 2 - kolumna wartosc y

	pamiecNew(A, n, m);
	pamiecNew(p1, 2, 1);

	// Read from file
	read_from_file("a_f1zs.txt",A,n,m);

	cout << "Aproksymacja liniowa funkcji jednej zmiennej - dane wejsciowe: \n";
	wyswietl(A, n, m);
	cout << endl;

	aproksymacja_f1z(A, n, p1);

	cout << "p0 = " << p1[0][0] << "\np1 = " << p1[1][0];
	*/

	// APROKSYMACJA 2 ZMIENNYCH 

	matrixD B, p2;
	int n2 = 6;
	int m2 = 3;

	pamiecNew(B, n2, m2);
	pamiecNew(p2, 3, 1);

	read_from_file("a_f2z.txt", B, n2, m2);
	cout << "";

	return 0;
}

void aproksymacja_f1z(matrixD& b, const int& n, matrixD& p)
{
	double s1, s2, s3, s4;
	s1 = s2 = s3 = s4 = 0;

	for (int i = 0; i < n; i++)
	{
		s1 = s1 + b[i][0];
		s2 = s2 + b[i][1];
		s3 = s3 + b[i][0] * b[i][0];
		s4 = s4 + b[i][0] * b[i][1];
	}
	double w = (n * s3) - (s1 * s1);
	double w1 = (s2 * s3) - (s4 * s1);
	double w2 = (n * s4) - (s1 * s2);

	p[0][0] = w1 / w;
	p[1][0] = w2 / w;
}