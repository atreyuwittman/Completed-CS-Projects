#include <cmath>
#include <iostream>

class Fraction
{
        int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }
        int n, d;
    public:
        Fraction(int n, int d = 1) : n(n/gcd(std::abs(n),std::abs(d))), d(d/gcd(std::abs(n),std::abs(d))) {
            if (this->d < 0) {
                this->n *= -1;
                this->d *= -1;
            }
        }
        int num() const { return n; }
        int den() const { return d; }
        Fraction(){
            n = 0;
            d = 1;
        }
        Fraction& operator*=(const Fraction& rhs) {
            int new_n = n*rhs.n / gcd(std::abs(n*rhs.n), std::abs(d*rhs.d));
            d = d*rhs.d / gcd(std::abs(n*rhs.n), std::abs(d*rhs.d));
            n = new_n;
            return *this;
        }
        Fraction& operator-=(const Fraction& rhs) {
            int new_num = (n * rhs.d) - (d * rhs.n);
            int new_den = d * rhs.d;
            n = new_num / gcd(std::abs(new_num), std::abs(new_den));
            d = new_den / gcd(std::abs(new_num), std::abs(new_den));
            return *this;
        }
        Fraction & operator=(const Fraction& rhs){
            this->n = rhs.n;
            this->d = rhs.d;
            return *this;
        }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    return out << f.num() << '/' << f.den() ;
}
bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.num() * rhs.den()) == (rhs.num() * lhs.den()));
}
bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs) {
    return lhs *= rhs;
}
Fraction operator-(Fraction lhs, const Fraction& rhs){
    return lhs -= rhs;
}

