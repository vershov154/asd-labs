#include <iostream>
#include <string>
#include <memory> 
#include <utility> 

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


bool search(const Node<int>* root, int val) {
    if (!root) {
        return false;
    }
    if (val == root->data) {
        return true;
    }
    if (val < root->data) {
        return search(root->left.get(), val);
    } else {
        return search(root->right.get(), val);
    }
}


bool removeNode(unique_ptr<Node<int>>& root, int val) {
    if (!root) {
        return false;
    }

    if (val < root->data) {
        return removeNode(root->left, val);
    } else if (val > root->data) {
        return removeNode(root->right, val);
    } else {
        if (!root->left) {
            root = move(root->right);
            return true;
        }
        if (!root->right) {
            root = move(root->left);
            return true;
        }

        Node<int>* maxLeft = root->left.get();
        while (maxLeft->right) {
            maxLeft = maxLeft->right.get();
        }

        root->data = maxLeft->data;
        return removeNode(root->left, maxLeft->data);
    }
}

template<class T>
void print_tree(const Node<T>* p, int level) {
    if (!p) {
        return;
    }
    print_tree(p->left.get(), level + 1);
    for (int i = 0; i < level; i++) {
        cout << ".";
    }
    cout << p->data << "\n";
    print_tree(p->right.get(), level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root = nullptr;
    string command;

    while (cin >> command) {
        if (command == "ADD") {
            int n;
            cin >> n;
            cout << (add(root, n) ? "DONE\n" : "ALREADY\n");
        } else if (command == "DELETE") {
            int n;
            cin >> n;
            cout << (removeNode(root, n) ? "DONE\n" : "CANNOT\n");
        } else if (command == "SEARCH") {
            int n;
            cin >> n;
            cout << (search(root.get(), n) ? "YES\n" : "NO\n");
        } else if (command == "PRINTTREE") {
            print_tree(root.get(), 0);
        }
    }

    return 0;
}
