#include <iostream>
#include <vector>

void CountSort(std::vector<int>& arr) {
    std::vector<int> counter(101, 0);

    for (int x : arr) {
        counter[x]++;
    }

    int index = 0;
    for (int num = 0; num <= 100; ++num) {
        while (counter[num] > 0) {
            arr[index] = num;
            index++;
            counter[num]--;
        }
    }
}

int main() {

    std::vector<int> arr;
    int val;
    
    while (std::cin >> val) {
        arr.push_back(val);
    }

    CountSort(arr);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}