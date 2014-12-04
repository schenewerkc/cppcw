#ifndef SAMPLE
#define SAMPLE

//Section 2.2 Q14
//The numbers given are the largest that can be represented by a double, written in scientific notation. 
//The std::scientific stream manipulator can be used to read these numbers in as doubles. 
//As the numbers are large they can caused overflow problems in some functions 
//(sample.cpp lines 89, 102,140, samplet.h lines 146, 160, 199). In all of these cases the overflow 
//was avoidable by making division the first operation in the calculation. As four of these cases were 
//essentially the same calculation (taking the average of two values) we wrote a generic helper function and put it in util.h (line 9).

#include <iostream>
#include <vector>

class sample {
	std::vector<double> _samples;
public:
	//We could have forced programmers to not initialise empty sample objects by not providing the default constructor.
	//As there is another constructor defined, this would stop the C++ compiler from generating a default constructor automatically.
	sample ();
	sample (const std::vector<double>&);

	//Get and Set the data vector
	const std::vector<double> & get_data() const;
	void set_data (const std::vector<double>&);
	void print(std::ostream&) const;
	void read(std::istream&);
	//implemented empty to make it the callers responsability to to check whether the sample has values before calling min/max. 
	//otherwise what is the minimum of an empty set?? Zero could be a real value so is misleading.
	bool empty() const;

	//Statistical Functions
	//calling minimum or maximum on an empty sample is undefined. Returning zero for an empty set could be missleading.
	//call empty() first to check there are values.
	double minimum() const;
	double maximum() const;
	double range() const;
	double midrange() const;
	double mean() const;
	double variance() const;
	double std_deviation() const;
	double median() const;

};

// Overload << and >> operators for reading and printing
std::ostream& operator<<(std::ostream&, const sample&);
std::istream& operator>>(std::istream&,sample&);

#endif // SAMPLE
