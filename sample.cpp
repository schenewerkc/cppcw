#include "sample.h"
#include <cmath>

using namespace std;

sample::sample() {}

sample::sample (const vector<double> &items) : samples(items) {
	sort (samples.begin(), samples.end());
}

const vector<double>& sample::get_data() const{
	return samples;
}

void sample::set_data (const std::vector<double>& data){
	samples = data;
	sort (samples.begin(), samples.end());
}

void sample::print(ostream &os) const {
	os << "< " << samples.size()  << ": ";
	for(vector<double>::const_iterator i = samples.cbegin(); i != samples.cend(); ++i){
		os << *i << " ";
	}
	os << '>';
}

void sample::read(istream &is){

        char begin, end, sep = 0;
        double sample = 0;
        uint count = 0;

        if(!is){
                return;
        }

        is >> begin >> count >> sep;

        if(begin != '<' || sep != ':'){
                is.setstate(ios_base::badbit);
                return;
        }

        while (is >> sample && count > 0){
                samples.push_back(sample);
                --count;
        }
        is.clear();
        sort (samples.begin(), samples.end());
        is >> end;
        if(end != '>'){
                is.setstate(ios_base::badbit);
        }
}

double sample::minimum () {
	if(samples.empty()){
		return 0;
	}
	return *samples.begin();
}

double sample::maximum () {
	if(samples.empty()){
		return 0;
	}
	if(samples.size() == 1){
		return samples[0];
	}
	return *(samples.end()-1);
}

double sample::range() {
	return this->maximum() - this->minimum();
}

double sample::midrange() {
	return (this->maximum() - this->minimum())/2;
}

double sample::mean () {
	//Add all values
	if(samples.empty()){
		return 0;
	}
	double sum = 0;
	for (vector<double>::const_iterator i = samples.cbegin(); i != samples.cend(); ++i) {
		sum += *i;
	}

	//Divide the number of values by the number of items
	return sum / samples.size();
}

double sample::variance () {
	if(samples.empty()){
		return 0;
	}

	double sum = 0;
	int num = samples.size();
	for(vector<double>::const_iterator i = samples.begin(); i != samples.end(); ++i){
		sum += (pow(*i - mean(),2))/num;
	}
	return sum;

}

double sample::std_deviation () {
	return sqrt(this->variance());
}

double sample::median() {
	if(samples.empty()){
		return 0;
	}
	double median;
	if (samples.size() % 2 == 0) {
		//The number of items is even
		vector<double>::size_type index = samples.size()/2;
		median = (samples[index] + samples[index+1])/2;
	} else {
		//The number of items is odd
		median = samples[((samples.size() + 1)/2)-1];
	}

	return median;
}
// Free functions
ostream& operator<<(ostream &os, const sample &s){
	s.print(os);
	return os;
}

istream& operator>>(istream &is,sample &s){
	s.read(is);
	return is;
}
