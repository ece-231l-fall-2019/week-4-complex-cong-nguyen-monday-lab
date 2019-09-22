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
	double ans1 = 25;
	double ans2 = 4;
	double ans3 = 5;
	//Comparison (necessary for everything else)
	Assert(norm(z1) == ans1, "real constructor"); 	//1
	Complex z8(4, 0);
	Assert(z8 == ans2, "real constructor");		//2
	Assert(z1 != z2, "real constructor");		//3
	Assert(z1 != ans3, "real constructor");		//4

	//Assignment
	double eqOpTest = 8;
	Complex eqOpTest2(16, 22);

	Complex AssnTest1(8, 0);
	Complex AssnTest2(16, 22);
	Complex z3(0, 0);
	z3 = eqOpTest;
	Complex z4(0, 0);
	z4 = eqOpTest2;

	Assert(z3 == AssnTest1, "real constructor");	//5
	Assert(z4 == AssnTest2, "real constructor");	//6

	z3 += Complex(1, 1);
	Assert(z3 == Complex(9, 1), "real constructor");	//7
	z3 *= Complex (2, 2);
	Assert(z3 == Complex(16, 20), "real constructor");	//8

	//Cong Nguyen test
	Complex z5(3,4);
	Complex z6(-6,7);
	Complex z7(2,-5);
	Complex z9(2,-5);
	Complex z10(0,5);
	Complex z11(-7,0);
	Complex z12(1,1);
	Complex ans5(9,11);
	Complex ans6(-6,2);
	Complex ans7(23,44);
	Complex ans8(1.2,-0.6);
	//Test Comparsion ==
	Assert(z5 == z6, "Test comparion =="); //9
	Assert(z7 == z9, "Test comparion =="); //10
	//Test basic math operations
	Assert(z5 + z6 == ans5, "Test basic math +"); //11
	Assert(z6 - z10 == ans6, "Test basic math -"); //12
	Assert(z6 * z7 == ans7, "Test basic math *"); //13
	Assert(z5 * z10 == ans7, "Test basic math *"); //14

	Complex ans9;
	ans9 = z12 / z10;
	std::cout << ans9 << std::endl;
	Assert(z12 / z10 == ans8, "Test basic math /"); //15
	//Test conjugate
	Complex z13, z14;
	z13 = conj(z5);
	z14 = conj(z7);
	Complex ans12(2,5);
	Complex ans11(3,-4);
	Assert(z13 == ans11, "Test conjugate"); //15
	Assert(z14 == ans12, "Test conjugate"); //16
	//Test output
	std::cout << "Vector z13: " << z13 << std::endl; //17
	std::cout << "Vector z5: " << z5 << std::endl; //18
	std::cout << "Vector z11: " << z11 << std::endl; //19

	return 0;
}
