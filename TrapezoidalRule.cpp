#include <bits/stdc++.h>
using namespace std;

inline double f(double x) {
    return exp(x);
}

int main() {
    double lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;


    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    ///h= (b-a)/n
    stepSize = (upper - lower) / subInterval;

    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;
        integration += 2 * f(k);
    }

    integration *= stepSize / 2;


    cout << endl << "\n\nRequired value of integration is: " << integration;
        cout<<endl<<endl<<endl ;
    return 0;
}
