/*
 * File: typedef_impl.cpp
 * Implementation of template-based stack with multiple data types
 * Author: Gaurav
 * Date: 2025
 * 
 * This file demonstrates the use of templates to create a generic stack that can work with:
 * 1. Integer data type (stack<int>)
 * 2. Character data type (stack<char>)
 * 3. Double data type (stack<double>)
 */

#include <iostream>
#include <stdexcept>

using namespace std;

// Constants for better maintainability
const int MAX_ARRAY_SIZE = 100;
const int STACK_EMPTY_VALUE = -1;

/*
 * Template class representing a generic stack data structure
 * 
 * This template class implements a stack that can work with any data type.
 * It provides basic stack operations: push, pop, peek, and isEmpty.
 * 
 * Template parameter T: The data type for the stack elements
 */
template <typename T>
class Stack {
private:
    T data[MAX_ARRAY_SIZE];    // Array to store elements of type T
    int top;                   // Index of the top element
    
public:
    // Constructor to initialize the stack
    Stack() : top(STACK_EMPTY_VALUE) {
        // Initialize all elements to default value for type T
        for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
            data[i] = T();
        }
    }
    
    // Check if the stack is empty
    // Returns: true if stack is empty, false otherwise
    bool isEmpty() const {
        return top == STACK_EMPTY_VALUE;
    }
    
    // Check if the stack is full
    // Returns: true if stack is full, false otherwise
    bool isFull() const {
        return top == MAX_ARRAY_SIZE - 1;
    }
    
    // Push an element onto the stack
    // Parameter: value - The value of type T to push
    // Throws: overflow_error if stack is full
    void push(T value) {
        if (isFull()) {
            throw overflow_error("Stack overflow: Cannot push to full stack");
        }
        data[++top] = value;
    }
    
    // Pop an element from the stack
    // Returns: The top element of the stack
    // Throws: underflow_error if stack is empty
    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: Cannot pop from empty stack");
        }
        return data[top--];
    }
    
    // Peek at the top element without removing it
    // Returns: The top element of the stack
    // Throws: underflow_error if stack is empty
    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: Cannot peek empty stack");
        }
        return data[top];
    }
    
    // Get the current size of the stack
    // Returns: Number of elements in the stack
    int size() const {
        return top + 1;
    }
    
    // Display all elements in the stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            cout << data[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
};

// Function to demonstrate the use of template stack with different data types
void demonstrateTemplateStack() {
    cout << "=== Template Stack Implementation Demo ===" << endl;
    
    // Demonstrate with integer stack
    cout << "\n--- Integer Stack (stack<int>) ---" << endl;
    Stack<int> intStack;
    
    try {
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.push(40);
        intStack.push(50);
        
        cout << "Integer stack size: " << intStack.size() << endl;
        intStack.display();
        cout << "Top element: " << intStack.peek() << endl;
        cout << "Popped: " << intStack.pop() << endl;
        intStack.display();
    } catch (const exception& e) {
        cerr << "Error with int stack: " << e.what() << endl;
    }
    
    // Demonstrate with character stack
    cout << "\n--- Character Stack (stack<char>) ---" << endl;
    Stack<char> charStack;
    
    try {
        charStack.push('A');
        charStack.push('B');
        charStack.push('C');
        charStack.push('D');
        charStack.push('E');
        
        cout << "Character stack size: " << charStack.size() << endl;
        charStack.display();
        cout << "Top element: " << charStack.peek() << endl;
        cout << "Popped: " << charStack.pop() << endl;
        charStack.display();
    } catch (const exception& e) {
        cerr << "Error with char stack: " << e.what() << endl;
    }
    
    // Demonstrate with double stack
    cout << "\n--- Double Stack (stack<double>) ---" << endl;
    Stack<double> doubleStack;
    
    try {
        doubleStack.push(3.14);
        doubleStack.push(2.718);
        doubleStack.push(1.414);
        doubleStack.push(0.577);
        doubleStack.push(2.236);
        
        cout << "Double stack size: " << doubleStack.size() << endl;
        doubleStack.display();
        cout << "Top element: " << doubleStack.peek() << endl;
        cout << "Popped: " << doubleStack.pop() << endl;
        doubleStack.display();
    } catch (const exception& e) {
        cerr << "Error with double stack: " << e.what() << endl;
    }
    
    // Demonstrate error handling
    cout << "\n--- Error Handling Demo ---" << endl;
    Stack<int> emptyStack;
    
    try {
        emptyStack.pop(); // This should throw an exception
    } catch (const underflow_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

// Main function to run the demonstration
// Returns: 0 on successful execution
int main() {
    try {
        demonstrateTemplateStack();
        cout << "\n=== Demo completed successfully ===" << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
} 