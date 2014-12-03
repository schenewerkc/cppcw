#include "sample.h"
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

        sample s;
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