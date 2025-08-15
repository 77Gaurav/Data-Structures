/*
 * stack.cpp
 * Demonstrates usage of std::stack in C++.
 * Definition: Stack is a container that follows Last-In-First-Out (LIFO) order, where elements are added and removed from the top.
 * Shows major operations: push, pop, top, size, empty, etc.
 * Run this file independently to see stack operations in action.
 */
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "After push: size = " << s.size() << endl;

    // Access top element
    cout << "Top element: " << s.top() << endl;

    // Pop element
    s.pop();
    cout << "After pop, top element: " << s.top() << endl;

    // Iterate (by popping all elements)
    cout << "Stack contents (from top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Check if empty
    cout << "Stack is empty: " << (s.empty() ? "yes" : "no") << endl;

    return 0;
}
