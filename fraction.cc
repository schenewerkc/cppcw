#include "fraction.h"
#include "util.h"

fraction::fraction() : _numerator(0), _denominator(0) {}

fraction::fraction(int n, int d) : _numerator(n), _denominator(m) {
	if(d == 0) {
		_numerator = 0;
		return;
	}
	simplify();
}

void fraction::simplify(){
        if(_denominator == 0) return;
        int _gcd = gcd(_numerator,_denominator);
        _numerator /= gcd;
        _denominator /= gcd;
}




