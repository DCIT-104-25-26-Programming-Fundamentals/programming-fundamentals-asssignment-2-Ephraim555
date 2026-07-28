// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void read_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


void display_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


// TRANSPOSE MATRIX
void transpose(int matrix[10][10],
               int result[10][10],
               int rows,
               int cols) {

    for (int i = 0; i < cols; i++) {
        for (int k = 0; k < rows; k++) {
            result[i][k] = matrix[k][i];
        }
    }
}


// ADD TWO MATRICES

void add_matrices(int matrix_1[10][10],
                  int matrix_2[10][10],
                  int result[10][10],
                  int rows,
                  int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
}


// MULTIPLY TWO MATRICES

bool mult_matrices(int matrix_1[10][10],
                   int matrix_2[10][10],
                   int result[10][10],
                   int rows_1,
                   int cols_1,
                   int rows_2,
                   int cols_2) {

    if (cols_1 != rows_2) {
        return false;
    }

    for (int i = 0; i < rows_1; i++) {
        for (int j = 0; j < cols_2; j++) {

            result[i][j] = 0;

            for (int k = 0; k < cols_1; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    return true;
}


// MAIN FUNCTION

int main() {
    // Transpose Matrix
    int rows, cols;
    int matrix[10][10];
    int result[10][10];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix:\n";
    read_matrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:\n";
    display_matrix(matrix, rows, cols);

    transpose(matrix, result, rows, cols);

    cout << "\nTransposed Matrix:\n";
    display_matrix(result, cols, rows);

    // ADD Matix
    int matrix_1[10][10];
    int matrix_2[10][10];
    int add_result[10][10];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix 1:\n";
    read_matrix(matrix_1, rows, cols);

    cout << "\nEnter Matrix 2:\n";
    read_matrix(matrix_2, rows, cols);

    add_matrices(matrix_1, matrix_2, add_result, rows, cols);

    cout << "\nMatrix 1:\n";
    display_matrix(matrix_1, rows, cols);

    cout << "\nMatrix 2:\n";
    display_matrix(matrix_2, rows, cols);

    cout << "\nSum of Matrix 1 and Matrix 2:\n";
    display_matrix(add_result, rows, cols);


    // MULTIPLICATION 
    int rows_1, cols_1;
    int rows_2, cols_2;
    int mult_result[10][10];

    cout << "Enter number of rows for Matrix 1: ";
    cin >> rows_1;

    cout << "Enter number of columns for Matrix 1: ";
    cin >> cols_1;

    cout << "\nEnter Matrix 1:\n";
    read_matrix(matrix_1, rows_1, cols_1);

    cout << "\nEnter number of rows for Matrix 2: ";
    cin >> rows_2;

    cout << "Enter number of columns for Matrix 2: ";
    cin >> cols_2;

    cout << "\nEnter Matrix 2:\n";
    read_matrix(matrix_2, rows_2, cols_2);

    bool multiplication_possible = mult_matrices(
        matrix_1,
        matrix_2,
        mult_result,
        rows_1,
        cols_1,
        rows_2,
        cols_2
    );

    cout << "\nMatrix 1:\n";
    display_matrix(matrix_1, rows_1, cols_1);

    cout << "\nMatrix 2:\n";
    display_matrix(matrix_2, rows_2, cols_2);

    if (multiplication_possible) {

        cout << "\nProduct of Matrix 1 and Matrix 2:\n";
        display_matrix(mult_result, rows_1, cols_2);

    } else {

        cout << "\nError: Matrix multiplication is not possible.\n";
        cout << "The number of columns in Matrix 1 must equal ";
        cout << "the number of rows in Matrix 2.\n";
    }

    return 0;
}