#include <iostream>
#include <memory>

using namespace std;


template<class T>
struct Node {
    T data;
    unique_ptr<Node<T>> left;
    unique_ptr<Node<T>> right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};


bool add(unique_ptr<Node<int>>& root, int val) {
    if (!root) {
        root = make_unique<Node<int>>(val);
        return true;
    }
    if (val == root->data) {
        return false;
    }
    if (val < root->data) {
        return add(root->left, val);
    } else {
        return add(root->right, val);
    }
}


template<class T>
int countNodes(const Node<T>* p) {
    if (!p) {
        return 0;
    }
    return 1 + countNodes(p->left.get()) + countNodes(p->right.get());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root = nullptr;
    int n;

    while (cin >> n && n != 0) {
        add(root, n);
    }

    cout << countNodes(root.get()) << "\n";

    return 0;
}
