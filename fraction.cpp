#include <numeric>
#include <string>
#include "fraction.h"

const fraction fraction::ZERO = fraction(0, 1);
const fraction fraction::ONE = fraction(1, 1);

void fraction::reduce() {
    long long gcd = std::gcd(n, d);
    n /= gcd;
    d /= gcd;
}

fraction::fraction(long long n, long long d) : n(n), d(d) {
    reduce();
}

fraction fraction::inv() const {
    return fraction(d, n);
}

fraction fraction::operator+(const fraction &f2) const {
    long long new_num = n * f2.d + f2.n * d;
    long long new_denom = d * f2.d;
    return fraction(new_num, new_denom);
}

fraction fraction::operator-(const fraction &f2) const {
    long long new_num = n * f2.d - f2.n * d;
    long long new_denom = d * f2.d;
    return fraction(new_num, new_denom);
}

fraction fraction::operator*(const fraction &f2) const {
    return fraction(n * f2.n, d * f2.d);
}

fraction fraction::operator/(const fraction &f2) const {
    return (*this) * f2.inv();
}

bool fraction::operator<(const fraction &f2) const {
    return n * f2.d < f2.n * d;
}

bool fraction::operator==(const fraction &f2) const {
    return !(*this < f2 && f2 < *this);
}

bool fraction::operator!=(const fraction &f2) const {
    return !(*this == f2);
}

bool fraction::operator>(const fraction &f2) const {
    return f2 < *this;
}

bool fraction::operator<=(const fraction &f2) const {
    return !(*this > f2);
}

bool fraction::operator>=(const fraction &f2) const {
    return !(*this < f2);
}

double fraction::to_double() const {
    return (double) n / d;
}

std::string fraction::to_string() const {
    return std::to_string(n) + " / " + std::to_string(d);
}

