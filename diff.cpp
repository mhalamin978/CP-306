#include<iostream>
#include<cmath>
using namespace std;
double f(double x) { return 10*pow(x,3)+3*x;}
double diff(double x,double h){
    double d;
    d = f(x+h)-f(x-h);
    return d/(2*h);
}
int main(){
double d,h;
cout<<diff(2,.1)<<endl;
return 0;
}