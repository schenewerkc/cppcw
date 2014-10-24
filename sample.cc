#include "sample.h"

sample::sample (std::vector<double> items) {
	samples = items;
};
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

int main () {
	std::vector<double> vd;
	vd.push_back(6.0);
	vd.push_back(4.3);
	vd.push_back(7.2);

	sample s (vd);
	std::cout << s.minimum();

}