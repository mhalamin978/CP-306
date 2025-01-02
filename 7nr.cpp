#include<iostream>
#include<cmath>
using namespace std;
#define EPSILON 0.1

double f(double x){
    return x*x*x-x*x+2;
}
double deriv(double x){
    return 3*x*x-2*x;
}
void nr(double x){
    double h=f(x)/deriv(x);
    while (abs(h)>EPSILON){
        h=f(x)/deriv(x);
        x=x-h;
    }
    cout<<"solution: "<<x<<endl;
}

int main(){
    nr(2);
    return 0;
}