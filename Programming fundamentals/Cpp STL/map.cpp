/*
 * map.cpp
 * Demonstrates usage of std::map in C++.
 * Definition: Map is a collection of key-value pairs, where each key is unique and mapped to a value, allowing fast lookup by key.
 * Shows major operations: insert, access, erase, find, iterate, size, clear, etc.
 * Run this file independently to see map operations in action.
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> age;

    // Insert elements
    age["Alice"] = 25;
    age["Bob"] = 30;
    age.insert({"Charlie", 22});

    // Access elements
    cout << "Alice's age: " << age["Alice"] << endl;

    // Iterate and print
    cout << "All ages:" << endl;
    for (const auto& entry : age) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Find element
    string name = "Bob";
    if (age.find(name) != age.end()) {
        cout << name << " found, age = " << age[name] << endl;
    } else {
        cout << name << " not found" << endl;
    }

    // Erase element
    age.erase("Alice");
    cout << "After erasing Alice:" << endl;
    for (const auto& entry : age) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Size
    cout << "Map size: " << age.size() << endl;

    // Clear all
    age.clear();
    cout << "After clear, map size: " << age.size() << endl;

    return 0;
}
