#include "function.hh"

Function::Function()
{}

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

std::string Function::getName()
{
    return name_;
}

Michalewicz::Michalewicz(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float Michalewicz::solve(std::vector<float> x)
{
    float res = 0.0;
    float i = 0.0;
    for (auto f : x)
    {
        i += 1.0;
        res += std::sin(f) * std::pow(std::sin((i * f * f) / M_PI), 20);
    }

    return -res;
}


De_Jong_F1::De_Jong_F1() : Function("djf1_for_zakharov", 0, 0.0, 0.0)
{}

De_Jong_F1::De_Jong_F1(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float De_Jong_F1::solve(std::vector<float> x)
{
    float res = 0.0;

    for (auto i : x)
    {
        res += i * i;
    }

    return res;
}


De_Jong_F2::De_Jong_F2(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float De_Jong_F2::solve(std::vector<float> x)
{
    if (x.size() != 2)
    {
        std::cerr << "De Jong F2: Error: should have two varaibles." << std::endl;
        exit(1);
    }

    float x1 = x[0];
    float x2 = x[1];
    float res = 100 * (x2 * x2 - x1) * (x2 * x2 - x1) + (1 - x1) * (1 - x1);

    return res;
}

De_Jong_F3::De_Jong_F3(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float De_Jong_F3::solve(std::vector<float> x)
{
    if (!x.size())
        return 0;

    int var = 0;

    for (float f : x)
        var += f;

    float res = var;

    return res;
}

Goldstein_Price::Goldstein_Price(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float Goldstein_Price::solve(std::vector<float> x)
{
    if (x.size() != 2)
    {
        std::cerr << "De Jong F2: Error: should have two varaibles." << std::endl;
        exit(1);
    }
    float x1 = x[0];
    float x2 = x[1];
    /*float var1 = x1 + x2 + 1.0;
    float var2 = 19.0 - 14.0 * x1 + 13.0 * x1 * x1 - 14.0 * x2 + 6.0 * x1 * x2 + 3.0 * x2 * x2;
    float var3 = 1.0 + var1 * var1 * var2;
    float var4 = 2.0 * x1 - 3.0 * x2;
    float var5 = 18.0 - 32.0 * x1 + 12.0 * x1 * x1 - 48.0 * x2 - 36.0 * x1 * x2
                 + 27.0 * x2 * x2;
    float var6 = 30.0 + var4 * var4 * var5;*/

    float var = (1.0 + std::pow((x1 + x2 + 1.0), 2) * (19.0 - 14.0 * x1 + 3.0 * x1 * x1
                - 14.0 * x2 + 6.0 * x1 * x2 + 3.0 * x2 *x2)) * (30 + std::pow((2 * x1 - 3 * x2), 2)
                * (18 - 32 * x1 + 12 * x1 * x1 + 48 * x2 - 36 * x1 * x2 + 27 * x2 * x2));

    return var;
}

Rosenbrock::Rosenbrock(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float Rosenbrock::solve(std::vector<float> x)
{
    float res = 0;

    for (auto it = x.begin(); it != (x.end() - 1); it++)
    {
        auto next = it + 1;
        float x1 = *it;
        float x2 = *next;

        float var1 = x1 * x1 - x2;

        res += 100 * var1 * var1 + (x1 - 1) * (x1 - 1);
    }

    return res;
}

Zakharov::Zakharov(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{
    djf1 = De_Jong_F1("de_jong_f1_for_zakharov", d, min, max);
}

float Zakharov::solve(std::vector<float> x)
{
    float res = 0;
    float i = 0;
    for (auto f : x)
    {
        i += 1.0;
        res += 0.5 * i * f;
    }

    return djf1.solve(x) + res * res + std::pow(res, 4);
}

Schwefel::Schwefel(std::string name, int d, float min, float max)
  : Function(name, d, min, max)
{}

float Schwefel::solve(std::vector<float> x)
{
    if (!x.size())
        return 0.0;

    float var = 0.0;

    for (float f : x)
    {
        var += - f * std::sin(std::sqrt(std::abs(f)));
    }
    return 418.9820 - var;
}
