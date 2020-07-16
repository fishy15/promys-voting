#include <vector>
#include "fraction.h"

#ifndef BANZHAF_H
#define BANZHAF_H

namespace banzhaf {
    namespace {
        std::vector<fraction> calc_index(int to_win, const std::vector<fraction> &voting, int pos, std::vector<bool> &chosen) {
            if (pos == (int)(voting.size())) {
                std::vector<fraction> res(pos, fraction::ZERO);
                fraction sum(0, 1);

                for (int i = 0; i < pos; i++) {
                    if (chosen[i]) {
                        sum = sum + voting[i];
                    }
                }

                for (int i = 0; i < pos; i++) {
                    if (chosen[i]) {
                        res[i] = res[i] + fraction::ONE;
                    }
                }

                return res;
            }

            auto res1 = calc_index(to_win, voting, pos + 1, chosen);
            chosen[pos] = true;
            auto res2 = calc_index(to_win, voting, pos + 1, chosen);
            chosen[pos] = false;

            std::vector<fraction> res;
            for (int i = 0; i < (int)(voting.size()); i++) {
                res.push_back(res1[i] + res2[i]);
            }

            return res;
        }
    }

    std::vector<fraction> calc_index(int to_win, const std::vector<fraction> &voting) {
        int length = (int)(voting.size());
        std::vector<bool> chosen = std::vector<bool>(length);
        auto res = calc_index(to_win, voting, 0, chosen);

        fraction total = fraction::ZERO;
        for (int i = 0; i < length; i++) {
            total = total + res[i];
        }

        for (int i = 0; i < length; i++) {
            res[i] = res[i] / total;
        }

        return res;
    }
}

#endif
