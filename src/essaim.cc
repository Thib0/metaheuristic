#include <iostream>
#include "swarm.hh"
#include <fstream>
#include <sstream>

void run_particules(Function* f)
{
    std::stringstream str;
    str << f->getName() << "_particules.txt";

    std::ofstream file;
    file.open(str.str(), std::ios::out);

    if (!file)
    {
        std::cerr << "Error: could not open/create file" << std::endl;
        exit(1);
    }

    file << f->getName() << " particules" << std::endl;

    for (int nb_particules = 10; nb_particules < 1000; nb_particules++)
    {
        float gBest = 0.0;
        int nb_run = 100;

        for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, 2000, 100, nb_particules);
            s.resolve();
            gBest += s.gBest;
        }
        file << nb_particules << " " << (gBest / nb_run) << std::endl;
    }

    file.close();
}

void run_iterations(Function* f)
{
    std::stringstream str;
    str << f->getName() << "_iterations.txt";
    std::ofstream file;
    file.open(str.str(), std::ios::out);

    if (!file)
    {
        std::cerr << "Error: could not open/create file" << std::endl;
        exit(1);
    }

    file << f->getName() << " iterations" << std::endl;

    for (int nb_iter = 100; nb_iter < 10000; nb_iter += 100)
    {
        float gBest = 0;
        int nb_run = 100;
        for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, nb_iter, 100, 40);
            s.resolve();
            gBest += s.gBest;
        }

        file << nb_iter << " " << (gBest / nb_run) << std::endl;
    }

    file.close();
}

void run_c1(Function* f)
{
    std::stringstream str;
    str << f->getName() << "_c1.txt";
    std::ofstream file;
    file.open(str.str(), std::ios::out);

    if (!file)
    {
        std::cerr << "Error: could not open/create file" << std::endl;
        exit(1);
    }

    file << f->getName() << " c1" << std::endl;

    for (float c = 0.0; c < 50.0; c += 0.05)
    {
        float gBest = 0;
        int nb_run = 100;
        for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, 2000, 100, 40, c, 1.0, 1.0);
            s.resolve();
            gBest += s.gBest;
        }

        file << c << " " << (gBest / nb_run) << std::endl;
    }

    file.close();
}

void run_c2(Function* f)
{
    std::stringstream str;
    str << f->getName() << "_c2.txt";
    std::ofstream file;
    file.open(str.str(), std::ios::out);

    if (!file)
    {
        std::cerr << "Error: could not open/create file" << std::endl;
        exit(1);
    }

    file << f->getName() << " c2" << std::endl;

    for (float c = 0.0; c < 50.0; c += 0.05)
    {
        float gBest = 0;
        int nb_run = 100;
        for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, 2000, 100, 40, 1.0, c, 1.0);
            s.resolve();
            gBest += s.gBest;
        }

        file << c << " " << (gBest / nb_run) << std::endl;
    }


    file.close();
}

void run_c3(Function* f)
{
    std::stringstream str;
    str << f->getName() << "_c3.txt";
    std::ofstream file;
    file.open(str.str(), std::ios::out);

    if (!file)
    {
        std::cerr << "Error: could not open/create file" << std::endl;
        exit(1);
    }

    file << f->getName() << " c3" << std::endl;

    for (float c = 0.0; c < 50.0; c += 0.05)
    {
        float gBest = 0;
        int nb_run = 100;
        for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, 2000, 100, 40, 1.0, 1.0, c);
            s.resolve();
            gBest += s.gBest;
        }

        file << c << " " << (gBest / nb_run) << std::endl;
    }

    file.close();
}

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


    //std::cout << "LAUNCH REGULAR SWARM" << std::endl;

    for (auto f : functions)
    {
        //Function *f = &gld_price;
        float gBest = 0;
        int nb_run = 100;
        std::vector<float> solution;
        //for (int i = 0; i < nb_run; i++)
        {
            Swarm s = Swarm(f, 10000, 100, 50, 1.0, 1.0, 2.0);
            s.resolve();
            gBest += s.gBest;
            solution = s.solution;
        }

        float moy_best = gBest / nb_run;
        std::cout << "function: " << f->getName() << " moyenne  best " << (gBest) << std::endl;
        std::cout << "sol vector:\n";
        for (auto i : solution)
            std::cout << i << ", ";
        std::cout << "\n\n";
    }

    std::cout << "LAUNCH STAT SWARM" << std::endl;

    for (auto f : functions)
    {
        //Function *f = &sch;
        run_particules(f);
        run_iterations(f);
        run_c1(f);
        run_c2(f);
        run_c3(f);
    }

    return 0;
}
