#pragma once

#include "function.hh"
#include <vector>

class Particle
{
  public:
    Particle(Function* f);

    float solve();
    void update(const std::vector<float> gBest, float c1, float c2, float c3);

    std::vector<float> getBestPos();

  private:
    std::vector<float> pos_;
    std::vector<float> speed_;
    std::vector<float> bestPos_;
    float bestVal_;
    float vMax_;

    Function* f_;
};
