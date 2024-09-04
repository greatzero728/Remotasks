#include <iostream>

using namespace std;

int main() {
    long long n, k, t;
    cin >> n >> k >> t;
    cout << ((n - 1) % (k - t)) + t + 1;
}