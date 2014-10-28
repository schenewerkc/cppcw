#include "util.h"
#include <cstdlib>

int gcd(int n, int m){
	if(m == 0) return abs(n);

	return gcd(m, n % m);
}

int lcm(int n, int m){
	return abs(m * (n/gcd(n,m)));
}	
