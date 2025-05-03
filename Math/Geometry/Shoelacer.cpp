#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double shoelace_area(const vector<Point>& pts) {
    int n = pts.size();
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += (pts[i].x * pts[j].y) - (pts[j].x * pts[i].y);
    }

    return fabs(area) / 2.0;
}

int main() {
    vector<Point> polygon = {{0,0}, {4,0}, {4,3}, {0,3}};
    cout << "Area: " << shoelace_area(polygon) << endl; // Output: 12.0
    return 0;
}
