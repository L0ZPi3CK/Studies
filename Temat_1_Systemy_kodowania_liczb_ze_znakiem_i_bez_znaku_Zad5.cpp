#include <iostream>
#include <iomanip>
int main() 
{
	double a = 0.1;
	double b = 0.2;
	double c = a + b;
	if (fabs(c) == 0.1 + 0.2)
	{
		std::cout << std::fixed << std::setprecision(20);	//optional
		std::cout << "suma=" << c << std::endl;
	}
	return 0;
}