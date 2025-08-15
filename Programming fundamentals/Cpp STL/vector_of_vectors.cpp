/*
 * vector_of_vectors.cpp
 * Demonstrates usage of std::vector<std::vector<int>> in C++.
 * Definition: A vector of vectors is a 2D dynamic array where each row can have a different number of elements.
 * Shows major operations: insert, access, iterate, size, clear, etc.
 * Run this file independently to see 2D vector operations in action.
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix;

    // Insert rows
    matrix.push_back({1, 2, 3});
    matrix.push_back({4, 5});
    matrix.push_back({6});

    // Access and print elements
    cout << "Matrix contents:" << endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Add an element to a specific row
    matrix[1].push_back(99);
    cout << "After adding 99 to row 1: ";
    for (int n : matrix[1]) cout << n << " ";
    cout << endl;

    // Iterate using range-based for
    cout << "All rows:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    // Size
    cout << "Number of rows: " << matrix.size() << endl;
    cout << "Size of row 0: " << matrix[0].size() << endl;

    // Clear a row
    matrix[2].clear();
    cout << "After clearing row 2, size: " << matrix[2].size() << endl;

    // Clear all
    matrix.clear();
    cout << "After clearing matrix, number of rows: " << matrix.size() << endl;

    return 0;
}
