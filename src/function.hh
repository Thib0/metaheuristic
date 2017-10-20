#pragma once

#include <vector>

class Function
{

    public:
        virtual float solve(std::vector<float> x) = 0;

    private:
};

class De_Jong_F1 : public Function
{
    public:
        virtual float solve(std::vector<float> x) override;


};

static constexpr float c1 = 1.0;
static constexpr float c2 = 1.0;
static constexpr float c3 = 1.0;
static constexpr int nb_iter = 2000;
static constexpr int nb_run = 101;
static constexpr int n_particles = 40;
