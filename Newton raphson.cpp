#include<bits/stdc++.h>

using namespace std;

// Function whose root we want to find
double f(double x)
{
    return x * x - 3*x +2;
}

// Derivative of the function
double df(double x)
{
    return 2 * x -3;
}

// Newton-Raphson method
double newtonRaphson(double initial_guess)
{
    double x = initial_guess;
    double x1, x2;
    int i=1 ;
    do
    {
        x1 = x;
        x2 = x - f(x) / df(x);
        if (abs(x2 - x1) < 0.001)
        {
            // Check if difference is within epsilon
           // cout<< i <<"                 "<<x1<< "          "<<x2<<endl ;
            return x2;
        }
        x = x2;
        cout << fixed << setprecision(8);
       // cout<< i <<"                 "<<x1<< "          "<<x2<<endl ;

        i++ ;
    }
    while (1);
}

int main()
{
    double initial_guess, epsilon;
    cout<<setw(10)<<"Using Newton Raphson Method : \n" ;
    cout<< "\tThe Equation is = x^2 -3^x +2 = 0 ";
    cout << "\nEnter initial guess: ";
    cin >> initial_guess;
    cout<<endl ;

 //   cout<< "Iterator" << setw(20) << "X1" << setw(20) << "X2" << endl;



    double root = newtonRaphson(initial_guess);


    cout << "\n\tRoot of the equation: " << root << endl;

    return 0;
}
