#include <iostream>
using namespace std;

// 1. Square of stars
void pattern_square_stars(int n) {
    /*
    Pattern for n = 3:
    * * *
    * * *
    * * *
    */
    // Theory: Prints an n x n grid of stars using nested loops.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

// 2. Square of same numbers (row-wise)
void pattern_square_same_numbers(int n) {
    /*
    Pattern for n = 3:
    1 1 1
    2 2 2
    3 3 3
    */
    // Theory: Each row contains the same number, equal to the row index (1-based).
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 3. Square of increasing numbers (column-wise)
void pattern_square_increasing_numbers(int n) {
    /*
    Pattern for n = 3:
    1 2 3
    1 2 3
    1 2 3
    */
    // Theory: Each row contains numbers from 1 to n.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 4. Square of decreasing numbers (column-wise)
void pattern_square_decreasing_numbers(int n) {
    /*
    Pattern for n = 3:
    3 2 1
    3 2 1
    3 2 1
    */
    // Theory: Each row contains numbers from n to 1.
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 5. Square of consecutive numbers
void pattern_square_consecutive_numbers(int n) {
    /*
    Pattern for n = 3:
    1 2 3
    4 5 6
    7 8 9
    */
    // Theory: Fills an n x n grid with consecutive numbers from 1 to n*n.
    int num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << num++ << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 6. Left-aligned triangle of stars
void pattern_left_triangle_stars(int n) {
    /*
    Pattern for n = 3:
    *
    * *
    * * *
    */
    // Theory: Each row contains one more star than the previous row.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

// 7. Left-aligned triangle of numbers (row-wise)
void pattern_left_triangle_numbers(int n) {
    /*
    Pattern for n = 3:
    1
    2 2
    3 3 3
    */
    // Theory: Each row contains the row number, repeated as many times as the row index.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 8. Left-aligned triangle of consecutive numbers
void pattern_left_triangle_consecutive(int n) {
    /*
    Pattern for n = 3:
    1
    2 3
    4 5 6
    */
    // Theory: Fills the triangle with consecutive numbers, increasing left to right, top to bottom.
    int num = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << num++ << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 9. Left-aligned triangle with increasing start
void pattern_left_triangle_increasing_start(int n) {
    /*
    Pattern for n = 3:
    1
    2 3
    3 4 5
    */
    // Theory: Each row starts with its index and increases by 1 for each column.
    for (int i = 1; i <= n; ++i) {
        int val = i;
        for (int j = 1; j <= i; ++j) {
            cout << val++ << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 10. Left-aligned triangle with decreasing start
void pattern_left_triangle_decreasing_start(int n) {
    /*
    Pattern for n = 3:
    1
    2 1
    3 2 1
    */
    // Theory: Each row starts with its index and decreases by 1 for each column.
    for (int i = 1; i <= n; ++i) {
        int val = i;
        for (int j = 1; j <= i; ++j) {
            cout << val-- << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 11. Square of same alphabets (row-wise)
void pattern_square_same_alphabets(int n) {
    /*
    Pattern for n = 3:
    A A A
    B B B
    C C C
    */
    // Theory: Each row contains the same alphabet, starting from 'A'.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << char('A' + i) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 12. Square of increasing alphabets (column-wise)
void pattern_square_increasing_alphabets(int n) {
    /*
    Pattern for n = 3:
    A B C
    A B C
    A B C
    */
    // Theory: Each row contains alphabets from 'A' to 'A'+n-1.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 13. Diagonal star pattern (right-aligned)
void pattern_diagonal_stars(int n) {
    /*
    Pattern for n = 3:
        *
      * *
    * * *
    */
    // Theory: Prints a right-aligned lower triangle of stars.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= n + 1 - i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

// 14. V-shaped star pattern
void pattern_v_shape_stars(int n) {
    /*
    Pattern for n = 3:
    * * *
      * *
        *
    */
    // Theory: Prints an inverted right-aligned triangle of stars.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

// 15. Right-aligned triangle of stars
void pattern_right_triangle_stars(int n) {
    /*
    Pattern for n = 3:
        *
      * *
    * * *
    */
    // Theory: Each row contains stars aligned to the right.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= n + 1 - i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;
    pattern_square_stars(n);
    pattern_square_same_numbers(n);
    pattern_square_increasing_numbers(n);
    pattern_square_decreasing_numbers(n);
    pattern_square_consecutive_numbers(n);
    pattern_left_triangle_stars(n);
    pattern_left_triangle_numbers(n);
    pattern_left_triangle_consecutive(n);
    pattern_left_triangle_increasing_start(n);
    pattern_left_triangle_decreasing_start(n);
    pattern_square_same_alphabets(n);
    pattern_square_increasing_alphabets(n);
    pattern_diagonal_stars(n);
    pattern_v_shape_stars(n);
    pattern_right_triangle_stars(n);
    return 0;
}
