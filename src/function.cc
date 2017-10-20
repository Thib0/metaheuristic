#include "function.hh"

Function::Function(std::string name, int dimension, float min_range, float max_range)
  : name_(name), dimension_(dimension), min_range_(min_range), max_range_(max_range)
{}

float Function::getMax()
{
  return max_range_;
}

float Function::getMin()
{
  return min_range_;
}

float Function::getDimension()
{
  return dimension_;
}

De_Jong_F1::De_Jong_F1(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float De_Jong_F1::solve(std::vector<float> x)
{
  float res = 0;
  for (auto i : x)
    res += i * i;

  return res;
}
