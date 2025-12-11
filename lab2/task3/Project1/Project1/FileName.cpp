#include <iostream>
#include <random>

using namespace std;

int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 100.0);
    double n{};
    volatile double result = 0;

    for (int i = 0; i < 1000000; i++) {
        n = dis(gen);
        cout << n << endl;
        result += n;
    }
    cout << result;
    return 0;
}