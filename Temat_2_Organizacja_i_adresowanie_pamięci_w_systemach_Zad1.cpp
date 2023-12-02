#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>

template <typename T>
void check(T& tmp)
{
	std::cout << "\n********************************** "<< typeid(T).name() << " **********************************\n" << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		int granica = 1 << i;

		//pobieramy adres zmiennej „tmp” i zapisujemy jego wartość w zmiennej „adres”
		long long adres = (long long)&tmp;

		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		if (adres % granica)
		{
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica << " bajtow.";
		}
		else
		{
			std::cout << "Adres jest dopasowany do badanej granicy " << granica << " bajtow.";
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}
}

int main() 
{
	
	char	tmp_char;		//3
	int		tmp_int;		//3
	float	tmp_float;		//3
	double	tmp_double;		//4
	__m128i tmp___m128i;	//5
	__m256i tmp___m256i;	//6

	check(tmp_char);
	check(tmp_int);
	check(tmp_float);
	check(tmp_double);
	check(tmp___m128i);
	check(tmp___m256i);
	
	// Czasem dla m256i program pokazuje granicę 64 bajtow a czasem nawet 128 bajtow niezależnie czy stosuję kod poniżej czy powyżej

	/*
	__m256i tmp;
	for (int i = 0; i < 8; ++i)
	{
		int granica = 1 << i;

		//pobieramy adres zmiennej „tmp” i zapisujemy jego wartość w zmiennej „adres”
		long long adres = (long long)&tmp;

		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		if (adres % granica)
		{
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica << " bajtow.";
		}
		else
		{
			std::cout << "Adres jest dopasowany do badanej granicy " << granica << " bajtow.";
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}
	*/
	return 0;
}

