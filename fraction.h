#ifndef FRACTION
#define FRACTION

#include <iostream>

using namespace std;

class fraction {
public:
	fraction();
	fraction(int);
	fraction(int,int);
	int numerator() const;
	int denominator() const;

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
ostream& operator<<( ostream &os, const fraction &f);
istream& operator>>( istream &os, fraction &f);

namespace std {
fraction sqrt(const fraction&);
}
#endif // FRACTION
