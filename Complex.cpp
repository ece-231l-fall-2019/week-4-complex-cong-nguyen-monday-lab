#include "Complex.h"

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
	Complex tmp;
	tmp._real = _real;
	return _real;
}

double Complex::imag() const
{
	Complex tmp;
	tmp._imag = _imag;
	return _imag;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex ans(a.real() + b.real(), a.imag() + b.imag());
	return ans;
}

bool operator==(const Complex& a, const Complex& b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
