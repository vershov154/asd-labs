#include <iostream>
#include <vector>
#include <algorithm>


struct Point {
    int x;
    int y;
};

bool comparePoints(const Point& a, const Point& b) {
    return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }
    
    stable_sort(points.begin(), points.end(), comparePoints);
    
    for (int i = 0; i < n; ++i) {
        std::cout << points[i].x << " " << points[i].y << "\n";
    }
    
    return 0;
}