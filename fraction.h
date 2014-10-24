class fraction {
public:
	fraction();
	fraction(int,int);
	int numberator() const;
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
	int _numberator;
	int _denominotor;
	
	void simplify();
};


