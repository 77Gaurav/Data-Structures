/*
 * vectors.cpp
 * Demonstrates usage of std::vector in C++.
 * Definition: Vectors are like arrays but with dynamic size, allowing elements to be added or removed easily.
 * Shows all major operations: insert, delete, access, iterate, search, size, clear, etc.
 * Run this file independently to see vector operations in action.
 */
#include <iostream>
#include <vector>
#include <algorithm> // for find
using namespace std;

int main() {
    vector<int> numbers;

    // Insert elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    cout << "After push_back: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Access elements
    cout << "Element at index 2: " << numbers[2] << endl;
    cout << "First element: " << numbers.front() << endl;
    cout << "Last element: " << numbers.back() << endl;

    // Insert at specific position
    numbers.insert(numbers.begin() + 1, 15);
    cout << "After insert at index 1: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Erase element at index 2
    numbers.erase(numbers.begin() + 2);
    cout << "After erase at index 2: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Iterate using iterator
    cout << "Iterate using iterator: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Search for an element
    int value = 20;
    auto found = find(numbers.begin(), numbers.end(), value);
    if (found != numbers.end()) {
        cout << value << " found at index " << (found - numbers.begin()) << endl;
    } else {
        cout << value << " not found" << endl;
    }

    // Size and capacity
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    // Clear all elements
    numbers.clear();
    cout << "After clear, size: " << numbers.size() << endl;

    return 0;
}
