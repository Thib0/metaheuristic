#include <iostream>
#include "swarm.hh"

int main(void)
{
    De_Jong_F1 djf1 = De_Jong_F1("djf1", 4, -5.12, 5.12); //gbest 0, vect (0, .., 0)
    Michalewicz mich1 = Michalewicz("micha_dim_2", 2, 0.0, M_PI); // gbset -1.80
    Michalewicz mich2 = Michalewicz("micha_dim_5", 5, 0.0, M_PI); // gbest -4.687
    Michalewicz mich3 = Michalewicz("micha_dim_10", 10, 0.0, M_PI); // gbest -9.68
    De_Jong_F2 djf2 = De_Jong_F2("djf2", 2, -2.048, 2.048); // gbest 0 vect (0, 0)
    De_Jong_F3 djf3_1 = De_Jong_F3("djf3_dim_2", 2, -5.12, 5.12); // gbest -6*dim = -12
    De_Jong_F3 djf3_2 = De_Jong_F3("djf3_dim_5", 5, -5.12, 5.12); // gbest -6*dim = -30
    Goldstein_Price gld_price = Goldstein_Price("gld_price", 2, -2.0, 2.0); // gbest = 3 vect(-1, 0)
    Rosenbrock ros = Rosenbrock("rosenbrock", 4, -2.048, 2.048); // gbest 0 vect (1, .. 1)
    Zakharov zak = Zakharov("zakharov", 4, -5.0, 10.0); // gbest 0 vect (0, ... 0)
    Schwefel sch = Schwefel("schefel", 4, -500.0, 500.0); //gbest - n * 418.9829 vect (420.9687, .. 420.9687)

    std::vector<Function*> functions = { &djf1, &mich1, &mich2, &mich3, &djf2,
                                         &djf3_1, &djf3_2, &gld_price, &ros,
                                         &zak, &sch };

    for (auto f : functions)
    {
        Swarm s = Swarm(f, 20000, 101, 40);
        s.resolve();
        std::cout << "function: " << f->getName() << " best " << s.gBest << std::endl;
        std::cout << "sol vector:\n";
        for (auto i : s.solution)
            std::cout << i << ", ";
        std::cout << "\n\n";

    }
    return 0;
}
