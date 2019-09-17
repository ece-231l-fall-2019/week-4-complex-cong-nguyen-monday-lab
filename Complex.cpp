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
	return tmp._real;
}

double Complex::imag() const
{
	Complex tmp;
	tmp._imag = _imag;
	return _imag;
}
