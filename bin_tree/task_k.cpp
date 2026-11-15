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

void add(unique_ptr<Node<int>>& root, int val) {
    if (!root) {
        root = make_unique<Node<int>>(val);
        return;
    }
    if (val == root->data) {
        return;
    }
    if (val < root->data) {
        add(root->left, val);
    } else {
        add(root->right, val);
    }
}

template<class T>
T nextElement(const Node<T>* root, T val) {
    const Node<T>* curr = root;
    T ans = -1;

    while (curr != nullptr) {
        if (curr->data == val) {
            return val;
        } else if (curr->data > val) {
            ans = curr->data;
            curr = curr->left.get();
        } else {
            curr = curr->right.get();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    unique_ptr<Node<int>> root = nullptr;
    const int MOD = 1000000000;
    int last_y = 0;
    bool prev_was_query = false;

    for (int step = 0; step < n; step++) {
        char op;
        int i;
        cin >> op >> i;

        if (op == '+') {
            if (prev_was_query) {
                i = ((1LL * i + last_y) % MOD + MOD) % MOD;
            }
            add(root, i);
            prev_was_query = false;
        } else if (op == '?') {
            last_y = nextElement(root.get(), i);
            cout << last_y << "\n";
            prev_was_query = true;
        }
    }

    return 0;
}
