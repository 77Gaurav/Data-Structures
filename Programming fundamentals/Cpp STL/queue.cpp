/*
 * queue.cpp
 * Demonstrates usage of std::queue in C++.
 * Definition: Queue is a container that follows First-In-First-Out (FIFO) order, where elements are added at the back and removed from the front.
 * Shows major operations: push, pop, front, back, size, empty, etc.
 * Run this file independently to see queue operations in action.
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push elements
    q.push(100);
    q.push(200);
    q.push(300);
    cout << "After push: size = " << q.size() << endl;

    // Access front and back
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;

    // Pop element
    q.pop();
    cout << "After pop, front: " << q.front() << endl;

    // Iterate (by popping all elements)
    cout << "Queue contents (from front to back): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Check if empty
    cout << "Queue is empty: " << (q.empty() ? "yes" : "no") << endl;

    return 0;
}
