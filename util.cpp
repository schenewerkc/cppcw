#include "util.h"
#include <cstdlib>

//This code is taken from the coursework specification
int gcd(int n, int m){
	if(m == 0) return abs(n);

	return gcd(m, n % m);
}

//This code is taken from the coursework specification
int lcm(int n, int m){
	return abs(m * (n/gcd(n,m)));
}	