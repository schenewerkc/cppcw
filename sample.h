#ifndef SAMPLE
#define SAMPLE

#include <iostream>
#include <vector>
#include <regex>

class sample {
	std::vector<double> _samples;
        static const std::regex _format;
public:
        sample ();
	sample (const std::vector<double>&);

	//Get and Set the data vector
	const std::vector<double> & get_data() const;
	void set_data (const std::vector<double>&);
	void print(std::ostream&) const;
	void read(std::istream&);

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

// Overload << and >> operators for reading and printing
std::ostream& operator<<(std::ostream&, const sample&);
std::istream& operator>>(std::istream&,sample&);

#endif // SAMPLE