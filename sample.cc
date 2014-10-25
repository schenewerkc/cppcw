#include "sample.h"
#include <cmath>

using namespace std;

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

void sample::print(ostream &os){
	os << "< " << samples.size()  << ": ";
	for(vector<double>::const_iterator i = samples.begin(); i != samples.end(); ++i){
		os << *i << " ";
	}
	os << '>';
}

double sample::minimum () {
	// double min=samples[0];
	// for (int i=0;i<samples.size(); ++i) {
	// 	if (samples[i]<min) {
	// 		min = samples[i];
	// 	}
	// 	else{}
	// }
	// return min;
	if(samples.empty()){
		return 0;
	}
	return *samples.begin();
}
double sample::maximum () {
	// double max=samples[0];
	// for (int i=0;i<samples.size(); ++i) {
	// 	if (samples[i]>max) {
	// 		max = samples[i];
	// 	}
	// 	else{}
	// }
	// return max;
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
	// return range;
}
double sample::midrange() {
	return (this->maximum() - this->minimum())/2;
	// return midrange;
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
	// return mean;
}
double sample::variance () {
	// std::vector<double> variances;
	// double mean = this->mean();

	// for (int i=0; i<samples.size(); ++i) {
	// 	//Compute the difference between the value and the mean
	// 	variances.push_back(samples[i] - mean);
	// 	//Square the difference
	// 	variances[i] = pow(variances [i],2);
	// }
	// //Average the squared values in the variances vector
	// double sum = 0;

	// for (int j=0; j<variances.size(); ++j) {
	// 	sum = sum + variances [j];
	// }
	// double variance = sum / variances.size();
	// return variance;
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
	// return std;
}
double sample::median() {
	// std::sort (samples.begin(), samples.end());
	if(samples.empty()){
		return 0;
	}
	double median;
	if (samples.size() % 2 == 0) {
		//The number of items is even
		vector<double>::size_type index = samples.size()/2;
		median = (samples[index] + samples[index+1])/2;
	}
	else {
		//The number of items is odd
		median = samples[((samples.size() + 1)/2)-1];
	}

	return median;
}
// Free functions
ostream& operator<<(ostream &os,sample &s){
	s.print(os);
	return os;
}

int main () {
	std::vector<double> vd;
	vd.push_back(6.0);
	vd.push_back(4.3);
	vd.push_back(7.2);
	vd.push_back(8.4);
	vd.push_back(1.4);

	sample s (vd);
	std::cout << s.minimum()<< '\n' << s.maximum() << '\n' << s.range() << '\n';
	std::cout << s.midrange() << '\n' << s.mean() <<'\n';
	std::cout << s.variance() << '\n' << s.std_deviation() << '\n';
	std::cout << s.median() <<'\n';
	std::vector<double> vd3 = s.get_data();
	std::vector<double> vd2;
	s.set_data(vd2);
	std::cout << s.minimum()<< '\n' << s.maximum() << '\n' << s.range() << '\n';
	std::cout << s.midrange() << '\n' << s.mean() <<'\n';
	std::cout << s.variance() << '\n' << s.std_deviation() << '\n';
	std::cout << s.median() <<'\n';
	s.set_data(vd3);
	std::cout << s.minimum()<< '\n' << s.maximum() << '\n' << s.range() << '\n';
	std::cout << s.midrange() << '\n' << s.mean() <<'\n';
	std::cout << s.variance() << '\n' << s.std_deviation() << '\n';
	std::cout << s.median() <<'\n';
	std::cout <<  s << '\n';
	
}