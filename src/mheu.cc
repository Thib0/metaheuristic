#include <cstdlib>
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
