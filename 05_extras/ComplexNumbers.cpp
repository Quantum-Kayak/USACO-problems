#include <iostream>     // cout, cin
#include <cmath>        // sqrt, abs, pow, atan2
#include <iomanip>      // setprecision (for printing decimals)
#include <cassert>      // assert (for sanity/suffering)
#include <utility>      // optional: std::pair if you lose control
#include <vector>       // optional: std::vector if you make a collection
#include <string>       // optional: debugging, stringifying stuff

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

struct Complex {
    double real, imag;

    Complex add(Complex A, Complex B) {
        Complex C;
        C.real = A.real + B.real;
        C.imag = A.imag + B.imag;
        return C;
    }

    Complex Subtract(Complex A, Complex B) {
        Complex C;
        C.real = A.real - B.real;
        C.imag = A.imag - B.imag;
        return C;
    }
    //A = a + bi, B = c + di,
    //A * B = (ac - bd) + (ad + bc)i
    Complex Multiply(Complex A, Complex B) {
        Complex C;
        C.real = A.real * B.real;
        C.imag = A.imag * B.imag;
    }

    //A = a + bi, B = c + di,
    //= (ac+bd)/c^2+d^2​+(bc−ad)/c^2+d^2 * ​i
    Complex Divide(Complex A, Complex B) {
        Complex C;
        double denom = B.real * B.real + B.imag * B.imag;

        C.real = (A.real * B.real + A.imag * B.imag) / denom;
        C.imag = (A.imag * B.real - A.real * B.imag) / denom;

        return C;
    }

    Complex Conjugate(Complex A) {
        return Complex{A.real, -A.imag};
    }
    // |A| = sqrt(a² + b²)
    double Magnitude(Complex A) {
        return sqrt(A.real * A.real + A.imag * A.imag);
    }
};

struct Complex1 {
    double real, imag;

    Complex1 add(const Complex1& other) const {
        return Complex1{real + other.real, imag + other.imag};
    }

    Complex1 subtract(const Complex1& other) const {
        return Complex1{real - other.real, imag - other.imag};
    }

    Complex1 Multiply(const Complex1& other) const {
        return Complex1{
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real 
        };
    }

    Complex1 Divide(const Complex1& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex1{
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom      
        };
    }

    Complex1 Conjugate() const {
        return Complex1{real, -imag};
    }

    double Magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

struct Complex2 {
    double real, imag;

    // === Arithmetic Operators ===
    Complex2 operator+(const Complex2& other) const {
        return {real + other.real, imag + other.imag};
    }

    Complex2 operator-(const Complex2& other) const {
        return {real - other.real, imag - other.imag};
    }

    Complex2 operator*(const Complex2& other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    Complex2 operator/(const Complex2& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return {
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        };
    }

    // === Unary Negation ===
    Complex2 operator-() const {
        return {-real, -imag};
    }

    // === Conjugate and Magnitude ===
    Complex2 conjugate() const {
        return {real, -imag};
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // === Friend Output Stream ===
    friend ostream& operator<<(ostream& os, const Complex2& z) {
        os << z.real;
        if (z.imag >= 0) os << " + ";
        else os << " - ";
        os << abs(z.imag) << "i";
        return os;
    }

    // === Friend Input Stream (bonus points) ===
    friend istream& operator>>(istream& is, Complex2& z) {
        return is >> z.real >> z.imag;
    }

    bool operator==(const Complex2& other) const {
        return real == other.real && imag == other.imag;
    }

    Complex2& operator+=(const Complex2& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex2& operator-=(const Complex2& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex2& operator*=(const Complex2& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    Complex2& operator/=(const Complex2& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        real = r;
        imag = i;
        return *this;
    }

    
};

int main() {

    return 0;
}
