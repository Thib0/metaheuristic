#pragma once

#include <vector>
#include <string>

class Function
{
    public:
        Function(std::string name, int dimension, float min_range, float max_range);
        virtual float solve(std::vector<float> x) = 0;

        float getMax();
        float getMin();
        float getDimension();

    private:
        std::string name_;
        int dimension_;
        float min_range_;
        float max_range_;
};

class De_Jong_F1 : public Function
{
    public:
        De_Jong_F1(std::string name, int d, float min, float max);
        virtual float solve(std::vector<float> x) override;
};

static constexpr float c1 = 1.0;
static constexpr float c2 = 1.0;
static constexpr float c3 = 1.0;
static constexpr int nb_iter = 2000;
static constexpr int nb_run = 101;
static constexpr int n_particles = 40;
