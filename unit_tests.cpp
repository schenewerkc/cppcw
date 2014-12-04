#include "fraction.h"
#include "sample.h"
#include "samplet.h"
#include <assert.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;
// Fraction tests
template <typename T, typename U, typename V>
void test_add(const T &lhs, const U &rhs, const V &result)
{
    cout << "Testing: " << lhs << " + " << rhs << " = " << result << "(" << lhs + rhs << ")";
    assert(lhs + rhs == result);
    cout << " Passed!" << endl;
}

template <typename T, typename U, typename V>
void test_sub(const T &lhs, const U &rhs, const V &result)
{
    cout << "Testing: " << lhs << " - " << rhs << " = " << result << "(" << lhs - rhs << ")";
    assert(lhs - rhs == result);
    cout << " Passed!" << endl;
}
template <typename T, typename U, typename V>
void test_mult(const T &lhs, const U &rhs, const V &result)
{
    cout << "Testing: " << lhs << " * " << rhs << " = " << result << "(" << lhs * rhs << ")";
    assert(lhs * rhs == result);
    cout << " Passed!" << endl;
}
template <typename T, typename U, typename V>
void test_div(const T &lhs, const U &rhs, const V &result)
{
    cout << "Testing: " << lhs << " / " << rhs << " = " << result << "(" << lhs / rhs << ")";
    assert(lhs / rhs == result);
    cout << " Passed!" << endl;
}
template <typename T, typename U>
void test_equality(const T &a, const U &b)
{
    cout << "Testing: " << a << " = " << b;
    assert(a == b);
    cout << " Passed!" << endl;
}

template <typename T, typename U>
void test_less_than(const T &a, const U &b)
{
    cout << "Testing: " << a << " < " << b;
    assert(a < b);
    cout << " Passed!" << endl;
}


//Sample Tests
void test_sample_size(const sample &sam, uint size)
{
    vector<double> data(sam.get_data());
    cout << "Testing size() of: " << sam << " is " << size << "(" << data.size() << ")";
    assert(data.size() == size);
    cout << " Passed!" << endl;
}

