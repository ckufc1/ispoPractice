#include <iostream>

using namespace std;

int rec(int n) {
    if (n > 10) {
        return 0;
    }
    cout << n << " ";
    
    return rec(n + 1);
}   

int main() {
    rec(1);
    cout << endl;
    return 0;
}