#include <iostream>

using namespace std;

bool good(long long x, long long w, long long h, long long n) {
    long long count = (x / w) * (x / h);
    return count >= n;
}

int main() {

    long long w, h, n;
    cin >> w >> h >> n;

    long long l = 0;
    long long r = 1;

    while (!good(r, w, h, n)) {
        r *= 2;
    }

    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (good(m, w, h, n)) {
            r = m; 
        } else {
            l = m;
        }
    }

    cout << r << "\n";
    return 0;
}
