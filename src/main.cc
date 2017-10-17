#include <iostream>

#include "mheu.hh"

int main(void)
{
    Recruit r;
    r.init_initial_state();
    std::cout << "Initializing: " << r.compute_total_length() << std::endl;
    r.randomize();
    r.solve();
    return 0;
}
