#include <iostream>
#include <vector>
#include "../fraction.h"
#include "../banzhaf.h" 


void print_vector(const std::vector<fraction> &v);
void test_three_equal();

int main() {
    test_three_equal();
}

void print_vector(const std::vector<fraction> &v) {
    std::cout << '[';

    for (int i = 0; i < (int)(v.size()); i++) {
        std::cout << v[i].to_string();
        if (i < (int)(v.size()) - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

void test_three_equal() {
    fraction to_win(3, 2);
    std::vector<fraction> weights = {fraction::ONE, fraction::ONE, fraction::ONE};
    std::cout << "Weights: ";
    print_vector(weights);

    auto res = banzhaf::calc_index(to_win, weights);
    std::cout << "Power Index: ";
    print_vector(res);
}

