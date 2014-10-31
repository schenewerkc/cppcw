#include "sample.h"
#include <vector>
using namespace std;

int main () {
        //Fraction Tests


        //Sample tests
        vector<sample> vec;
        while(cin){
                sample s;
                try {
                        cin >> s;
                        if(cin){
                              vec.push_back(s);  
                        }
                } catch (exception &e) {
                        cout << e.what() << endl;
                }

        }
        for( auto i = begin(vec); i != end(vec); ++i){
                        cout << *i << endl;
        }
	
}