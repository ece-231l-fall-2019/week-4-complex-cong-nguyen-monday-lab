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
	Complex z2(4, 3);
	Complex z3(2, 5);
	double ans1 = 25;
	double ans2 = 4;
	double ans3 = 5;
	//Comparison (necessary for everything else)
	Assert(norm(z1) == ans1, "Comparison Test, Normalized Complex == Double"); 	//1
	Assert(z1 == z2, "Comparison Test, Complex == Complex");			//2
	Complex z4(4, 0);
	Assert(z4 == ans2, "Comparison Test, Complex == Real");				//3
	Assert(z2 != z3, "Comparison Test, Complex != Complex");			//4
	Assert(z1 != ans3, "Comparison Test, Complex != Real");				//5

	//Assignment
	double eqOpTest = 8;
	Complex z5_1(0, 0);
	Complex z6_1(0, 0);

	Complex eqOpTest2(16, 22);
	Complex AssnTest1(8, 0);
	Complex AssnTest2(16, 22);
	z5_1 = eqOpTest;
	z6_1 = eqOpTest2;

	Assert(z5_1 == AssnTest1, "Assignment Test, Real");				//6
	Assert(z6_1 == AssnTest2, "Assignment Test, Complex");				//7

	z5_1 += Complex(1, 1);
	Assert(z5_1 == Complex(9, 1), "Assignment Test, +=");				//8
	z5_1 *= z5_1;
	Assert(z5_1 == Complex(80, 18), "Assignment Test, *=");				//9

	z5_1 /= Complex(2, 2);
	Assert(z5_1 == Complex(9, 1), "Assignment Test, /=");				//10
	z5_1 -= Complex(1, 1);
	Assert(z5_1 == Complex(8, 0), "Assignment Test, -=");				//11

	//Cong Nguyen test
	Complex z5(3,4);
	Complex z6(-6,7);
	Complex z7(2,-5);
	Complex z9(2,-5);
	Complex z10(0,5);
	Complex z11(-7,0);
	Complex z12(1,1);
	Complex ans5(-3,11);
	Complex ans6(-6,2);
	Complex ans7(23,44);
	Complex ans8(0.2,-0.2);
	//Test Comparsion == @SteelMatrix has done the Comparisons already
	Assert(z5 != z6, "Test comparison =="); //9
	Assert(z7 == z9, "Test comparison =="); //10
	//Test basic math operations
	Assert(z5 + z6 == ans5, "Test basic math +"); 					//12
	Assert(z6 - z10 == ans6, "Test basic math -"); 					//13
	Assert(z6 * z7 == ans7, "Test basic math *"); 					//14
	Assert(z5 * z10 == ans7, "Test basic math *"); //14 (Already done above)

	Complex ans9;
	ans9 = z12 / z10;
	std::cout << ans9 << std::endl;
	Assert(z12 / z10 == ans8, "Test basic math /"); 				//15
	//Test conjugate
	Complex z13, z14;
	z13 = conj(z5);
	z14 = conj(z7);
	Complex ans12(2,5);
	Complex ans11(3,-4);
	Assert(z13 == ans11, "Test conjugate"); 					//16
	Assert(z14 == ans12, "Test conjugate"); 					//17
	//Test output
	std::cout << "Complex z13: " << z13 << std::endl; 				//18
	std::cout << "Complex z5: " << z5 << std::endl; 				//19
	std::cout << "Complex z11: " << z11 << std::endl; 				//20

	return 0;
}
