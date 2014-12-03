#include "fraction.h"
#include <assert.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void test_fraction_files(const char* filename, vector<fraction> &vfrac, uint num){
    ifstream file(filename);
    vfrac.clear();

    while(file){
        fraction f;
        file >> f;
        if(file){
            vfrac.push_back(f);
        }
    }

    file.close();

    assert(vfrac.size() == num);
}

int main () {
        //Fraction Tests
    fraction a(1,3);
    fraction aa(1,3);
    fraction b(1,6);

    assert(a == aa);
    assert(a != b);
    assert(b < a);
    fraction c = a + b;
    assert(c.numerator() == 1 && c.denominator() == 2);
    c = a - b;
    assert(c.numerator() == 1 && c.denominator() == 6);
    c = a * b;
    assert(c.numerator() == 1 && c.denominator() == 18);
    c = a / b;
    assert(c.numerator() == 2 && c.denominator() == 1);
    c = a + 1;
    assert(c.numerator() == 4 && c.denominator() == 3);
    c = a - 1;
    assert(c.numerator() == -2 && c.denominator() == 3);
    c = a * 2;
    assert(c.numerator() == 2 && c.denominator() == 3);
    c = a / 2;
    assert(c.numerator() == 1 && c.denominator() == 6);

    vector<fraction> vfrac;
    test_fraction_files("test_data/test_fraction_good.txt",vfrac,1000);

    cout << "All builtin tests passed." << endl;

    for(;;){
        cout << "Enter two fractions: " << endl;
        fraction a, b;
        cin >> a >> b;

        if(!cin){
            cout << "Error - Invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cout << "Fraction a+b = " << a+b << endl;
        cout << "Fraction a-b = " << a-b << endl;
        cout << "Fraction a*b = " << a*b << endl;
        cout << "Fraction a/b = " << a/b << endl;

        cin.clear();
        cin.ignore(1000, '\n');
    }

    return 0;

}