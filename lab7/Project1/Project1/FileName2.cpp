#include <iostream>
#include <stdexcept>

using namespace std;

struct Fraction {
    int n;
    int d;
};

struct MathFractionOperations {

    static Fraction simplify(Fraction f) {
        if (f.d == 0) {
            throw std::invalid_argument("Знаменатель равен 0");
        }

        int a = f.n;
        int b = f.d;

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        f.n = f.n / a;
        f.d = f.d / a;

        return f;
    }

    static Fraction add(Fraction f1, Fraction f2) {
        Fraction res;
        res.n = f1.n * f2.d + f2.n * f1.d;
        res.d = f1.d * f2.d;
        return simplify(res);
    }

    static Fraction multiply(Fraction f1, Fraction f2) {
        Fraction res;
        res.n = f1.n * f2.n;
        res.d = f1.d * f2.d;
        return simplify(res);
    }

    static double toDecimal(Fraction f) {
        if (f.d == 0) throw std::invalid_argument("Деление на ноль");
        return (double)f.n / f.d;
    }
};

//int main() {
//    setlocale(LC_ALL, ""); 
//
// 
//    Fraction a = { 1, 2 };
//    Fraction b = { 2, 4 }; 
//
//    cout << "Дробь 1: " << a.n << "/" << a.d << endl;
//    cout << "Дробь 2: " << b.n << "/" << b.d << endl;
//    cout << "----------------" << endl;
//
//
//    Fraction sumRes = MathFractionOperations::add(a, b);
//    cout << "Сумма: " << sumRes.n << "/" << sumRes.d << endl; 
//
//    Fraction multRes = MathFractionOperations::multiply(a, b);
//    cout << "Умножение: " << multRes.n << "/" << multRes.d << endl; 
//
//
//    double decimal = MathFractionOperations::toDecimal(a);
//    cout << "Десятичное число: " << decimal << endl; 
//
//    return 0;
//}