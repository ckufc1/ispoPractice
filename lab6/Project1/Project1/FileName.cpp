#include <iostream>
#include <vector>

using namespace std;

class FactorialCalculator {
private:
    vector<unsigned long long> results;
    unsigned long long result = 1;

public:
    unsigned long long calculate(int n) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            result = 1;
            return result;
        }

        unsigned long long tempResult = 1;
        for (int i = 1; i <= n; i++) {
            tempResult = tempResult * i;
        }

        result = tempResult;
        return result;
    }

    void calculateRange(int start, int end) {
        results.clear();

        if (start > end) {
            cout << "error: start > end." << endl;
            return;
        }
        int currentStart = (start < 0) ? 0 : start;

        for (int i = currentStart; i <= end; i++) {
            results.push_back(calculate(i));
        }
    }

    unsigned long long getLastResult() { return result; }
    vector<unsigned long long> getAllResults() { return results; }
};

int main() {
    setlocale(0, "ru");
    FactorialCalculator calculator;
    int choice;

    cout << "1 - одно число" << endl;
    cout << "2 - диапазон" << endl;
    cout << "Выбор: ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Введите число: ";
        cin >> num;
        cout << num << "! = " << calculator.calculate(num) << endl;
    }
    else if (choice == 2) {
        int start, end;
        cout << "Начало: ";
        cin >> start;
        cout << "Конец: ";
        cin >> end;
        calculator.calculateRange(start, end);

        vector<unsigned long long> res = calculator.getAllResults();
        int index = (start < 0) ? 0 : start;
        for (unsigned long long val : res) {
            cout << index << "! = " << val << endl;
            index++;
        }
    }

    cin.get();
    cin.get();

    return 0;
}