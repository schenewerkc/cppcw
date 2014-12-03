#include "samplet.h"
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

        samplet<fraction> s;
        cin >> s;

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
        cout << count << ": Read:" << s << endl;
        ++count;
    }
    return 0;
}