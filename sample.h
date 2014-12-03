#ifndef SAMPLE
#define SAMPLE

#include <iostream>
#include <vector>
// #include <regex>

class sample {
	std::vector<double> _samples;
public:
<<<<<<< HEAD
	//We could have forced programmers to not initialise empty sample objects by not providing the default constructor below.
=======
	//We could have forced programmers to not initialise empty sample objects by not providing the default constructor below
>>>>>>> a9a021dd0e82b7611ff679144a51ed59da3bf811
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
