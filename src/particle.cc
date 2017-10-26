#include "particle.hh"
#include <cfloat>
#include <limits>
#include <random>
#include <functional>

float getRand(float min, float max)
{
    /*std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution <double> uid(min, max);

    return uid(rng);*/
    return (float)((max - min)*(std::rand()/(float)RAND_MAX) + min);
}

Particle::Particle(Function* f)
{
  f_ = f;

  vMax_ = f->getMax() - f->getMin();

  for (size_t i = 0; i < f->getDimension(); i++)
  {
    pos_.push_back(getRand(f->getMin(), f->getMax()));
    speed_.push_back(0);
  }

  bestVal_ = FLT_MAX;
}

float Particle::solve()
{
  float res = f_->solve(pos_);
  if (res < bestVal_)
  {
    bestVal_ = res;
    bestPos_ = pos_;
  }

  return res;
}

void Particle::update(const std::vector<float> gBest, float c1, float c2, float c3)
{
  std::vector<float> newSpeed;

  for (size_t i = 0; i < f_->getDimension(); i++)
  {
    newSpeed.push_back(c1 * speed_[i] + getRand(0, c2) * (bestPos_[i] - pos_[i])
        + getRand(0, c3) * (gBest[i] - pos_[i]));

    pos_[i] += newSpeed[i];

    if (pos_[i] > f_->getMax())
      pos_[i] = f_->getMax();
    if (pos_[i] < f_->getMin())
      pos_[i] = f_->getMin();
  }

  speed_ = newSpeed;
}

std::vector<float> Particle::getBestPos()
{
  return bestPos_;
}
