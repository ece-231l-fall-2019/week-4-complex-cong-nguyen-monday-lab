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

	//Comparison (necessary for everything else)
	Assert(norm(z1) == 25, "real constructor");
	Assert(z1 == 4, "real constructor");
	Assert(z1 != z2, "real constructor");
	Assert(z1 != 5, "real constructor");

	//Assignment
	double eqOpTest = 8;
	Complex eqOpTest2(16, 23);

	Complex AssnTest1(8, 0);
	Complex AssnTest2(16, 22);
	Complex z3(0, 0);
	z3 = eqOpTest;
	Complex z4(0, 0);
	z4 = eqOpTest2;

	Assert(z3 == AssnTest1, "real constructor");
	Assert(z4 == AssnTest2, "real constructor");

	z3 += Complex(1, 1);
	Assert(z3 == Complex(9, 1), "real constructor");
	z3 *= Complex (2, 2);
	Assert(z3 == Complex(16, 20), "real constructor");

	z4 -= Complex(1, 1);
	Assert(z4 == Complex(15, 21), "real constructor");
	z4 /= Complex(3, 3);
	Assert(z4 == Complex(6, 1), "real constructor");

	// TODO:
	// Write *at least* 20 more tests to fully test
	// your Complex class.


	return 0;
}


