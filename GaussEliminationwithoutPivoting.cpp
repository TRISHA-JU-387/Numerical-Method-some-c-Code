
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    // Input matrix
    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
                cout<<"Matrix["<<i<<"]["<<j<<"]==" ;
            cin >> matrix[i][j];

        }
    }

     cout << "\n\n The Matrix is :\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
              if(j!=n)
            cout<< matrix[i][j]<<" ";
            else cout<<"= "<<matrix[i][j];

        }
        cout<<endl ;
    }


    for (int i = 0; i < n; ++i) {
        // Partial pivoting
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap the maximum row with current row (partial pivoting)
        for (int k = i; k <= n; ++k) {
            double temp = matrix[maxRow][k];
            matrix[maxRow][k] = matrix[i][k];
            matrix[i][k] = temp;
        }

        // Make all elements below the diagonal equal to 0
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back substitution
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    // Print the solution
    cout << "\n\nNOW THE SOLUTION OF THE GAUSS ELIMINATION METHOD WITH PIVOTING IS:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "] = " << solution[i] << endl;
    }
    return 0;
}
