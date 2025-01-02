#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double t,double x){
    return t*sqrt(x);
}
double rk4(double t0,double x0,double h){
    double k1,k2,k3,k4;

    k1=h*f1(t0,x0);
    k2=h*f1(t0+h/2,x0+k1/2);
    k3=h*f1(t0+h/2,x0+k2/2);
    k4=h*f1(t0+h,x0+k3);
    return x0 +(k1+2*k2+2*k3+k4)/6.0;
}


int main(){
    ofstream fout("4rk4.dat");
    double h = 0.01,x=1.0,t=0.0;
    for(double t=0.1;t<10.0;t=t+h){
        fout<<t<<"    "<<x<<"    "<< ((t*t+4)*(t*t+4)/16)<<endl;
        cout<<t<<"    "<<x<<"    "<< ((t*t+4)*(t*t+4)/16)<<endl;
        x=rk4(t,x,h);
}

    return 0;
}