#include <iostream>

// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if 1
#include "Complex.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}


int main()
{
	Complex z1(4, 3);
	Complex z2(2, 5);
	Complex ans1(6, 8); //Addition
	Complex ans2(2, -2); //Subtraction
	Complex ans3(-7, 26); //Multiplication
	Complex ans4(0.79, -0.48); //Division
	Assert(z1.real() == 4, "real constructor");
	Assert(z1.imag() == 3, "real constructor");
	Assert(z1 + z2 == ans1, "real constructor");
	Assert(z1 - z2 == ans2, "real constructor");
	Assert(z1 * z2 == ans3, "real constructor");
	Assert(z1 / z2 == ans4, "real constructor");
	//Commented out for now
	//Assert(norm(z1) == 25, "complex norm");


	// TODO:
	// Write *at least* 20 more tests to fully test
	// your Complex class.


	return 0;
}


