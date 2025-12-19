#include <iostream>
#include <stdexcept>

using namespace std;

struct UnitConverter {
    static double celsiusToFahrenheit(double celsius) {
        if (celsius < -273.15) {
            throw std::invalid_argument("Температура ниже абсолютного нуля!");
        }
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    static double fahrenheitToCelsius(double fahrenheit) {
        if (fahrenheit < -459.67) {
            throw std::invalid_argument("Температура ниже абсолютного нуля!");
        }
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    static double metersToFeet(double meters) {
        if (meters < 0) {
            throw std::invalid_argument("Расстояние не может быть отрицательным!");
        }
        return meters * 3.28084;
    }

    static double feetToMeters(double feet) {
        if (feet < 0) {
            throw std::invalid_argument("Расстояние не может быть отрицательным!");
        }
        return feet / 3.28084;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        double c = 25.0;
        double f = UnitConverter::celsiusToFahrenheit(c);
        cout << c << " C = " << f << " F" << endl;

        double m = 10.0;
        double ft = UnitConverter::metersToFeet(m);
        cout << m << " м = " << ft << " футов" << endl;
 
    }
    catch (const std::exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}