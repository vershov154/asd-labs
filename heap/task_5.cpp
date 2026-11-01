#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        min_heap.push(val);
    }

    double total_cost = 0.0;

    while (min_heap.size() > 1) {
        int first = min_heap.top(); 
        min_heap.pop();
        
        int second = min_heap.top(); 
        min_heap.pop();

        int current_sum = first + second;
        total_cost += current_sum * 0.05;

        min_heap.push(current_sum);
    }

    printf("%.2f\n", total_cost);

    return 0;
}
