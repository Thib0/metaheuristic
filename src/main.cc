#include <iostream>

#include "mheu.hh"

int main(void)
{
    Recruit r;
    r.init_initial_state();
    std::cout << r.compute_total_length() << std::endl;
    r.randomize();
    std::cout << r.compute_total_length() << std::endl;
    return 0;
}
