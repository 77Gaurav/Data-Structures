/*
 * File: array_operations.cpp
 * Template-based array operations: traversal, insertion, and deletion
 * Author: Gaurav
 * Date: 2025
 * 
 * This file demonstrates fundamental array operations using templates:
 * 1. Traversal - visiting each element
 * 2. Insertion - adding elements at specific positions
 * 3. Deletion - removing elements from specific positions
 * 
 * Focus: Simplicity and learning with clear examples
 */

#include <iostream>
#include <stdexcept>

using namespace std;

// Constants for better maintainability
const int MAX_ARRAY_SIZE = 50;
const int INVALID_INDEX = -1;

/*
 * Template class for array operations
 * 
 * This class provides basic array operations including traversal,
 * insertion, and deletion with proper error handling.
 * 
 * Template parameter T: The data type for array elements
 */
template <typename T>
class ArrayOperations {
private:
    T data[MAX_ARRAY_SIZE];    // Array to store elements
    int size;                  // Current number of elements
    
public:
    // Constructor to initialize the array
    ArrayOperations() : size(0) {
        // Initialize all elements to default value for type T
        for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
            data[i] = T();
        }
    }
    
    // Get the current size of the array
    // Returns: Number of elements currently in the array
    int getSize() const {
        return size;
    }
    
    // Check if the array is empty
    // Returns: true if array is empty, false otherwise
    bool isEmpty() const {
        return size == 0;
    }
    
    // Check if the array is full
    // Returns: true if array is full, false otherwise
    bool isFull() const {
        return size == MAX_ARRAY_SIZE;
    }
    
    // Validate if an index is within bounds
    // Parameter: index - The index to validate
    // Returns: true if index is valid, false otherwise
    bool isValidIndex(int index) const {
        return index >= 0 && index < size;
    }
    
    // TRAVERSAL: Display all elements in the array
    void traverse() const {
        if (isEmpty()) {
            cout << "Array is empty - nothing to traverse" << endl;
            return;
        }
        
        cout << "Array traversal (forward): ";
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    // TRAVERSAL: Display elements in reverse order
    void traverseReverse() const {
        if (isEmpty()) {
            cout << "Array is empty - nothing to traverse" << endl;
            return;
        }
        
        cout << "Array traversal (reverse): ";
        for (int i = size - 1; i >= 0; --i) {
            cout << data[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
    
    // TRAVERSAL: Find and display element at specific index
    // Parameter: index - The index to access
    void traverseAtIndex(int index) const {
        if (!isValidIndex(index)) {
            cout << "Invalid index: " << index << " (valid range: 0 to " << size - 1 << ")" << endl;
            return;
        }
        
        cout << "Element at index " << index << ": " << data[index] << endl;
    }
    
    // INSERTION: Add element at the end of array
    // Parameter: value - The value to insert
    // Throws: overflow_error if array is full
    void insertAtEnd(T value) {
        if (isFull()) {
            throw overflow_error("Array is full - cannot insert more elements");
        }
        
        data[size] = value;
        size++;
        cout << "Inserted " << value << " at the end (index " << size - 1 << ")" << endl;
    }
    
    // INSERTION: Add element at specific position
    // Parameter: value - The value to insert
    // Parameter: position - The position where to insert (0-based index)
    // Throws: overflow_error if array is full
    // Throws: invalid_argument if position is invalid
    void insertAtPosition(T value, int position) {
        if (isFull()) {
            throw overflow_error("Array is full - cannot insert more elements");
        }
        
        if (position < 0 || position > size) {
            throw invalid_argument("Invalid position: " + to_string(position) + 
                                 " (valid range: 0 to " + to_string(size) + ")");
        }
        
        // Shift elements to make room for new element
        for (int i = size; i > position; --i) {
            data[i] = data[i - 1];
        }
        
        data[position] = value;
        size++;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // INSERTION: Add element at the beginning
    // Parameter: value - The value to insert
    void insertAtBeginning(T value) {
        insertAtPosition(value, 0);
    }
    
    // DELETION: Remove element from the end
    // Returns: The removed element
    // Throws: underflow_error if array is empty
    T deleteFromEnd() {
        if (isEmpty()) {
            throw underflow_error("Array is empty - cannot delete elements");
        }
        
        T removedElement = data[size - 1];
        size--;
        cout << "Deleted " << removedElement << " from the end" << endl;
        return removedElement;
    }
    
    // DELETION: Remove element from specific position
    // Parameter: position - The position to delete from (0-based index)
    // Returns: The removed element
    // Throws: underflow_error if array is empty
    // Throws: invalid_argument if position is invalid
    T deleteFromPosition(int position) {
        if (isEmpty()) {
            throw underflow_error("Array is empty - cannot delete elements");
        }
        
        if (!isValidIndex(position)) {
            throw invalid_argument("Invalid position: " + to_string(position) + 
                                 " (valid range: 0 to " + to_string(size - 1) + ")");
        }
        
        T removedElement = data[position];
        
        // Shift elements to fill the gap
        for (int i = position; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        
        size--;
        cout << "Deleted " << removedElement << " from position " << position << endl;
        return removedElement;
    }
    
    // DELETION: Remove element from the beginning
    // Returns: The removed element
    T deleteFromBeginning() {
        return deleteFromPosition(0);
    }
    
    // Display current array state
    void displayArray() const {
        cout << "\n--- Current Array State ---" << endl;
        cout << "Size: " << size << "/" << MAX_ARRAY_SIZE << endl;
        cout << "Empty: " << (isEmpty() ? "Yes" : "No") << endl;
        cout << "Full: " << (isFull() ? "Yes" : "No") << endl;
        
        if (!isEmpty()) {
            cout << "Elements: ";
            for (int i = 0; i < size; ++i) {
                cout << "[" << i << ":" << data[i] << "]";
                if (i < size - 1) cout << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
};

// Function to demonstrate array operations with integers
void demonstrateIntegerArray() {
    cout << "\n=== INTEGER ARRAY OPERATIONS ===" << endl;
    ArrayOperations<int> intArray;
    
    try {
        // Initial state
        intArray.displayArray();
        
        // Insertion operations
        cout << "\n--- INSERTION OPERATIONS ---" << endl;
        intArray.insertAtEnd(10);
        intArray.insertAtEnd(20);
        intArray.insertAtEnd(30);
        intArray.insertAtBeginning(5);
        intArray.insertAtPosition(15, 2);
        
        intArray.displayArray();
        intArray.traverse();
        intArray.traverseReverse();
        
        // Traversal at specific index
        cout << "\n--- TRAVERSAL AT SPECIFIC INDEX ---" << endl;
        intArray.traverseAtIndex(2);
        intArray.traverseAtIndex(10); // Invalid index
        
        // Deletion operations
        cout << "\n--- DELETION OPERATIONS ---" << endl;
        intArray.deleteFromBeginning();
        intArray.deleteFromEnd();
        intArray.deleteFromPosition(1);
        
        intArray.displayArray();
        intArray.traverse();
        
    } catch (const exception& e) {
        cerr << "Error with integer array: " << e.what() << endl;
    }
}

// Function to demonstrate array operations with characters
void demonstrateCharacterArray() {
    cout << "\n=== CHARACTER ARRAY OPERATIONS ===" << endl;
    ArrayOperations<char> charArray;
    
    try {
        // Insertion operations
        cout << "\n--- INSERTION OPERATIONS ---" << endl;
        charArray.insertAtEnd('A');
        charArray.insertAtEnd('B');
        charArray.insertAtEnd('C');
        charArray.insertAtBeginning('Z');
        charArray.insertAtPosition('X', 2);
        
        charArray.displayArray();
        charArray.traverse();
        charArray.traverseReverse();
        
        // Deletion operations
        cout << "\n--- DELETION OPERATIONS ---" << endl;
        charArray.deleteFromPosition(1);
        charArray.deleteFromBeginning();
        
        charArray.displayArray();
        charArray.traverse();
        
    } catch (const exception& e) {
        cerr << "Error with character array: " << e.what() << endl;
    }
}

// Function to demonstrate array operations with doubles
void demonstrateDoubleArray() {
    cout << "\n=== DOUBLE ARRAY OPERATIONS ===" << endl;
    ArrayOperations<double> doubleArray;
    
    try {
        // Insertion operations
        cout << "\n--- INSERTION OPERATIONS ---" << endl;
        doubleArray.insertAtEnd(3.14);
        doubleArray.insertAtEnd(2.718);
        doubleArray.insertAtEnd(1.414);
        doubleArray.insertAtBeginning(0.577);
        doubleArray.insertAtPosition(2.236, 2);
        
        doubleArray.displayArray();
        doubleArray.traverse();
        doubleArray.traverseReverse();
        
        // Deletion operations
        cout << "\n--- DELETION OPERATIONS ---" << endl;
        doubleArray.deleteFromEnd();
        doubleArray.deleteFromPosition(1);
        
        doubleArray.displayArray();
        doubleArray.traverse();
        
    } catch (const exception& e) {
        cerr << "Error with double array: " << e.what() << endl;
    }
}

// Function to demonstrate error handling
void demonstrateErrorHandling() {
    cout << "\n=== ERROR HANDLING DEMO ===" << endl;
    ArrayOperations<int> errorArray;
    
    try {
        // Try to delete from empty array
        cout << "Attempting to delete from empty array..." << endl;
        errorArray.deleteFromEnd();
    } catch (const underflow_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    try {
        // Try to insert at invalid position
        cout << "\nAttempting to insert at invalid position..." << endl;
        errorArray.insertAtPosition(100, 5);
    } catch (const invalid_argument& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    // Fill array to capacity
    cout << "\nFilling array to capacity..." << endl;
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
        errorArray.insertAtEnd(i);
    }
    
    try {
        // Try to insert when array is full
        cout << "Attempting to insert when array is full..." << endl;
        errorArray.insertAtEnd(999);
    } catch (const overflow_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

// Main function to run all demonstrations
// Returns: 0 on successful execution
int main() {
    cout << "=== TEMPLATE ARRAY OPERATIONS DEMO ===" << endl;
    cout << "This program demonstrates traversal, insertion, and deletion operations" << endl;
    cout << "on template-based arrays with different data types." << endl;
    
    try {
        demonstrateIntegerArray();
        demonstrateCharacterArray();
        demonstrateDoubleArray();
        demonstrateErrorHandling();
        
        cout << "\n=== All demonstrations completed successfully ===" << endl;
        
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
} 