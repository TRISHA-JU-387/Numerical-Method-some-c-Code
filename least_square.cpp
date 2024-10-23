#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the x and y values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = ";
        cin >> x[i];
        cout << "y[" << i + 1 << "] = ";
        cin >> y[i];

        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / n;

    cout << "The best fit line is: y = " << a<<" + "  << b << "x  "  << endl;

    return 0;
}

