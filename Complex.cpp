#include "Complex.h"
//There are 2 issues somewhere in this code. When you find them,
//create an issue on GitHub for each
Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;

}

Complex::Complex(double re, double im)
{
	_real = re;
	_imag = im;
}

Complex::Complex(const Complex& z)
{
	_real = z._real;
	_imag = z._imag;
}

double Complex::real() const
{
	return _real;
}

double Complex::imag() const
{
	return _imag;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex ans(a.real() + b.real(), a.imag() + b.imag());
	return ans;
}

Complex operator-(const Complex a, const Complex& b)
{
	Complex ans(a.real() - b.real(), a.imag() - b.imag());
	return ans;
}

Complex operator*(const Complex& a, Complex& b)
{
	//Using the model (a+bi)(c+di)
	int firsts = a.real() * b.real(); //Real components (a * c)
	int lasts = a.imag() * b.imag(); // Imaginary components (bi * di)
	int inners = a.imag() * b.real(); //First imaginary with second real (bi * c)
	int outers = a.real() * b.imag(); // Second imaginary with first real (a * di)

	int real = firsts - lasts; // Real component (subtracted because i^2 = -1)
	int imag = inners + outers; // Imaginary component

	Complex ans(real, imag);
	return ans;
}

bool operator==(const Complex& a, const Complex& b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
