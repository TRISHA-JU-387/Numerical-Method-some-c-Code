#include <bits/stdc++.h>
using namespace std ;
const double EPS = 1e-9;
const int INF = 2;
int main() {
    // Input
    int n, m;
    cout << "Enter the number of equations: ";
    cin >> n;


    vector<vector<double>> matrix(n, vector<double>(n+1));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j <= n; ++j){
              cout<<"Matrix["<<i<<"]["<<j<<"]=" ;
            cin >> matrix[i][j];
    }
    } cout << "\n\n The Matrix is :\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
              if(j!=n)
            cout<< matrix[i][j]<<" ";
            else cout<<"= "<<matrix[i][j];

        }
        cout<<endl ;
    }


    // Gaussian Elimination
    vector<int> where(n, -1);
    for (int col = 0, row = 0; col < n && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(matrix[i][col]) > abs(matrix[sel][col]))
                sel = i;
        if (abs(matrix[sel][col]) < EPS)
            continue;
        for (int i = col; i <= n; ++i)
            swap(matrix[sel][i], matrix[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = matrix[i][col] / matrix[row][col];
                for (int j = col; j <= n; ++j)
                    matrix[i][j] -= matrix[row][j] * c;
            }
        ++row;
    }

    // Output
    vector<double> solution(n, 0);
    for (int i = 0; i < n; ++i)
        if (where[i] != -1)
            solution[i] = matrix[where[i]][n] / matrix[where[i]][i];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j)
            sum += solution[j] * matrix[i][j];
        if (abs(sum - matrix[i][n]) > EPS) {
            cout << "No solution exists.\n";
            return 0;
        }
    }
   cout<<"USING GAUSS ELIMINATION METHOD :\n" ;
    for (int i = 0; i < n; ++i)
        if (where[i] == -1) {
            cout << " THE MATRIX HAVE INFINITE SOLUTION.\n";
            return 0;
        }


    for (int i = 0; i < n; ++i)
        cout << "x" << i + 1 << " = " << solution[i] << std::endl;

    return 0;
}
