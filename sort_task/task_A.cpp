# include <iostream>
# include <vector>

std::vector<int> SelectionSort(const std::vector<int>& A) {
    std::vector<int> sort_A = A;
    int n = sort_A.size();

    for (int i = 0; i < n - 1; ++i) {
        int imax = i;
        for (int j = i + 1; j < n; ++j) {
            if (sort_A[j] > sort_A[imax]) imax = j;
        }

        if (imax != i) std::swap(sort_A[i], sort_A[imax]);
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

    std::vector<int> sorted_A = SelectionSort(A);

    for (int x : sorted_A) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}