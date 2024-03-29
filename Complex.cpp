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
	Complex t;
	t._real = _real*z.real() - _imag*z.imag();
	t._imag = _real*z.imag() + _imag*z.real();
	*this = t;
	return *this;
}
Complex& Complex::operator/=(const Complex& z)
{
	Complex t;
	t._real = (_real*z.real() + _imag*z.imag()) / (z.real()*z.real() + z.imag()*z.imag());
	t._imag = (_imag*z.real() - _real*z.imag()) / (z.real()*z.real() + z.imag()*z.imag());
	*this = t;
	return *this;
}

// squared magnitude of z
double norm(const Complex& z)
{
	double nor;
	nor = z.real()*z.real() + z.imag()*z.imag();
	return nor;
}
// complex conjugate of z
Complex conj(const Complex& z)
{
	Complex ans (z.real(), -z.imag());
	return ans;
}

// basic math operations
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
	double numReal = (a.real() * b.real()) - (a.imag() * -b.imag());
	double numImag = (a.imag() * b.real()) + (a.real() * -b.imag());
	double denominator = (b.real() * b.real()) + (b.imag() * b.imag());
	double real = numReal / denominator;
	double imag = numImag / denominator;
	Complex ans(real, imag);
	return ans;
}

// comparison
bool operator==(const Complex& a, const Complex& b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
bool operator==(const Complex& a, double r)
{
	return (a.real() == r) && (a.imag() == 0);
}
bool operator!=(const Complex& a, const Complex& b)
{
	return (a.real() != b.real()) || (a.imag() != b.imag());
}
bool operator!=(const Complex& a, double r)
{
	return (a.real() != r) || (a.imag() != 0);
}

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	if(z.imag() >= 0)
		out << z.real() << "+" << z.imag() << "i";
	else
		out << z.real() << z.imag() << "i";
	return out;
}
