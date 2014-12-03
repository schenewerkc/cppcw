#ifndef FRACTION
#define FRACTION

#include <iostream>

class fraction {
public:
	fraction();
	fraction(int);
	fraction(int,int);
	int numerator() const;
	int denominator() const;

	operator double() const;

	bool operator==(const fraction&) const;
	bool operator<(const fraction&) const;
	
	fraction &operator+=(const fraction&);
	fraction &operator-=(const fraction&);
	fraction &operator*=(const fraction&);
	fraction &operator/=(const fraction&);

	void set(int, int);

private:
	int _numerator;
	int _denominator;
	void simplify();
};

fraction operator+(fraction, fraction);
fraction operator+(int, fraction);
fraction operator+(fraction,int);
fraction operator-(fraction, fraction);
fraction operator-(int, fraction);
fraction operator-(fraction,int);
fraction operator*(fraction, fraction);
fraction operator*(int, fraction);
fraction operator*(fraction, int);
fraction operator/(fraction, fraction);
fraction operator/(int, fraction);
fraction operator/(fraction,int);

// format: n/m 
std::ostream& operator<<( std::ostream &os, const fraction &f);
std::istream& operator>>( std::istream &os, fraction &f);

#endif // FRACTION
