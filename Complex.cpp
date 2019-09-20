#include "Complex.h"
// Constructors
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

// Access
double Complex::real() const
{
	return _real;
}
double Complex::imag() const
{
	return _imag;
}

// Assignment
Complex& Complex::operator=(double r)
{
	_real = r;
	_imag = 0;
	return *this;
}
Complex& Complex::operator=(const Complex& z)
{
	_real = z.real();
	_imag = z.imag();
	return *this;
}
Complex& Complex::operator+=(const Complex& z)
{
	_real += z.real();
	_imag += z.imag();
	return *this;
}
Complex& Complex::operator-=(const Complex& z)
{
	_real -= z.real();
	_imag -= z.imag();
	return *this;
}
Complex& Complex::operator*=(const Complex& z)
{
	_real = _real*z.real() - _imag*z.imag();
	_imag = _real*z.imag() + _imag*z.real();
	return *this;
}
Complex& Complex::operator/=(const Complex& z)
{
	_real = (_real*z.real() + _imag*z.imag()) / (z.real()*z.real() + z.imag()*z.imag());
	_imag = (_imag*z.real() - _real*z.imag()) / (z.real()*z.real() + z.imag()*z.imag());
	return *this;
}

// norm returns the squared magnitude of z
double norm(const Complex& z)
{
	double nor;
	nor = z.real()*z.real() + z.img()*z.img()
	return nor;
}
// Comparison
bool operator==(const Complex& a, const Complex& b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
bool operator==(const Complex& a, double r)
{
	return (a.real() == r) && (a.img() == 0);
}
bool operator!=(const Complex& a, const Complex& b)
{
	return (a.real() != b.real()) || (a.img() != b.img());
}
bool operator!=(const Complex& a, double r)
{
	return (a.real() != r) || (a.img() != 0);
}
