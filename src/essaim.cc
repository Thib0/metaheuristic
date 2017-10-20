#include <iostream>
#include "swarm.hh"

int main()
{
  De_Jong_F1 djf1 = De_Jong_F1("djf1", 4, -5.12, 5.12);
  Swarm s = Swarm(&djf1, 20000, 101, 40);
  std::cout << s.gBest << std::endl;
  s.resolve();
  std::cout << s.gBest << std::endl;
  std::cout << "sol vector:\n";
  for (auto i : s.solution)
    std::cout << i << ", ";
  std::cout << "\n";
  return 0;
}
