#include<bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-10;

void print_vector(const vector<double>& v) {
    for (double val : v) {
        cout << setw(10) << val << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    vector<double> x(n, 0.0); // Initial guess

    // Input A matrix
    cout << "Enter the coefficients of the system (A matrix):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Input b vector
    cout << "Enter the constants (B vector):\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<double> x_old(n);
    int iterations = 0;

    while (true) {
        for (int i = 0; i < n; ++i) {
            x_old[i] = x[i];
        }

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < n; ++i) {
            max_error = max(max_error, fabs(x[i] - x_old[i]));
        }

        ++iterations;
        cout << "Iteration " << iterations << ": ";
        print_vector(x);

        if (max_error < EPSILON) {
            break;
        }
    }

    cout << endl << "Solution after " << iterations << " iterations:\n";
    print_vector(x);  // Generalize solution printing

    return 0;
}
