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
            cin.ignore(1000,'\n');
            ++count;
            continue;
        }
        cout << count << ": Read:" << f << endl;
        ++count;
    }
    return 0;
}