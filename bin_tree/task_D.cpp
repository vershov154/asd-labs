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
T findSecondMax(const Node<T>* root) {
    const Node<T>* parent = nullptr;
    const Node<T>* curr = root;

    while (curr->right != nullptr) {
        parent = curr;
        curr = curr->right.get();
    }

    if (curr->left != nullptr) {
        curr = curr->left.get();
        while (curr->right != nullptr) {
            curr = curr->right.get();
        }
        return curr->data;
    }

    return parent->data;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root = nullptr;
    int n;

    while (cin >> n && n != 0) {
        add(root, n);
    }

    cout << findSecondMax(root.get()) << "\n";

    return 0;
}
