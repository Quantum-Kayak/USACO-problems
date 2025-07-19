#include <iostream>     // cout, cin
#include <cmath>        // sqrt, abs, pow, atan2
#include <iomanip>      // setprecision (for printing decimals)
#include <cassert>      // assert (for sanity/suffering)
#include <utility>      // optional: std::pair if you lose control
#include <vector>       // optional: std::vector if you make a collection
#include <string>       // optional: debugging, stringifying stuff

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

struct Complex  {
    double real, imag;

    // === Arithmetic Operators ===
    Complex  operator+(const Complex & other) const {
        return {real + other.real, imag + other.imag};
    }

    Complex  operator-(const Complex & other) const {
        return {real - other.real, imag - other.imag};
    }

    Complex operator*(const Complex & other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    Complex  operator/(const Complex & other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return {
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        };
    }

    // === Unary Negation ===
    Complex  operator-() const {
        return {-real, -imag};
    }

    // === Conjugate and Magnitude ===
    Complex  conjugate() const {
        return {real, -imag};
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // === Friend Output Stream ===
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        os << "(";
        os << z.real;
        if (z.imag >= 0) os << " + ";
        else os << " - ";
        os << std::abs(z.imag) << "i";
        os << ")";
        return os;
    }

    // === Friend Input Stream (bonus points) ===
    friend std::istream& operator>>(std::istream& is, Complex & z) {
        return is >> z.real >> z.imag;
    }

    bool operator==(const Complex & other) const {
        return real == other.real && imag == other.imag;
    }

    Complex & operator+=(const Complex & other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex & operator-=(const Complex & other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex & operator/=(const Complex & other) {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        real = r;
        imag = i;
        return *this;
    }

    static long long binom(int n, int k) {
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= n--;
            res /= i;
        }
        return res;
    }

    Complex& operator*=(const Complex& other) {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        real += 1;
        return temp;
    }
};
Complex multiply_power(const Complex& z, int n) {
    Complex result = {1, 0};
    for (int i = 0; i < n; ++i) {
        result *= z;
    }
    return result;
}

Complex operator^(const Complex& z, int n) {
    if (n < 0) throw std::invalid_argument("Nuh uh.");
    if (n == 0) return {1, 0};
    if (n <= 4) {
        double r = z.magnitude();
        double theta = atan2(z.imag, z.real);
        double rn = std::pow(r, n);
        double angle = theta * n;
        return {
            rn * std::cos(angle),
            rn * std::sin(angle)
        };
    } else {
        return multiply_power(z, n);
    }
}

Complex powz(const Complex& z, int n) {
    return ::operator^(z, n);
}

int main() {
    Complex z = {3, -5};
    std::cout << z;
    return 0;
}
