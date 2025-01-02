#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
    return x*x+1;
}
double trap(double a, double b, double n)
{
    double h,A,sum=0;
    h=(b-a)/n;
    for(int i=0;i<n;i++)
    {
        double y=a+i*h;
        sum=sum+f(y);
    }
    A=(h/2)*(f(a)+2*sum+f(b));
    return A;
}
int main()
{
    ofstream fout("trap.dat");
    for(double j=0;j<=10;j+=0.1){
    cout<<j<<"  "<<trap(0,j,1000000)<<endl;
    fout<<j<<"  "<<trap(0,j,1000)<<endl;}
    return 0;}