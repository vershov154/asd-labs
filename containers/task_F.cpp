#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> d;

    for (int i = 0; i < n; ++i) {

        while (!d.empty() && arr[d.back()] >= arr[i]) {
            d.pop_back();
        }


        d.push_back(i);


        if (d.front() <= i - k) {
            d.pop_front();
        }

        if (i >= k - 1) {
            cout << arr[d.front()] << "\n";
        }
    }

    return 0;
}
