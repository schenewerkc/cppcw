#include "sample.h"
#include <cmath>
#include <string>
#include <sstream>
#include <istream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// const regex sample::_format(" * [0-9]+ *: *([0-9]+\\.{0,1}[0-9]* )+");

sample::sample() 
{
}

sample::sample (const vector<double> &items) : 
_samples(items)
{
	sort (_samples.begin(), _samples.end());
}

const vector<double>& sample::get_data() const
{
	return _samples;
}

void sample::set_data (const std::vector<double>& data)
{
	_samples = data;
	sort (_samples.begin(), _samples.end());
}

void sample::print(ostream &os) const 
{
	os << "< " << _samples.size()  << ": ";
	for(auto i = _samples.cbegin(); i != _samples.cend(); ++i){
		os << *i << " ";
	}
	os << '>';
}

void sample::read(istream &is)
{
	char left, right, sep;
	int count = 0;
	if(is >> left){
		if((is >> count >> sep) && left == '<' && sep == ':'){
			while (count > 0){
				double s;
				is >> s;
				_samples.push_back(s);
				--count;
			}
			is >> right;
		} else {
			is.setstate(ios_base::badbit);
		}
	} 
	sort (_samples.begin(), _samples.end());
}

double sample::minimum () const 
{
	if(_samples.empty()){
		return 0;
	}
	return *_samples.begin();
}

double sample::maximum () const
{
	if(_samples.empty()){
		return 0;
	}
	if(_samples.size() == 1){
		return _samples[0];
	}
	return *(_samples.end()-1);
}

double sample::range() const
{
	return this->maximum() - this->minimum();
}

double sample::midrange() const
{
	return (this->maximum() + this->minimum())/2;
}

double sample::mean () const
{
	//Add all values
	if(_samples.empty()){
		return 0;
	}
	double sum = 0;
	for (auto i = _samples.cbegin(); i != _samples.cend(); ++i) {
		sum += *i;
	}

	//Divide the number of values by the number of items
	return sum / _samples.size();
}

double sample::variance () const
{
	if(_samples.empty()){
		return 0;
	}

	double sum = 0;
	int num = _samples.size();
	for(auto i = _samples.begin(); i != _samples.end(); ++i){
		sum += (pow(*i - mean(),2))/num;
	}
	return sum;

}

double sample::std_deviation () const
{
	return sqrt(this->variance());
}

double sample::median() const
{
	if(_samples.empty()){
		return 0;
	}
	double median;
	if (_samples.size() % 2 == 0) {
		//The number of items is even
		auto N = _samples.size()/2;
		//container is indexed from 0, hence N-1...
		median = (_samples[N-1] + _samples[N])/2;
	} else {
		//The number of items is odd
		median = _samples[static_cast<int>(_samples.size()/2)];
	}

	return median;
}
// Free functions
ostream& operator<<(ostream &os, const sample &s)
{
	s.print(os);
	return os;
}

istream& operator>>(istream &is,sample &s)
{
	s.read(is);
	return is;
}
