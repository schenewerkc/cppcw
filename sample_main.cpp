#include "sample.h"
#include <assert.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void test_sample_files(const char* filename, vector<sample> &vsamp, uint num){
    ifstream file(filename);
    vsamp.clear();

    while(file){
        sample sam;
        file >> sam;
        if(file){
            vsamp.push_back(sam);
        }
    }

    file.close();

    assert(vsamp.size() == num);
}

int main () {
    // Sample tests

    string testString("< 6 :7 11 2 13 3 5>");
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

    vector<sample> vsamp;
    test_sample_files("test_data/test_sample_good.txt",vsamp,1000);

    cout << "All builtin tests passed." << endl;

    for(;;){
        cout << "Enter a sample of doubles: " << endl;
        sample a;
        cin >> a;

        if(!cin){
            cout << "Error - Invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cout << "Maximum: " << a.maximum() << endl;
        cout << "Minimum: " << a.minimum() << endl;
        cout << "Range: " << a.range() << endl;
        cout << "Midrange: " << a.midrange() << endl;
        cout << "Mean: " << a.mean() << endl;
        cout << "Variance: " << a.variance() << endl;
        cout << "Standard Deviation: " << a.std_deviation() << endl;
        cout << "Median: " << a.median() << endl;
        

        cin.clear();
        cin.ignore(1000, '\n');
    }

    return 0;

}