void test_sample_min(const sample &sam, double min)
{
    double epsilon = 0.0001;
    cout << "Testing minimum() of: " << sam << " is " << min << "(" << sam.minimum() << ")";
    assert(abs(sam.minimum() - min) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_max(const sample &sam, double max)
{
    double epsilon = 0.0001;
    cout << "Testing maximum() of: " << sam << " is " << max << "(" << sam.maximum() << ")";
    assert(abs(sam.maximum() - max) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_range(const sample &sam, double range)
{
    double epsilon = 0.0001;
    cout << "Testing range() of: " << sam << " is " << range << "(" << sam.range() << ")";
    assert(abs(sam.range() - range) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_midrange(const sample &sam, double midrange)
{
    double epsilon = 0.0001;
    cout << "Testing midrange() of: " << sam << " is " << midrange << "(" << sam.midrange() << ")";
    assert(abs(sam.midrange() - midrange) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_median(const sample &sam, double median)
{
    double epsilon = 0.0001;
    cout << "Testing median() of: " << sam << " is " << median << "(" << sam.median() << ")";
    assert(abs(sam.median() - median) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_mean(const sample &sam, double mean)
{
    double epsilon = 0.0001;
    cout << "Testing mean() of: " << sam << " is " << mean << "(" << sam.mean() << ")";
    assert(abs(sam.mean() - mean) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_variance(const sample &sam, double variance)
{
    double epsilon = 0.0001;
    cout << "Testing variance() of: " << sam << " is " << variance << "(" << sam.variance() << ")";
    assert(abs(sam.variance() - variance) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_std_dev(const sample &sam, double std_deviation)
{
    double epsilon = 0.0001;
    cout << "Testing std_deviation() of: " << sam << " is " << std_deviation << "(" << sam.std_deviation() << ")";
    assert(abs(sam.std_deviation() - std_deviation) < epsilon);
    cout << " Passed!" << endl;
}

void test_sample_is_empty(const sample &sam, bool is_empty){
    cout << "Testing empty() of: " << sam;
    if(is_empty){
        cout << " is true";
    } else {
        cout << " is false";
    }
    assert(sam.empty() == is_empty);
    cout << " Passed!" << endl;
}

//Generic sample tests
template <typename T>
void test_sample_size(const samplet<T> &sam, uint size)
{
    vector<T> data(sam.get_data());
    cout << "Testing size() of: " << sam << " is " << size << "(" << data.size() << ")";
    assert(data.size() == size);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_min(const samplet<T> &sam, T min)
{
    cout << "Testing minimum() of: " << sam << " is " << min << "(" << sam.minimum() << ")";
    assert(sam.minimum() == min);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_max(const samplet<T> &sam, T max)
{
    cout << "Testing maximum() of: " << sam << " is " << max << "(" << sam.maximum() << ")";
    assert(sam.maximum() == max);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_range(const samplet<T> &sam, double range)
{
    double epsilon = 0.0001;
    cout << "Testing range() of: " << sam << " is " << range << "(" << sam.range() << ")";
    assert(abs(sam.range() - range) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_midrange(const samplet<T> &sam, double midrange)
{
    double epsilon = 0.0001;
    cout << "Testing midrange() of: " << sam << " is " << midrange << "(" << sam.midrange() << ")";
    assert(abs(sam.midrange() - midrange) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_median(const samplet<T> &sam, double median)
{
    double epsilon = 0.0001;
    cout << "Testing median() of: " << sam << " is " << median << "(" << sam.median() << ")";
    assert(abs(sam.median() - median) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_mean(const samplet<T> &sam, double mean)
{
    double epsilon = 0.0001;
    cout << "Testing mean() of: " << sam << " is " << mean << "(" << sam.mean() << ")";
    assert(abs(sam.mean() - mean) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_variance(const samplet<T> &sam, double variance)
{
    double epsilon = 0.0001;
    cout << "Testing variance() of: " << sam << " is " << variance << "(" << sam.variance() << ")";
    assert(abs(sam.variance() - variance) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_std_dev(const samplet<T> &sam, double std_deviation)
{
    double epsilon = 0.0001;
    cout << "Testing std_deviation() of: " << sam << " is " << std_deviation << "(" << sam.std_deviation() << ")";
    assert(abs(sam.std_deviation() - std_deviation) < epsilon);
    cout << " Passed!" << endl;
}

template <typename T>
void test_sample_is_empty(const samplet<T> &sam, bool is_empty){
    cout << "Testing empty() of: " << sam;
    if(is_empty){
        cout << " is true";
    } else {
        cout << " is false";
    }
    assert(sam.empty() == is_empty);
    cout << " Passed!" << endl;
}

sample build_sample(const string &sample_str)
{
    stringstream stream(sample_str);
    sample s;
    stream >> s;
    return s;
}

template <typename T>
samplet<T> build_sample_t(const string &sample_str)
{
    stringstream stream(sample_str);
    samplet<T> s;
    stream >> s;
    return s;
}

int main () 
{
    {
        fraction half(1,2);
        fraction quarter(1,4);
        fraction one(1,1);
        fraction two(2,1);
        fraction zero(0,1);
        fraction whole(1);
        fraction huge(std::numeric_limits<int>::max(),1);
        fraction tiny(1,std::numeric_limits<int>::max());

        fraction neg_half(-1,2);
        fraction neg_quarter(-1,4);
        fraction neg_one(-1,1);
        fraction neg_two(-2,1);
        fraction neg_zero(-0,1);
        fraction neg_whole(-1);
        fraction neg_huge(- std::numeric_limits<int>::max(),1);
        fraction neg_tiny(-1,std::numeric_limits<int>::max());

        test_equality(whole, one);
        test_less_than(one, two);
        test_add(half,half,one);
        test_add(one,1,two);
        test_add(1,one,two);
        test_sub(1,one,zero);
        test_sub(one,1,zero);
        test_sub(one,half,half);
        test_mult(half,one,half);
        test_mult(1,half,half);
        test_mult(half,1,half);
        test_div(one,two,half);
        test_div(1,two,half);
        test_div(half,2,quarter);
        test_mult(huge,tiny,one);

        test_equality(neg_whole, neg_one);
        test_less_than(neg_two, neg_one);
        test_add(neg_half,neg_half,neg_one);
        test_add(neg_one,1,zero);
        test_add(1,neg_one,zero);
        test_sub(1,neg_one,two);
        test_sub(neg_one,1,neg_two);
        test_sub(neg_one,neg_half,neg_half);
        test_mult(neg_half,neg_one,half);
        test_mult(1,neg_half,neg_half);
        test_mult(neg_half,1,neg_half);
        test_div(neg_one,neg_two,half);
        test_div(1,neg_two,neg_half);
        test_div(half,2,quarter);
        test_mult(neg_huge,neg_tiny,one);
    }

    {
        sample normal(build_sample("< 6 :7 11 2 13 3 5>"));
        sample limit(build_sample("<2: 1.7976931348623158e+308 1.7976931348623158e+308 >"));
        sample empty(build_sample("< 0: >"));

        test_sample_is_empty(empty, true);

        test_sample_is_empty(normal,false);
        test_sample_size(normal, 6);
        test_sample_min(normal,2);
        test_sample_max(normal,13);
        test_sample_range(normal,11);
        test_sample_midrange(normal,7.5);
        test_sample_median(normal,6);
        test_sample_mean(normal,6.83333);
        test_sample_variance(normal,16.1389);
        test_sample_std_dev(normal,4.01732);
    }

    {
        samplet<fraction> normal(build_sample_t<fraction>("< 6: 1/2 1/4 4/5 7/3 7/9 15/1>"));
        samplet<fraction> empty(build_sample_t<fraction>("< 0: >"));

        test_sample_is_empty(empty,true);
        test_sample_is_empty(normal,false);
        test_sample_size(normal,6);
        test_sample_min(normal,fraction(1,4));
        test_sample_max(normal,fraction(15,1));
        test_sample_range(normal,14.75);
        test_sample_midrange(normal,7.625);
        test_sample_median(normal,0.788889);
        test_sample_mean(normal,3.2768518);
        test_sample_variance(normal,27.9292224);
        test_sample_std_dev(normal,5.28481054);

    }
    
    
    // test_fraction(fraction(1,2),fraction(1,2),fraction(1,1),fraction(0,1),fraction(1,4),fraction(1,1));
    // test_sample(build_sample("< 6 :7 11 2 13 3 5>"),6,2,13,11,7.5,6,6.833333,16.1389,4.01732);
    // test_sample(build_sample("<2: 1.7976931348623158e+308 1.7976931348623158e+308 >"),2,std::numeric_limits<double>::max(),std::numeric_limits<double>::max(),0,std::numeric_limits<double>::max(),std::numeric_limits<double>::max(),std::numeric_limits<double>::max(),0,0);
    // test_sample_t<fraction>(build_sample_t<fraction>("< 2: 1/2 1/4 >"), 2, fraction(1,4),fraction(1,2),0.25,0.375,0.375,0.375,0.015625, 0.125);
    test_sample_is_empty<fraction>(build_sample_t<fraction>("< 0: >"),true);
    test_sample_is_empty<fraction>(build_sample_t<fraction>("< 1: 7/5 >"),false);
    return 0;
}
