#ifndef FRACTION
#define FRACTION

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
	fraction &operator+(const fraction&);
	fraction &operator-(const fraction&);
	fraction &operator/(const fraction&);

private:
	int _numerator;
	int _denominator;
	
	void simplify();
};

#endif // FRACTION
