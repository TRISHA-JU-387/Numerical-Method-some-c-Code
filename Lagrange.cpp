#include<bits/stdc++.h>

using namespace std;


double lagrange_Interpolation(vector<double>& x, vector<double>& y, double xi, int n) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the x and y values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];//f(x)
    }

    double xi;
    cout << "Enter the value of x to interpolate: ";
    cin >> xi;

    double yi = lagrange_Interpolation(x, y, xi, n);

    cout << "The interpolated value at x = " << xi << " is y = " << yi << endl;

    return 0;
}

