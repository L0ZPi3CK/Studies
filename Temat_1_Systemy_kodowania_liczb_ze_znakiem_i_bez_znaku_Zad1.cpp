#include <iostream>
#include <bitset>
#include <limits>
#include <iomanip>

template<typename T>
void show_32_bits(const T& tmp) 
{
	const unsigned int tmpSize = 32;
	unsigned long int bits = *(unsigned long int*) (&tmp);
	std::bitset<(tmpSize)> tmpBits(bits);

	std::cout << std::fixed << std::setprecision(20);
	std::cout << tmpBits << " ; " << tmp << " ; " << typeid(T).name() << " ; " << tmpSize << "bits" << std::endl;
}

template<typename T>
void show_64_bits(const T& tmp) 
{
	const unsigned int tmpSize = 64;
	unsigned long long int bits = *(unsigned long long int*) (&tmp);
	std::bitset<(tmpSize)> tmpBits(bits);

	std::cout << std::fixed << std::setprecision(20);
	std::cout << tmpBits << " ; " << tmp << " ; " << typeid(T).name() << " ; " << tmpSize << "bits" << std::endl;
}

int main() 
{
	int a[8] = { 0, 91, -91, 49, 12456, -1111, std::numeric_limits<int>::min() , std::numeric_limits<int>::max() };
	for ( int i : a)
	{
		show_32_bits(i);
	}

	std::cout << std::endl;

	/*
		-91		-> underflow resulted in 4294967205 value	(0 - 91		turns into 4 294 967 295 - 90)
		-1111	-> underflow resulted in 4294966185 value	(0 - 1111	turns into 4 294 967 295 - 1110)
	*/
	unsigned int ua[8] = { 0u, 91u, -91, 49u, 12456u, -1111, std::numeric_limits<unsigned int>::min() , std::numeric_limits<unsigned int>::max() };
	for (unsigned int i : ua)
	{
		show_32_bits(i);
	}

	std::cout << std::endl;

	float fa[8] = { 0.0f, 91.0f, -91.0f, 0.3f, 0.1f, 1234567.1234567f, std::numeric_limits<float>::min() , std::numeric_limits<float>::max() };
	for (float i : fa)
	{
		show_32_bits(i);
	}

	std::cout << std::endl;

	double da[8] = { 0.0, 91.0, -91.0, 0.3, 0.1, 1234567.1234567, std::numeric_limits<double>::min() , std::numeric_limits<double>::max() };
	for (double i : da)
	{
		show_64_bits(i);
	}
	return 0;
}