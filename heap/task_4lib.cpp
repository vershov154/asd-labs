#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    priority_queue<int> the_heap;
    
    string command;
    
    while (cin >> command) {
        if (command == "ADD") {
            int n;
            cin >> n;
            the_heap.push(n); 
        } 
        else if (command == "EXTRACT") {
            if (the_heap.empty()) {
                cout << "CANNOT\n"; 
            } else {
                cout << the_heap.top() << "\n";
                the_heap.pop();
            }
        } 
        else if (command == "CLEAR") {
            the_heap = priority_queue<int>();
        }
    }

    return 0;
}
