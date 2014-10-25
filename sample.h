#ifndef SAMPLE
#defile SAMPLE

#include <iostream>
#include <vector>

class sample {
	std::vector<double> samples;
public:
	sample (std::vector<double> items);

	//Get and Set the data vector
	const std::vector<double> & getdata();
	void setdata (const std::vector<double> &v);

	//Overload << and >> operators for reading and printing
	std::ostream& operator<<(const sample &s);
	std::istream& operator>>(sample &s);

	//Statistical Functions
	double minimum();
	double maximum();
	double range();
	double midrange();
	double mean();
	double variance();
	double std_deviation();
	double median();


};

#endif // SAMPLE