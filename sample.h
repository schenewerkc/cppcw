#ifndef SAMPLE
#define SAMPLE

#include <iostream>
#include <vector>

class sample {
	std::vector<double> samples;
public:
	sample (const std::vector<double>&);

	//Get and Set the data vector
	const std::vector<double> & getdata();
	void setdata (const std::vector<double>&);

	//Overload << and >> operators for reading and printing
	std::ostream& operator<<(const sample&);
	std::istream& operator>>(sample&);

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