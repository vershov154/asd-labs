# include <iostream>
# include <vector>

std::vector<int> InsertionSort(const std::vector<int> &A) {
    std::vector<int> sort_A = A;
    int n = sort_A.size();

    for (int i = 1; i < n; ++i) {
        int key = sort_A[i];
        int j = i - 1;
        while (j >= 0 && sort_A[j] > key) {
            sort_A[j + 1] = sort_A[j];
            j--;
        }
        sort_A[j + 1] = key;
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

    std::vector<int> sorted_A = InsertionSort(A);

    for (int x : sorted_A) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}