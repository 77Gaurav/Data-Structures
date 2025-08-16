#include <iostream>
#include <cmath> // for pow() and log2()
using namespace std;

/*
   CLEAN CODE PRINCIPLES DEMONSTRATION

   This file shows how to write clean and understandable C++ code
   for absolute beginners. Each function is small, focused, and
   well-named, with simple comments that explain what is happening.

   Author: [Your Name]
   Date: [Date]
*/

// -------------------------------------------------
// 1. SIMPLE INTEREST FUNCTION
// -------------------------------------------------

/*
// Generic/Mistake: Using int for monetary calculations loses precision
int simpleInterest(int p, int r, int t) {
    return (p * r * t) / 100;
}
*/
// Correct usage: Use double for precision
// Calculates simple interest using the formula:
// Simple Interest = (Principal * Rate * Time) / 100
// Explanation: Using double avoids truncation errors with decimals.
double calculateSimpleInterest(double principal, double rate, double time) {
    return (principal * rate * time) / 100.0;
}

// -------------------------------------------------
// 2. CHECK EVEN NUMBER
// -------------------------------------------------

/*
// Generic/Mistake: Unclear or verbose logic
bool even(int n) {
    if (n % 2 == 0) return true; else return false;
}
*/
// Correct usage: Use direct boolean expression
// Explanation: (n % 2 == 0) is already a boolean.
bool isEven_Modulus(int n) {
    return (n % 2 == 0);
}

/*
// Generic/Mistake: Using division or unnecessary steps
bool evenBitwise(int n) {
    return ((n / 2) * 2 == n);
}
*/
// Correct usage: Use bitwise AND for efficiency
// Explanation: (n & 1) checks the last bit; 0 means even.
bool isEven_Bitwise(int n) {
    return !(n & 1);
}

// -------------------------------------------------
// 3. CHECK IF NUMBER IS A POWER OF TWO
// -------------------------------------------------

/*
// Generic/Mistake: Using repeated division, which is less efficient
bool isPowerOfTwo_Division(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    return num == 1;
}
*/
// Correct usage: Use log2 for mathematical check
// Explanation: log2(num) is integer for powers of two.
bool isPowerOfTwo_Log(int num) {
    if (num <= 0) return false;
    double logVal = log2(num);
    return floor(logVal) == ceil(logVal);
}

/*
// Generic/Mistake: Using floating point for integer property
bool isPowerOfTwo_Float(int num) {
    return pow(2, round(log2(num))) == num;
}
*/
// Correct usage: Use integer multiplication
// Explanation: Multiply by 2 until reaching or exceeding num.
bool isPowerOfTwo_Iterative(int num) {
    if (num <= 0) return false;
    int power = 1;
    while (power < num) {
        power *= 2;
    }
    return power == num;
}

/*
// Generic/Mistake: Using loops for what can be done in one operation
bool isPowerOfTwo_Loop(int num) {
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (num & (1 << i)) count++;
    }
    return count == 1;
}
*/
// Correct usage: Use bitwise trick
// Explanation: Powers of two have only one bit set.
bool isPowerOfTwo_Bitwise(int num) {
    if (num <= 0) return false;
    return !(num & (num - 1));
}

// -------------------------------------------------
// 4. ADDITIONAL EXAMPLE
// -------------------------------------------------

/*
// Generic/Mistake: No base case or unclear recursion
int fact(int n) {
    return n * fact(n - 1);
}
*/
// Correct usage: Clear base case, descriptive name
// Explanation: Recursion stops at n <= 1.
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// -------------------------------------------------
// MAIN FUNCTION (Driver Code)
// -------------------------------------------------
int main() {
    cout << "=== Clean Code Examples ===" << endl;

    // Example 1: Simple Interest
    double si = calculateSimpleInterest(1000, 5, 2);
    cout << "Simple Interest (P=1000, R=5%, T=2 years): " << si << endl;

    // Example 2: Even check
    cout << "Is 10 even (modulus)? " << (isEven_Modulus(10) ? "Yes" : "No") << endl;
    cout << "Is 7 even (bitwise)? " << (isEven_Bitwise(7) ? "Yes" : "No") << endl;

    // Example 3: Power of Two
    cout << "Is 16 power of two (log)? " << (isPowerOfTwo_Log(16) ? "Yes" : "No") << endl;
    cout << "Is 18 power of two (iterative)? " << (isPowerOfTwo_Iterative(18) ? "Yes" : "No") << endl;
    cout << "Is 32 power of two (bitwise)? " << (isPowerOfTwo_Bitwise(32) ? "Yes" : "No") << endl;

    // Example 4: Factorial
    cout << "Factorial of 5: " << factorial(5) << endl;

    return 0;
}
