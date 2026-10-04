#include <iostream>

using namespace std;

bool good(long long cnt, long long q, long long s, long long t) {
    return (t / q) + (t / s) >= cnt;
}

int main() {

    long long n, x, y; 
    cin >> n >> x >> y;

    long long quick = min(x, y);
    long long slow = max(x, y);

    long long l = 0;
    long long r = (n - 1) * quick; 

    while (r - l > 1) {
        long long m = (l + r) / 2;
        
        if (good(n - 1, quick, slow, m)) {
            r = m; 
        } else {
            l = m; 
        }
    }

    cout << r + quick << "\n";

    return 0;
}
