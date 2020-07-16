#ifndef FRAC_H
#define FRAC_H

class fraction {
private:
    long long n;
    long long d;
    void reduce();

public:
    static const fraction ZERO;
    static const fraction ONE;
    fraction(long long n, long long d);
    fraction inv() const;
    fraction operator+(const fraction &f2) const;
    fraction operator-(const fraction &f2) const;
    fraction operator*(const fraction &f2) const;
    fraction operator/(const fraction &f2) const;
    double to_double() const;
};

#endif
