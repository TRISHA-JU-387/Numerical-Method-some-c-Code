#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find the transpose of a matrix
vector<vector<float>> Transpose(const vector<vector<float>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<float>> result(cols, vector<float>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Function to find the inverse of a matrix
vector<vector<float>> Inverse(const vector<vector<float>>& matrix) {
    int n = matrix.size();
    vector<vector<float>> identity(n, vector<float>(n));
    vector<vector<float>> inverse(n, vector<float>(n));
    for (int i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }

    // Gauss-Jordan elimination
    vector<vector<float>> augmented = matrix;
    for (int i = 0; i < n; ++i) {
        // Find pivot row
        int pivot_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(augmented[j][i]) > abs(augmented[pivot_row][i])) {
                pivot_row = j;
            }
        }
        // Swap rows
        if (pivot_row != i) {
            swap(augmented[i], augmented[pivot_row]);
            swap(identity[i], identity[pivot_row]);
        }
        // Make diagonal elements 1
        float pivot = augmented[i][i];
        for (int j = 0; j < n; ++j) {
            augmented[i][j] /= pivot;
            identity[i][j] /= pivot;
        }
        // Make other elements in column 0
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                float factor = augmented[j][i];
                for (int k = 0; k < n; ++k) {
                    augmented[j][k] -= factor * augmented[i][k];
                    identity[j][k] -= factor * identity[i][k];
                }
            }
        }
    }
    return identity;
}

// Function to multiply two matrices
vector<vector<float>> Multiply(const vector<vector<float>>& matrix1, const vector<vector<float>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();
    vector<vector<float>> result(rows1, vector<float>(cols2, 0));
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to print a matrix
void PrintMatrix(const vector<vector<float>>& matrix) {
    for (const auto& row : matrix) {
        for (float value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    // Create matrix A for coefficients and vector B for constants
    vector<vector<float>> A(n, vector<float>(n));
    vector<vector<float>> B(n, vector<float>(1));

    // Input matrix A and vector B
    cout << "Enter the coefficients of the equations:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
        cout << "Constant: ";
        cin >> B[i][0];
    }

    // Find the inverse of matrix A
    vector<vector<float>> A_inverse = Inverse(A);

    // Multiply A_inverse and B to find the solution vector X
    vector<vector<float>> X = Multiply(A_inverse, B);

    // Print the solution vector X
    cout << "The solution is:" << endl;
    PrintMatrix(X);

    return 0;
}
