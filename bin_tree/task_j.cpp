#include <iostream>
#include <memory>

using namespace std;

template<class T>
struct Node {
    T data;
    int count;
    unique_ptr<Node<T>> left;
    unique_ptr<Node<T>> right;

    Node(T val) : data(val), count(1), left(nullptr), right(nullptr) {}
};

void add(unique_ptr<Node<int>>& root, int val) {
    if (!root) {
        root = make_unique<Node<int>>(val);
        return;
    }
    if (val == root->data) {
        root->count++; 
        return;
    }
    if (val < root->data) {
        add(root->left, val);
    } else {
        add(root->right, val);
    }
}

template<class T>
void printFrequencies(const Node<T>* p) {
    if (!p) {
        return;
    }
    printFrequencies(p->left.get());
    cout << p->data << " " << p->count << "\n";
    printFrequencies(p->right.get());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root = nullptr;
    int n;

    while (cin >> n && n != 0) {
        add(root, n);
    }

    printFrequencies(root.get());

    return 0;
}
