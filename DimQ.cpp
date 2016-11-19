#include <typeinfo>
#include <iostream>
#include <iomanip>
#include "TypeIdFix/type.h"



// Обобщенный класс размерной величины. L, M, T, I, O, N, J - параметры шаблона - степени соответсвующих
// базовых размерностей при описании какой-то размерной величины.
template<int L, int M, int T, int I, int O, int N, int J>
class DimQ {
private:
    // Модуль размерной величины.
    double _value;

public:
    DimQ(double value) : _value(value) {};

    DimQ() : _value(0) {};


    double getVal() {
        return _value;
    }


    // Здесь и далее, кроме оператора <<, перегрузка осуществляеться с использованием функций-членов,
    // поэтому один операнд(тот, который вызывает оператор, для бинарных - левый) передается неявно.
    DimQ operator-() {
        return DimQ(-_value);
    }


    DimQ operator+(DimQ right) {
        return DimQ(_value + right._value);
    }


    DimQ operator-(DimQ right) {
        return DimQ(_value - right._value);
    }


    // При перегрузке оператора * и / нужно использовать шаблон, т.к. правый операнд(передается явно)
    // не должен совпадать по типу с левым. Возвращаемый тип зависит от переданных -
    // для * - сумма парраметров шаблона класса, для / - разность.
    template<int l, int m, int t, int i, int o, int n, int j>
    DimQ<L + l, M + m, T + t, I + i, O + o, N + n, J + j>
    operator*(DimQ<l, m, t, i, o, n, j> right) {
        return DimQ<L + l, M + m, T + t, I + i, O + o, N + n, J + j>
                (_value * right.getVal());
    };


    template<int l, int m, int t, int i, int o, int n, int j>
    DimQ<L - l, M - m, T - t, I - i, O - o, N - n, J - j>
    operator/(DimQ<l, m, t, i, o, n, j> right) {
        return DimQ<L - l, M - m, T - t, I - i, O - o, N - n, J - j>
                (_value / right.getVal());
    };


    // Для перегрузки оператора << используеться шаблон дружественной функции. Нельзя перегружать
    // с помощью функции-члена, потому что в таком случае операторной функции будет неявно передаваться
    // левый операнд - объект класса, но левый операнд для << обязательно должен быть потоком.
    // Почему функция должна быть шаблонной очевидно.
    template<int l, int m, int t, int i, int o, int n, int j>
    friend std::ostream &operator<<(std::ostream &out_stream,
                                    const DimQ<l, m, t, i, o, n, j> &);


};


///////////////////////////////////////////////////////////////////////////////////////////////////////////


template<int L, int M, int T, int I, int O, int N, int J>
std::ostream
&operator<<(std::ostream &out_stream, const DimQ<L, M, T, I, O, N, J> &V) {
    out_stream << V._value << " ";
    if (L) out_stream << "m^(" << L << ")";
    if (M) out_stream << "kg^(" << M << ")";
    if (T) out_stream << "s^(" << T << ")";
    if (I) out_stream << "A^(" << I << ")";
    if (O) out_stream << "K^(" << O << ")";
    if (N) out_stream << "mol^(" << N << ")";
    if (J) out_stream << "cd^(" << J << ")";
    return out_stream;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {

    using namespace std;
    typedef DimQ<0, 0, 0, 0, 0, 0, 0> Scalar;
    typedef DimQ<1, 0, 0, 0, 0, 0, 0> Length;
    typedef DimQ<0, 0, 1, 0, 0, 0, 0> Time;
    typedef DimQ<1, 0, -1, 0, 0, 0, 0> Velocity;
    typedef DimQ<1, 0, -2, 0, 0, 0, 0> Acceleration;


    Scalar sc = 100;
    Length l1 = 15;
    Time t1 = 5;
    auto s = l1 / t1;
    auto a1 = l1 / t1 / t1;
    auto ad100 = a1 / sc;
    auto lx100 = s * t1 * sc + l1;
    auto smth = sc * t1 / t1 + sc;


    cout << setw(35) << left << type(l1) << setw(10) << l1 << "\n"
         << setw(35) << left << type(t1) << setw(10) << t1 << "\n"
         << setw(35) << left << type(s) << setw(10) << s << "\n"
         << setw(35) << left << type(a1) << setw(10) << a1 << "\n"
         << setw(35) << left << type(ad100) << setw(10) << ad100 << "\n"
         << setw(35) << left << type(lx100) << setw(10) << lx100 << "\n"
         << setw(35) << left << type(smth) << setw(10) << smth << "\n\n\n";


    Length l = {100};
    Time t = {20};
    Velocity v = l / t;
    Acceleration a = v / t;

    auto smth1 = v * a * a / t;
    auto dimensionless = v / v;

    cout << v << endl;
    cout << a << endl;
    cout << smth1 << endl;
    cout << dimensionless << endl;


    return 0;
}





