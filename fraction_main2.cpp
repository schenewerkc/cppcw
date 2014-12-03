#include "fraction.h"
#include <assert.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () 
{
    uint count = 0;
    while(!cin.eof()){

        fraction f;
        cin >> f;

        if(!cin.good()){
            if(cin.eof()) {
                continue;
            }
            cout << count << ": Invalid Input" << endl;
            cin.clear();
            //read to string to clear buffer until next newline OR space 
            //(dont know how input will be given, want to handle both)
            string s;
            cin >> s;
            s.clear();
            ++count;
            continue;
        }
        cout << count << ": Read:" << f << endl;
        ++count;
    }
    return 0;
}