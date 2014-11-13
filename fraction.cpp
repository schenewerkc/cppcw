#include "fraction.h"
#include "util.h"
#include <utility>
#include <iostream>

fraction::fraction() : _numerator(0), _denominator(1) {}

fraction::fraction(int n) : _numerator(n), _denominator(1) {}

fraction::fraction(int n, int d) : _numerator(n), _denominator(d)
{
	if(d == 0) {
		_numerator = 0;
		return;
	}
	simplify();
}

int fraction::numerator() const { return _numerator; }
int fraction::denominator() const { return _denominator; }

void fraction::simplify()
{
        if(_denominator == 0) return;
        int _gcd = gcd(_numerator,_denominator);
        _numerator /= _gcd;
        _denominator /= _gcd;
}


bool fraction::operator==(const fraction &o) const 
{
	return o.numerator() == numerator() && o.denominator() == denominator();
} 

bool fraction::operator<(const fraction &o) const 
{
	int lcd = lcm(o.denominator(), denominator());
	return (numerator()* (lcd/denominator())) < (o.numerator() * (lcd/o.denominator()));
}


fraction& fraction::operator+=(const fraction &o) 
{
	int lcd = lcm(o.denominator(), denominator());
 	_numerator = (_numerator* (lcd/_denominator)) + (o.numerator() * (lcd/o.denominator()));
	_denominator = lcd;			
	simplify();
	return *this;
}

fraction& fraction::operator-=(const fraction &o) 
{
	int lcd = lcm(o.denominator(), denominator());
	_numerator = (_numerator* (lcd/_denominator)) - (o.numerator() * (lcd/o.denominator()));
	_denominator = lcd;
	simplify();
	return *this;
}

fraction& fraction::operator*=(const fraction &o) 
{
	_numerator *= o.numerator();
	_denominator *= o.denominator();
	simplify();
	return *this;
}

fraction& fraction::operator/=(const fraction &o) 
{
	_numerator *= o.denominator();
	_denominator *= o.numerator();
	simplify();
	return *this;
}

fraction operator+(fraction a, fraction b) {return a.operator+=(b);} 
fraction operator+(int a, fraction b) { return fraction(a) += b;} 
fraction operator+(fraction a, int b) { return fraction(b) += a;}

// Not commutative!
fraction operator-(fraction a, fraction b) { return a-=b; } 
fraction operator-(int a, fraction b) { return fraction(a) -= b; }
fraction operator-(fraction a, int b) { return  a -= fraction(b); } 

fraction operator*(fraction a, fraction b) { return a*=b; }
fraction operator*(int a, fraction b) { return fraction(a) *= b; }
fraction operator*(fraction a, int b) { return fraction(b) *= a; }

//Not commutative!
fraction operator/(fraction a, fraction b) { return a/=b; }
fraction operator/(int a, fraction b) { return fraction(a)/=b; }
fraction operator/(fraction a, int b) { return a/=fraction(b); }