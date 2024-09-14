#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <cmath>
#include <ostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    double get_real() const {return real;}
    double get_imag() const {return imag;}
    double Magnitude() const{
        return sqrt(pow(real,2) + pow(imag,2));
    }
    bool operator==(const Complex &other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    bool operator<(const Complex& other) const {
        return Magnitude() < other.Magnitude();
    }

    bool operator>(const Complex& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Complex& c){
        os << c.real << "+" << c.imag << "i";
        return os;
    }




};
#endif
