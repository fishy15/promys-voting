#include <iostream>
#include <vector>
#include "../fraction.h"
#include "../banzhaf.h" 


void print_vector(const std::vector<fraction> &v);
void test_three_equal();
void test_four_diff();
void dictator();

int main() {
    test_three_equal();
    test_four_diff();
    dictator();
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

    std::vector<fraction> correct = {fraction(1, 3), fraction(1, 3), fraction(1, 3)};
    std::cout << "Correct: ";
    print_vector(correct);
    std::cout << std::endl;
}

void test_four_diff() {
    fraction to_win(7, 1);
    std::vector<fraction> weights = {fraction::ONE, fraction(2, 1), fraction(3, 1), fraction(4, 1)};
    std::cout << "Weights: ";
    print_vector(weights);

    auto res = banzhaf::calc_index(to_win, weights);
    std::cout << "Power Index: ";
    print_vector(res);

    std::vector<fraction> correct = {fraction(1, 10), fraction(1, 10), fraction(3, 10), fraction(1, 2)};
    std::cout << "Correct: ";
    print_vector(correct);
    std::cout << std::endl;
}

void dictator() {
    fraction to_win(10, 1);
    std::vector<fraction> weights = {fraction(10, 1), fraction(2, 1), fraction(3, 1), fraction(4, 1)};
    std::cout << "Weights: ";
    print_vector(weights);

    auto res = banzhaf::calc_index(to_win, weights);
    std::cout << "Power Index: ";
    print_vector(res);

    std::vector<fraction> correct = {fraction::ONE, fraction::ZERO, fraction::ZERO, fraction::ZERO};
    std::cout << "Correct: ";
    print_vector(correct);
    std::cout << std::endl;
}
