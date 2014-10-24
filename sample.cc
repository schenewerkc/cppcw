#include "sample.h"

sample::sample (std::vector<double> items) {
	samples = items;
}

double sample::minimum () {
	double min=samples[0];
	for (int i=0;i<samples.size(); ++i) {
		if (samples[i]<min) {
			min = samples[i];
		}
		else{}
	}
	return min;
}
double sample::maximum () {
	double max=samples[0];
	for (int i=0;i<samples.size(); ++i) {
		if (samples[i]>max) {
			max = samples[i];
		}
		else{}
	}
	return max;
}

double sample::range() {
	double range = this->maximum() - this->minimum();
	return range;
}

double sample::midrange() {
	double midrange = (this->maximum() - this->minimum())/2;
	return midrange;
}
double sample::mean () {
	double sum = 0;
	for (int i=0;i<samples.size(); ++i) {
		sum = sum + samples[i];
	}
	double mean = sum / samples.size();
	return mean;
}
double sample::variance () {

}
double sample::std_deviation () {

}
double sample::median() {
	
}

int main () {
	std::vector<double> vd;
	vd.push_back(6.0);
	vd.push_back(4.3);
	vd.push_back(7.2);

	sample s (vd);
	std::cout << s.minimum()<< '\n' << s.maximum() << '\n' << s.range() << '\n';
	std::cout << s.midrange() << '\n' << s.mean() <<'\n';
}