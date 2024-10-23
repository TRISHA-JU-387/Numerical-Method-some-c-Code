#include<bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-10;
int main()
{
    int n;
    cout << "Enter the number of equation: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    vector<double> x(n, 0.0);
#
    cout << "Enter the coefficients of the system (A matrix):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants (B vector):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    cout << setw(10) <<"    ";
     cout << setw(10)  << "  x";
     cout << setw(10)  << "  y";
     cout << setw(10) << "  z";
    vector<double> x_new(n);
    int iterations = 0;
    if(iterations!=0)
        cout << "Iteration " << iterations << ": ";
    if(iterations!=0)
        for (double val : x)
        {
            cout << setw(10) << val << " ";
        }
while (iterations<173)
    {
        for (int i = 0; i < n; ++i)
        {
            double sum = 0.0;
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < n; ++i)
        {
            max_error = max(max_error, fabs(x_new[i] - x[i]));
            x[i] = x_new[i];
        }

        iterations++;
        if(iterations !=0)
            cout << "Iteration " << iterations << ": ";
        for (double val : x)
        {
            cout << setw(10) << val << " ";
        }
        cout << endl;

        if (max_error < EPSILON )
        {
            break;
        }
    }
       cout<<endl <<"\t" ;
    cout << "Solution  is value of x= "<< x[0]<<" y = " <<x[1]<<" and z = "<<x[2]<<endl ;

    return 0;}

