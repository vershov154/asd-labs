#include <iostream>
#include <memory>
#include <algorithm> 
#include <cmath>     

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
        return false; // Дубликаты не добавляем
    }
    if (val < root->data) {
        return add(root->left, val);
    } else {
        return add(root->right, val);
    }
}

template<class T>
int height(const Node<T>* p) {
    if (!p) {
        return 0;
    }
    return 1 + max(height(p->left.get()), height(p->right.get()));
}

template<class T>
bool isBalanced(const Node<T>* p) {
    if (!p) {
        return true;
    }
    int leftH = height(p->left.get());
    int rightH = height(p->right.get());

    return abs(leftH - rightH) <= 1 &&
           isBalanced(p->left.get()) &&
           isBalanced(p->right.get());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root = nullptr;
    int n;

    while (cin >> n && n != 0) {
        add(root, n);
    }

    if (isBalanced(root.get())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
