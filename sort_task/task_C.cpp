#include <iostream>
#include <vector>

std::vector<int> BubbleSort(const std::vector<int> &A) {
    std::vector<int> sort_A = A;
    int n = sort_A.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sort_A[j + 1] > sort_A[j]) {
                std::swap(sort_A[j + 1], sort_A[j]);
            }
        }
    }
    return sort_A;
}

int main() {

    std::vector<int> A;

    int num; 
    int n = 0;

    while (std::cin >> num)
    {
        n++;
        A.push_back(num);

        if (std::cin.peek() == '\n') {
            break;
        }
    }


    std::vector<int> sorted_A = BubbleSort(A);

    for (int x : sorted_A) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}