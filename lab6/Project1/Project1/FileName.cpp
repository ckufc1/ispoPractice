#include <iostream>
#include <vector>

using namespace std;

class FactorialCalculator {
private:
    vector<unsigned long long> results;
    unsigned long long result = 1;

public:
    int calculate(int n) {
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

//test
int main() {
    FactorialCalculator calculator;

    cout << "Factorial of 5: " << calculator.calculate(5) << endl;

    cout << "Range calculation (3 to 6):" << endl;
    calculator.calculateRange(3, 6);

    vector<unsigned long long> res = calculator.getAllResults();
    for (unsigned long long val : res) {
        cout << val << " ";
    }

    cin.get();
    cout << endl;
}