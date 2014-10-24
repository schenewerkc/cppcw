#include "sample.h"
#include <cmath>

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
	//Add all values
	double sum = 0;
	for (int i=0;i<samples.size(); ++i) {
		sum = sum + samples[i];
	}

	//Divide the number of values by the number of items
	double mean = sum / samples.size();
	return mean;
}
double sample::variance () {
	std::vector<double> variances;
	double mean = this->mean();

	for (int i=0; i<samples.size(); ++i) {
		//Compute the difference between the value and the mean
		variances.push_back(samples[i] - mean);
		//Square the difference
		variances[i] = pow(variances [i],2);
	}
	//Average the squared values in the variances vector
	double sum = 0;

	for (int j=0; j<variances.size(); ++j) {
		sum = sum + variances [j];
	}
	double variance = sum / variances.size();
	return variance;
}
double sample::std_deviation () {
	double std = sqrt(this->variance());
	return std;
}
double sample::median() {
	std::sort (samples.begin(), samples.end());
	double median;
	if (samples.size() % 2 == 0) {
		//The number of items is even
		int index = samples.size()/2;
		median = (samples[index] + samples[index+1])/2;
	}
	else {
		//The number of items is odd
		median = samples[((samples.size() + 1)/2)-1];
	}

	return median;
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

}