#include <vector>

#include "mheu.hh"

Recruit::Recruit() {}
Recruit::~Recruit() {}

void
Recruit::init_initial_state()
{
    // Init corners
    components_[0] = {1, 6};
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
    components_[11] = {6, 10, 16};
    components_[12] = {7, 11, 17};
    components_[13] = {8, 12, 18};
    components_[16] = {11, 15, 21};
    components_[17] = {12, 16, 22};
    components_[18] = {13, 17, 23};
}
