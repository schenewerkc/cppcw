#ifndef UTIL
#define UTIL

int gcd(int, int);
int lcm(int, int);


//a safe averageing function that avoids overflow.
template <typename T>
void average(const T &lhs, const T &rhs, double &result){
    result = (static_cast<double>(lhs)/2 + static_cast<double>(rhs)/2);
}

#endif // UTIL