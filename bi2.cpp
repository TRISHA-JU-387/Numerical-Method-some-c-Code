#include<bits/stdc++.h>
using namespace  std ;
int main()
{    cout<<"USING BISECTION METHOD ALGORITHM "<<endl<<endl ; ;
    double a,b,c,d,fa,fb,fc,tolerance,Root ;
    cout<<" Enter  guess a :" ;
    cin>>a ;
    cout<<" Enter  guess b :  " ;
    cin>>b ;
    fa =a*a*a + 3*a - 5 ;
    fb =b*b*b + 3*b - 5 ;
    if(fa * fb  >0)
    {cout<<" No root is found " <<endl ;
        return 0 ;
    }
    int i=1 ;
    while(1)
{
        c= (a+b)/2 ;
        fc= c*c*c + 3*c - 5 ;

        if(fc==0)
        {
            Root=c ;
            break ;
        }

        cout<<i<< " th iteration root is :"<<c<<endl ;
        i++ ;
        if( fa * fc < 0)
            b= c;
        else
            a = c;
}
    cout<<endl ;
    cout<<"\t\t\t\t\t Root of the equation  : "<<Root<<endl ;
    return  0 ;
}
