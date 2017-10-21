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
      particles[p].update(particles[gbest_idx].getBestPos());
  }
}

void Swarm::initSwarm()
{
  gBest = FLT_MAX;

  particles.clear();

  for (size_t i = 0; i < nbParticles; ++i)
    particles.push_back(Particle(f));
}
