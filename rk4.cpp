#include<iostream>
#include<cmath>
#include<fstream>
using namespace std; 

double func(double x , double t ){
    return 2-exp(-4*t)-2*x;
}
double rk4(double n, double tf,double t0, double x0){
    ofstream fout("rk4.dat");
    double h = (tf-t0)/n;
    double k1,k2,k3,k4;
    double x =x0; 
    for(double t;t<=tf;t+=h){
        k1 = h*func(x,t);
        k2 = h*func(x+k1/2,t+h/2);
        k3 = h*func(x+k2/2,t+h/2);
        k4 = h*func(x+k3,t+h);
        x+=(k1+2*k2+2*k3+k4)/6;
        fout<< t <<"    "<<x <<endl;
    }
    return 0;
}

int main(){

rk4(10000, 5,0,1);
return 0; 

}