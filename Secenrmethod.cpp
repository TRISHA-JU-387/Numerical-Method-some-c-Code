
#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

// Function whose root we want to find
double f(double x)
{
    return x * x - 4*x - 10 ; // Example function: x^2 - 25
}

// Secant method to find the root of the equation
double secantMethod(double x1, double x2)
{
    double x3;
    int i=1 ;
    do
    {
        x3 = x2 - ((f(x2) * (x2 - x1)) / (f(x2) - f(x1)));
        if (abs(x3 - x2) <= 0.001) // Check if difference is within epsilon
            return x3;
        cout << fixed << setprecision(8);
        cout<< i <<"                 "<<x1<< "                 "<<x2<<"                 "<<x3<<endl ;

        x1 = x2;
        x2 = x3;
        i++ ;
    }
    while (true);
}

int main()
{
    double x1, x2, epsilon;

    cout<<setw(10)<<"Using Secent Method : \n" ;
    cout<< "\tThe Equation is = x^2 -4^x -10 = 0 \n";



    cout << "Enter first initial guess (x1): ";
    cin >> x1;

    cout << "Enter second initial guess (x2): ";
    cin >> x2;

    cout << fixed << setprecision(8);

    cout<<"Iterator"<<setw(15)<<"X1"<<setw(25)<<"X2"<<setw(25)<<"X3"<<endl ;
    double root = secantMethod(x1, x2);

    cout << "\n\tRoot of the equation: " << root << endl;

    return 0;
}
