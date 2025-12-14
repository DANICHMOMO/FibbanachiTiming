#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

long long fibIterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter term n: ";
    cin >> n;
    auto start = high_resolution_clock::now();
    long long resIter = fibIterative(n);
    auto stop = high_resolution_clock::now();
    auto durationIter = duration_cast<microseconds>(stop - start);

    cout << "\nIterative Result: " << resIter << endl;
    cout << "Time taken: " << durationIter.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    long long resRec = fibRecursive(n);
    stop = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(stop - start);

    cout << "\nRecursive Result: " << resRec << endl;
    cout << "Time taken: " << durationRec.count() << " microseconds" << endl;

    return 0;
}
