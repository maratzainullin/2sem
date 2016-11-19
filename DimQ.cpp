#include <typeinfo>
#include <iostream>
#include <string>
#include "type.h"


template<int L, int M, int T, int I, int O, int N, int J>
class DimQ {
private:
    double value;

public:
    DimQ(double _value) : value(_value) {};

    DimQ() : value(0) {};


    double get_val() {
        return value;
    }


    DimQ operator-() {
        return DimQ(-value);
    }


    DimQ operator+(DimQ right) {
        return DimQ(value + right.value);
    }


    DimQ operator-(DimQ right) {
        return DimQ(value - right.value);
    }


    template<int l, int m, int t, int i, int o, int n, int j>
    DimQ<L + l, M + m, T + t, I + i, O + o, N + n, J + j>
    operator*(DimQ<l, m, t, i, o, n, j> right) {
        return DimQ<L + l, M + m, T + t, I + i, O + o, N + n, J + j>
                (value * right.get_val());
    };


    template<int l, int m, int t, int i, int o, int n, int j>
    DimQ<L - l, M - m, T - t, I - i, O - o, N - n, J - j>
    operator/(DimQ<l, m, t, i, o, n, j> right) {
        return DimQ<L - l, M - m, T - t, I - i, O - o, N - n, J - j>
                (value / right.get_val());
    };

};






typedef DimQ<0, 0, 0, 0, 0, 0, 0> scalar;
typedef DimQ<1, 0, 0, 0, 0, 0, 0> length;
typedef DimQ<0, 0, 1, 0, 0, 0, 0> time;
typedef DimQ<1, 0, -1, 0, 0, 0, 0> speed;
typedef DimQ<1, 0, -2, 0, 0, 0, 0> accelerate;


int main() {

    scalar sc = 100;
    length l = 15;
    time t = 5;
    auto s = l / t;
    auto a = l / t / t;
    auto ad100 = a / sc;
    auto lx100 = s * t * sc + l;
    auto smth = sc * t / t + sc;


    std::cout << "l: " << l.get_val() << " " << type(l) << "\n"
              << "t: " << t.get_val() << " " << type(t) << "\n"
              << "s: " << s.get_val() << " " << type(s) << "\n"
              << "a: " << a.get_val() << " " << type(a) << "\n"
              << "a/100: " << ad100.get_val() << " " << type(ad100) << "\n"
              << "l*100 + l: " << lx100.get_val() << " " << type(lx100) << "\n"
              << "sc * t / t + sc : " << smth.get_val() << " " << type(smth) << "\n";

}




