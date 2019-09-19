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
	return _real;
}

double Complex::imag() const
{
	return _imag;
}

Complex conj(const Complex& z)
{
	Complex ans (z.real(), -z.imag());
	return ans;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex ans(a.real() + b.real(), a.imag() + b.imag());
	return ans;
}

Complex operator-(const Complex& a, const Complex& b)
{
	Complex ans(a.real() - b.real(), a.imag() - b.imag());
	return ans;
}

Complex operator*(const Complex& a, const Complex& b)
{
	int real = (a.real() * b.real()) - (a.imag() * b.imag()); // Real component (subtracted because i^2 = -1)
	int imag = (a.imag() * b.real()) + (a.real() * b.imag()); // Imaginary component

	Complex ans(real, imag);
	return ans;
}

Complex operator/(const Complex& a, const Complex& b)
{
	Complex numerator = (a * conj(b));
	int denominator = (b.real() * b.real()) + (b.imag() * b.imag());
	int real = numerator.real() / denominator;
	int imag = numerator.imag() / denominator;
	Complex ans(real, imag);
	return ans;
}

bool operator==(const Complex& a, const Complex& b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
