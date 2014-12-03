#ifndef SAMPLE_T_H
#define SAMPLE_T_H

#include "samplet.h"
#include "util.h"
#include <algorithm>
#include <ctgmath>
#include <string>
#include <sstream>
#include <istream>
#include <iostream>
#include <vector>

template <typename T>
class samplet {
    std::vector<T> _samples;

public:
    samplet ();
    samplet (const std::vector<T>&);

    //Get and Set the data vector
    const std::vector<T> & get_data() const;
    void set_data (const std::vector<T>&);
    void print(std::ostream&) const;
    void read(std::istream&);
    //implemented empty to make it the callers responsability to to check whether the sample has values before calling min/max. 
    //otherwise what is the minimum of an empty set?? Zero could be a real value so is misleading.
    bool empty() const;

    //calling minimum or maximum on an empty sample is undefined. Returning zero for an empty set could be missleading.
    //call empty() first to check there are values.
    const T& minimum() const;
    const T& maximum() const;
    //Statistical Functions
    double range() const;
    double midrange() const;
    double mean() const;
    double variance() const;
    double std_deviation() const;
    double median() const;
};

// Overload << and >> operators for reading and printing
template <typename T>
std::ostream& operator<<(std::ostream&, const samplet<T>&);
template <typename T>
std::istream& operator>>(std::istream&,samplet<T>&);


//Implementation
template <typename T>
samplet<T>::samplet()
{
}

template <typename T>
samplet<T>::samplet (const std::vector<T> &items) : 
_samples(items)
{
    std::sort (_samples.begin(), _samples.end());
}

template <typename T>
const std::vector<T>& samplet<T>::get_data() const
{
    return _samples;
}

template <typename T>
void samplet<T>::set_data (const std::vector<T>& data)
{
    _samples = data;
    std::sort (_samples.begin(), _samples.end());
}

template <typename T>
void samplet<T>::print(std::ostream &os) const 
{
    os << "< " << _samples.size()  << ": ";
    for(auto i = _samples.cbegin(); i != _samples.cend(); ++i){
        os << *i << " ";
    }
    os << '>';
}

template <typename T>
void samplet<T>::read(std::istream &is)
{
    char left, right, sep;
    int count = 0;
    if(is >> left){
        if((is >> count >> sep) && left == '<' && sep == ':' && is.good()){
            while (count > 0 && is.good()){
                T s;
                is >> s;
                _samples.push_back(s);
                --count;
            }
            is >> right;
            if(right != '>'){
              is.setstate(std::ios_base::badbit);
            }

        } else {
            is.setstate(std::ios_base::badbit);
        }
    } 
    std::sort (_samples.begin(), _samples.end());
}

template <typename T>
bool samplet<T>::empty() const
{
    return _samples.empty();
}

template <typename T>
const T& samplet<T>::minimum () const 
{

    return _samples.front();
}

template <typename T>
const T& samplet<T>::maximum () const
{
    return _samples.back();
}

template <typename T>
double samplet<T>::range() const
{
    return this->maximum() - this->minimum();
}

template <typename T>
double samplet<T>::midrange() const
{
    //division first to avoid overflow
    double result = 0;
    average(this->maximum(),this->minimum(),result);
    return result;
}

template <typename T>
double samplet<T>::mean () const
{
    //Add all values
    if(_samples.empty()){
        return 0;
    }
    double sum = 0;
    for (auto i = _samples.cbegin(); i != _samples.cend(); ++i) {
        //division first to avoid overflow
        sum += (static_cast<double>(*i)/_samples.size());
    }
    //Divide the number of values by the number of items
    return sum;
}

template <typename T>
double samplet<T>::variance () const
{
    if(_samples.empty()){
        return 0;
    }

    double sum = 0;
    int num = _samples.size();
    for(auto i = _samples.begin(); i != _samples.end(); ++i){
        double frac = *i;
        sum += pow(frac - mean(),2)/num;
    }
    return sum;
}

template <typename T>
double samplet<T>::std_deviation () const
{
    return std::sqrt(this->variance());
}

template <typename T>
double samplet<T>::median() const
{
    if(_samples.empty()){
        return 0;
    }
    double median;
    if (_samples.size() % 2 == 0) {
        //The number of items is even
        auto N = _samples.size()/2;
        //container is indexed from 0, hence N-1...
        average(_samples[N-1],_samples[N],median);
    } else {
        //The number of items is odd
        median = _samples[static_cast<int>(_samples.size()/2)];
    }

    return median;
}
// Free functions
template <typename T>
std::ostream& operator<<(std::ostream &os, const samplet<T> &s)
{
    s.print(os);
    return os;
}

template <typename T>
std::istream& operator>>(std::istream &is,samplet<T> &s)
{
    s.read(is);
    return is;
}

#endif // SAMPLE_T_H