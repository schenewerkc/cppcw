Build Instructions
==================

To compile: make clean all

This will make four executables: "sample_main", "samplet_main", "fraction_main", and "unit_tests", execute them with test data and generate seven output files.

sample_main, samplet_main, and fraction_main take as input via standard in sequences of samples, samples of fractions and fractions respectively. For each sample they output a line stating whether a sample was correctly read (and what it was) or if there was an invalid input. Each executable is tested with a file containing only good data, and a mix of good and bad data.

unit_tests runs internal tests that test the member functions of the sample, samplet and fraction class, it then reports the result of each test to standard out.

This is tested and working on "gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5)" on ubuntu 12.04 lts.


Answers to questions 
====================

Section 2.2 Q1
We could have forced programmers to not initialise empty sample objects by not providing the default constructor.
As there is another constructor defined, this would stop the C++ compiler from generating a default constructor automatically.

Section 2.2 Q14
The numbers given are the largest that can be represented by a double, written in scientific notation. The std::scientific stream manipulator can be used to read these numbers in as doubles. As the numbers are large they can caused overflow problems in some functions (sample.cpp lines 89, 102,140, samplet.h lines 164, 178, 217). In all of these cases the overflow was avoidable by making division the first operation in the calculation. As four of these cases were essentially the same calculation (taking the average of two values) we wrote a generic helper function and put it in util.h (line 9).

Section 2.3 Question 15
Double is a good choice for some of the return type of some of the member functions of samplet, but not all of them. For the functions mean(), median(), range(), variance() and std_deviation(), if the return type is T, an T is for instance an int, these calculations could give an unreliable result due to a loss in precision from integer division. E.g. the mean of two integers 1 and 2 should be 1.5, but 1.5 would be returned as 1 if converted to an integer. Therefore we have chosen to keep the return type as double for these functions. 


For the functions minimum() and maximum() we have allowed a return type of T, returned by const reference. As these functions are essentially getters for the smallest and largest values in the dataset, they could not result in a loss in precision. This keeps the code as generic as possible. Their return value in the case of an empty set is undefined. We have provided the member function empty() and it is the caller's responsibility to check if empty() returns false before calling minimum() or maximum(). This mimics the behavior of the standard library for empty containers. Calling vector::front() or list::front() on an empty vector results in undefined behavior. Both collections have empty() methods. Returning a zero or a default initialised value in the case of an empty set could be misleading as the same value could could occur in a non-empty set, the caller would not be able to tell the difference.
