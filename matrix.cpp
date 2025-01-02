#include <iostream>
#include <cmath>
using namespace std;

void luDecomposition(double A[10][10], double L[10][10], double U[10][10], int n) {
    // Initialize L and U matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        // Compute U matrix
        for (int j = i; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        // Compute L matrix
        for (int j = i; j < n; j++) {
                L[i][i] = 1.0; // Diagonal elements of L are 1
                double sum = 0.0;
                for (int k = 0; k < i; k++) {
                    sum += L[j][k] * U[k][i];
                }
                if (U[i][i] == 0) {
                    cout << "LU decomposition failed: Zero pivot encountered." << endl;
                    return;
                }
                L[j][i] = (A[j][i] - sum) / U[i][i];
        
        }
    }
}

// Function to print a matrix
void printMatrix(double matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define matrix A
    double A[10][10] = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    double L[10][10], U[10][10];
    int n = 3; // Size of the matrix

    // Perform LU decomposition
    luDecomposition(A, L, U, n);

    // Print results
    cout << "Matrix A:" << endl;
    printMatrix(A, n);

    cout << "\nLower Triangular Matrix L:" << endl;
    printMatrix(L, n);

    cout << "\nUpper Triangular Matrix U:" << endl;
    printMatrix(U, n);

    return 0;
}