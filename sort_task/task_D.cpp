# include <iostream>
# include <vector>

int BubbleSort(const std::vector<int> &A) {
    std::vector<int> sort_A = A;
    int n = sort_A.size();
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sort_A[j + 1] < sort_A[j]) {       
                std::swap(sort_A[j + 1], sort_A[j]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    int swaps = BubbleSort(A);

    std::cout << swaps << "\n";

    return 0;
}