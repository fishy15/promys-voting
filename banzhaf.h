#include <vector>
#include "fraction.h"

#ifndef BANZHAF_H
#define BANZHAF_H

namespace banzhaf {
    std::vector<fraction> calc_index(fraction to_win, const std::vector<fraction> &voting);
    namespace details {
        std::vector<fraction> calc_index(fraction to_win, const std::vector<fraction> &voting, int pos, std::vector<bool> &chosen);
    }
}

#endif
