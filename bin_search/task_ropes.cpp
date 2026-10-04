#include <iostream>
#include <vector>

using namespace std;

bool good(double x, const vector<int>& a, int k) {
    int cnt = 0;
    for (int len : a) {
        cnt += (int)(len / x);
    }
    return cnt >= k;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double l = 0;
    double r = 10000000 + 1; 

    for (int i = 0; i < 100; ++i) {
        double m = (l + r) / 2;
        if (good(m, a, k)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << (int)l << "\n";

    return 0;
}
