// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

string stats( int n ) {
    if (n <=0) {
        return "Error: number must be greater than 0";
    }
    int array[n];

    for (int i = 0; i < n; i++ ) {
        cout << "Enter a number: ";
        cin >> array[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    double avg = sum / n;

    int max = array[0];
    for (int i = 0; i < n; i++) {
        if (array[i] > max){
            max = array[i];
        }
    }

    int min = array[0];
    for (int i = 0; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    cout << "Results: " << endl 
         << "Sum: " << sum << endl
         << "Average: " << avg << endl
         << "Maximum: " << max << endl
         << "Minimum: " << min << endl;
}

int main() {
    cout << "How many numbers? ";
    int n;
    cin >> n;

    cout << stats(n);
}