#pragma once

#include "function.hh"
#include "particle.hh"

class Swarm
{
  public:
    Swarm(Function *f, size_t iter, size_t nbrun, size_t nbpar);

    void resolve(int precision = 4);
    float gBest;
    std::vector<float> solution;

  private:
    void initSwarm();

    size_t nbParticles;
    size_t nbIter;
    size_t nbRun;
    Function *f;
    std::vector<Particle> particles;
};
