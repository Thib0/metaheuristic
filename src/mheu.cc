#include <cassert>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "mheu.hh"

Recruit::Recruit() {}
Recruit::~Recruit() {}

typedef std::pair<short, short> pair;

void
Recruit::init_initial_state()
{
    // Init corners
    components_[0] = {1, 5};
    components_[4] = {3, 9};
    components_[20] = {15, 21};
    components_[24] = {19, 23};

    // Init top edges
    components_[1] = {0, 2, 6};
    components_[2] = {1, 3, 7};
    components_[3] = {2, 4, 8};

    // Init bottom edges
    components_[21] = {20, 22, 16};
    components_[22] = {21, 23, 17};
    components_[23] = {22, 24, 18};

    // Init right edges
    components_[5] = {0, 6, 10};
    components_[10] = {5, 11, 15};
    components_[15] = {10, 16, 20};

    // Init left edges
    components_[9] = {4, 8, 14};
    components_[14] = {9, 13, 19};
    components_[19] = {14, 18, 24};

    // Init inside
    components_[6] = {1, 5, 7, 11};
    components_[7] = {2, 6, 8, 12};
    components_[8] = {3, 7, 9, 13};
    components_[11] = {6, 10, 12, 16};
    components_[12] = {7, 11, 13, 17};
    components_[13] = {8, 12, 14, 18};
    components_[16] = {11, 15, 17, 21};
    components_[17] = {12, 16, 18, 22};
    components_[18] = {13, 17, 19, 23};
}

pair
get_coordinate(short index)
{
    return pair(index % 5, index / 5);
}

short
get_length(pair& a, pair& b)
{
    return std::abs(b.first - a.first) + std::abs(b.second - a.second);
}

short
Recruit::compute_total_length() const
{
    short total = 0;
    for (auto map_it = components_.begin(); map_it != components_.end(); ++map_it)
    {
        auto node_a = get_coordinate(map_it->first);
        for (auto vec_it = map_it->second.begin(); vec_it != map_it->second.end(); ++vec_it)
        {
            auto node_b = get_coordinate(*vec_it);
            total += get_length(node_a, node_b) * 5;
        }
    }
    return total / 2;
}

void
Recruit::swap(short key1, short key2)
{
    auto vec_tmp = std::vector<short>(components_[key1]);
    components_[key1] = components_[key2];
    components_[key2] = vec_tmp;
}

template <typename T>
short get_random_index(T& v)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, v.size() - 1);
    return dis(gen);
}

void
Recruit::randomize()
{
    for (int i = 0; i < 250; ++i)
        swap(get_random_index(components_), get_random_index(components_));
}

void
write_vector(std::ofstream& out, std::vector<short> v)
{
    for (auto& el : v)
        out << el << (el != v.back() ? "," : "");
    out << std::endl;
}

void
Recruit::export_components(unsigned count, bool last) const
{
    std::ofstream out;
    out.open("out/" + (last ? "last" : std::to_string(count)) + ".csv", std::ofstream::out
                                                      | std::ofstream::in
                                                      | std::ofstream::trunc);
    for (auto& c : components_)
    {
        out << c.first << ",";
        write_vector(out, c.second);
    }
    out.close();
}

void
Recruit::solve()
{
    std::cout << "Before solving: " << compute_total_length() << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    unsigned loop_counts = 0;
    export_components(loop_counts);
    while (compute_total_length() != optimum && temp >= stop)
    {
        auto key1 = get_random_index(components_);
        auto key2 = get_random_index(components_);
        auto last_length = compute_total_length();

        swap(key1, key2);
        auto current_length = compute_total_length();

        if (current_length > last_length)
        {
            swap(key2, key1);
            assert(compute_total_length() == last_length);
        }

        temp *= tau;
        ++loop_counts;
        if (!(loop_counts % 200))
            export_components(loop_counts);
    }
    export_components(loop_counts, true);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "After solving: " << compute_total_length() << std::endl;
    std::cout << "Execution time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count()
        << " milliseconds" << std::endl;

    std::cout << "Loop counts: " << loop_counts << std::endl;
}
