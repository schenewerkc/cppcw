#include "sample.h"
#include "fraction.h"
#include <assert.h>
#include <vector>
#include <sstream>
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

        //Sample tests
        // vector<sample> vec;
        // while(cin){
        //         sample s;
        //         try {
        //                 cin >> s;
        //                 if(cin){
        //                       vec.push_back(s);  
        //                 }
        //         } catch (exception &e) {
        //                 cout << e.what() << endl;
        //         }

        // }
        // stringstream ss;
        // for( auto i = begin(vec); i != end(vec); ++i){
        //         ss << *i << endl;
        // }
        // sample s;
        // while(ss){
                
        //         ss >> s;
        //         cout << s << endl;
        // }
	
}