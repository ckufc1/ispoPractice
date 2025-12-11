#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

void accessInvalidMemory() {
    vector<int> arr(5);
    cout << arr.at(10) << endl;
}

int rec(int n) {
    if (n > 10) {
        return 0;
    }
    cout << n << " ";
    
    return rec(n + 1);
}   

int main() {
    try {
        accessInvalidMemory();
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    rec(1);
    cout << endl;
    return 0;
}
