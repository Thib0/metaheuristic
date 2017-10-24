#include "swarm.hh"
#include <cfloat>

Swarm::Swarm(Function *f, size_t iter, size_t nbrun, size_t nbpar)
{
    nbParticles = nbpar;
    this->f = f;
    nbIter = iter;
    nbRun = nbrun;
    if (nbRun % 2 == 0)
        nbRun++;
    c1_ = 1.0;
    c2_ = 1.0;
    c3_ = 1.0;
}

Swarm::Swarm(Function *f, size_t iter, size_t nbrun, size_t nbpar, float c1,
             float c2, float c3)
{
    nbParticles = nbpar;
    this->f = f;
    nbIter = iter;
    nbRun = nbrun;
    if (nbRun % 2 == 0)
        nbRun++;
    c1_ = c1;
    c2_ = c2;
    c3_ = c3;
}

void Swarm::resolve(int precision)
{
  int gbest_idx = -1;
  initSwarm();

  for (size_t i = 0; i < nbIter; i++)
  {
    for (size_t p = 0; p < nbParticles; p++)
    {
      float res = particles[p].solve();
      if (res < gBest)
      {
        gBest = res;
        gbest_idx = p;
        solution = particles[p].getBestPos();
      }
    }

    for (size_t p = 0; p < nbParticles; p++)
      particles[p].update(particles[gbest_idx].getBestPos(), c1_, c2_, c3_);
  }
}

void Swarm::initSwarm()
{
  gBest = FLT_MAX;

  particles.clear();

  for (size_t i = 0; i < nbParticles; ++i)
    particles.push_back(Particle(f));
}
