#include<iostream>
#include<cmath>
using namespace std;

double f(double x){
    return 3*x*x+5*x;
}
double diff(double x, double h){
    double d = f(x+h)-f(x-h);
    return d/(2*h);
}
int main(){
    cout<<diff(2,.1)<<endl;
    return 0;
}