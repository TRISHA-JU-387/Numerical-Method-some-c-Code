#include<bits/stdc++.h>
using namespace std;


void dividedDifferenceTable(vector<double>& x, vector<vector<double>>& table, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]) / (x[j + i] - x[j]);
        }
    }
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(10) << table[i][j] << "\t";
        cout << endl;
}
}

double newtonInterpolation(vector<double>& x, vector<vector<double>>& table, double xi, int n) {
    double result = table[0][0];

    double product = 1.0;
    for (int i = 1; i < n; i++) {
        product *= (xi - x[i - 1]);
        result += product * table[0][i];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    vector<vector<double>> table(n, vector<double>(n));

    cout << "Enter the x and y values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> table[i][0];
    }

    dividedDifferenceTable(x, table, n);

    double xi;
    cout << "Enter the value of x to interpolate: ";
    cin >> xi;

    double yi = newtonInterpolation(x, table, xi, n);

    cout << "The interpolated value at x = " << xi << " is y = " << yi << endl;

    return 0;
}

