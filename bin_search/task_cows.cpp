#include <iostream>
#include <vector>

using namespace std;

bool good(const vector<int>& boxes, int k, int r) {
    int cows_count = 1;
    int last_box = boxes[0];
    
    // ИСПРАВЛЕНО: добавили инициализацию i = 1
    for (int i = 1; i < boxes.size(); ++i) {
        if (boxes[i] - last_box >= r) {
            cows_count++;
            last_box = boxes[i];
        }
    }
    return cows_count >= k;
}

int main() {
    int n, k, l, r;
    cin >> n >> k;
    
    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    l = 0;
    r = boxes[n - 1] - boxes[0] + 1;
    
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (good(boxes, k, m)) {
            l = m; 
        } else {
            r = m;
        }
    }
    cout << l << "\n";

    return 0;
}
