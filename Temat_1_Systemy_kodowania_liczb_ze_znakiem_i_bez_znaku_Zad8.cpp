#include <iostream>
#include <bitset>
#include <limits>
#include <iomanip>

template<typename T>
void show_32_bits(T tmp)
{
	const unsigned int tmpSize = 32;
	unsigned long int bits = *(unsigned long int*) (&tmp);
	std::bitset<(tmpSize)> tmpBits(bits);
	std::cout << tmpBits << "\t" << tmpSize << " bits" << "\t" << std::fixed << std::setprecision(20) << tmp << std::endl;
}


template<typename T>
void show_64_bits(T tmp)
{
	const unsigned int tmpSize = 64;
	unsigned long long int bits = *(unsigned long long int*) (&tmp);
	std::bitset<(tmpSize)> tmpBits(bits);
	std::cout << tmpBits << "\t" << tmpSize << " bits"<<"\t" << std::fixed << std::setprecision(20) << tmp << std::endl;
}


int main() 
{
	float tmp = 5.0f;
	show_32_bits(tmp);

	// powy¿szy float traktowany jako int
	unsigned long int * tmp_as_int = (unsigned long int*) (&tmp);
	show_32_bits(*tmp_as_int);

	// zastanów siê jaka operacja na bitach mo¿e zamieniæ znak,
	// oraz jaka wartoœæ operanda dla zmiennej bit_1 bêdzie tutaj konieczna
	unsigned long int bit_1 = INT32_MAX+1;
	
	show_32_bits(bit_1);

	unsigned long int new_as_int = ((*tmp_as_int) ^ bit_1);
	show_32_bits(new_as_int);
	
	//nasz nowy float wydobyty z "inta"
	float new_tmp = *(float*)(&new_as_int);
	show_32_bits(new_tmp);

	return 0;
}