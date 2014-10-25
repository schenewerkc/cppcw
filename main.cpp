#include "sample.h"
#include <vector>

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