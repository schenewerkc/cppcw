#include "sample.h"
#include "fraction.h"
#include <assert.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace std::rel_ops;


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


        cout << "All fraction tests passed" << endl;

        // Sample tests
        
        string testString("< 6 :7 11 2 13 3 5 >");
        stringstream stream(testString);
        sample sam;
        stream >> sam;

        vector<double> data = sam.get_data();
        assert(data.size() == 6);
        assert(is_sorted(data.begin(),data.end()));
        assert(sam.minimum() == 2);
        assert(sam.maximum() == 13);
        assert(sam.range() == 11);
        assert(round(sam.midrange() * 10)/10 == 7.5);
        assert(sam.median() == 6);
        assert(round(sam.mean() * 100000) / 100000 == 6.83333);
        assert(round(sam.variance() * 10000)/ 10000 == 16.1389);
        assert(round(sam.std_deviation() * 100000)/100000 == 4.01732);

        cout << "All sample tests passed" << endl;
        cout << "Enter a sample to test: " << endl;
        sample s;
        while (cin>>s){
                cout << s << endl
                << "Minimum: " << s.minimum() << endl << "Maximum :" << s.maximum() << endl
                << "Range: " << s.range() << endl << "Midrange: " << s.midrange() << endl
                << "Median: " << s.median() << endl << "Mean: " << s.mean() << endl 
                << "Variance: " << s.variance() << endl << "Std. deviation: " << s.std_deviation() << endl;
        }

}