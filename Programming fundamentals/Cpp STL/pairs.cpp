/*
 * pairs.cpp
 * Demonstrates usage of std::pair in C++.
 * Definition: Pairs are simple containers to store two related values (possibly of different types) together as a single unit.
 * Shows major operations: creation, access, assignment, comparison, usage in containers.
 * Run this file independently to see pair operations in action.
 */
#include <iostream>
#include <vector>
#include <utility> // for pair
using namespace std;

int main() {
    // Create pairs
    pair<int, string> p1(1, "apple");
    pair<int, string> p2 = make_pair(2, "banana");

    // Access elements
    cout << "p1: (" << p1.first << ", " << p1.second << ")" << endl;
    cout << "p2: (" << p2.first << ", " << p2.second << ")" << endl;

    // Assignment
    p1 = p2;
    cout << "After assignment, p1: (" << p1.first << ", " << p1.second << ")" << endl;

    // Comparison
    pair<int, string> p3(2, "banana");
    if (p2 == p3) {
        cout << "p2 and p3 are equal" << endl;
    }

    // Using pairs in a vector
    vector<pair<int, int>> points;
    points.push_back({1, 2});
    points.push_back({3, 4});
    points.push_back(make_pair(5, 6));

    cout << "Points:" << endl;
    for (const auto& pt : points) {
        cout << "(" << pt.first << ", " << pt.second << ") ";
    }
    cout << endl;

    return 0;
}
