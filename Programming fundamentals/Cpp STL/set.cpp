/*
 * set.cpp
 * Demonstrates usage of std::set in C++.
 * Definition: Set is a collection of unique elements, automatically sorted, with fast search, insert, and delete operations.
 * Shows major operations: insert, erase, find, iterate, size, clear, etc.
 * Run this file independently to see set operations in action.
 */
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Insert elements
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(5); // duplicate, will not be added

    // Iterate and print
    cout << "Set contents: ";
    for (int n : s) cout << n << " ";
    cout << endl;

    // Find element
    int value = 3;
    if (s.find(value) != s.end()) {
        cout << value << " found in set" << endl;
    } else {
        cout << value << " not found in set" << endl;
    }

    // Erase element
    s.erase(1);
    cout << "After erasing 1: ";
    for (int n : s) cout << n << " ";
    cout << endl;

    // Size
    cout << "Set size: " << s.size() << endl;

    // Clear all
    s.clear();
    cout << "After clear, set size: " << s.size() << endl;

    return 0;
}
