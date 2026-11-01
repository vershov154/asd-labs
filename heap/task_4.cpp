#include <iostream>
#include <vector>
#include <string>

class MaxHeap {
private:
    std::vector<int> heap;
    int size;

    void ShiftUp(int i) {
        while (i / 2 > 0 && heap[i] > heap[i / 2]) {
            std::swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    void shiftDown(int i) {
        while (i * 2 <= size) {
            int j = indMaxChild(i);
            if (heap[i] < heap[j]) {
                std::swap(heap[i], heap[j]);
            }
            i = j;
        }
    }    

    int indMaxChild(int i) {
        if (i * 2 + 1 > size) {
            return i * 2;
        }
        if (heap[i * 2] > heap[i * 2 + 1]) {
            return i * 2;
        }
        return i * 2 + 1;
    }

public:
    MaxHeap() {
        heap.push_back(0);
        size = 0;
    }

    void Insert(int x) {
        heap.push_back(x);
        size++;
        ShiftUp(size);
    }

    int delMax() {
        if (size == 0) {
            return -1;
        }
        int removed = heap[1];
        heap[1] = heap[size];
        size--;
        heap.pop_back(); 
        shiftDown(1);
        return removed;
    }

    void clear() {
        heap.clear();
        heap.push_back(0);
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    MaxHeap heap;
    std::string command;

    while (std::cin >> command) {
        if (command == "ADD") {
            int n;
            std::cin >> n;
            heap.Insert(n);
        } 
        else if (command == "EXTRACT") {
            if (heap.isEmpty()) {
                std::cout << "CANNOT\n";
            } else {
                std::cout << heap.delMax() << "\n";
            }
        } 
        else if (command == "CLEAR") {
            heap.clear();
        }
    }

    return 0;
}
