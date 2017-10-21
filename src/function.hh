#pragma once

#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class Function
{
    public:
        Function();
        Function(std::string name, int dimension, float min_range, float max_range);
        virtual float solve(std::vector<float> x) = 0;


        float getMax();
        float getMin();
        float getDimension();
        std::string getName();

    private:
        std::string name_;
        int dimension_;
        float min_range_;
        float max_range_;
};

class Michalewicz : public Function
{
    public:
        Michalewicz(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class De_Jong_F1 : public Function
{
    public:
        De_Jong_F1(); // This constructor should be used only for Zakharov Resolution
        De_Jong_F1(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class De_Jong_F2 : public Function
{
    public:
        De_Jong_F2(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class De_Jong_F3 : public Function
{
    public:
        De_Jong_F3(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class Goldstein_Price : public Function
{
    public:
        Goldstein_Price(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class Rosenbrock : public Function
{
    public:
        Rosenbrock(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

class Zakharov : public Function
{
    public:
        Zakharov(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;

    private:
        De_Jong_F1 djf1;
};

class Schwefel : public Function
{
    public:
        Schwefel(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

static constexpr float c1 = 1.0;
static constexpr float c2 = 1.0;
static constexpr float c3 = 1.0;
static constexpr int nb_iter = 2000;
static constexpr int nb_run = 101;
static constexpr int n_particles = 40;
