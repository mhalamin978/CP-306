#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout("5rk4-sol.dat");
double k=150.0, m=7.2, t=0.0, x=0.5, v=4.0, dt=0.01;

double f(double t, double x, double v){
return v;
}
double g(double t, double x, double v){
return -k*x/m;
}
void rk4(double h, double t0, double x0, double v0){

double k1=h*f(t0,x0,v0);
double l1=h*g(t0,x0,v0);
double k2=h*f(t0+(h/2.0), x0+(k1/2.0),v0+(l1/2.0));
double l2=h*g(t0+(h/2.0), x0+(k1/2.0),v0+(l1/2.0));

double k3=h*f(t0+(h/2.0),x0+(k2/2.0),v0+(l2/2.0));
double l3=h*g(t0+(h/2.0),x0+(k2/2.0),v0+(l2/2.0));
double k4=h*f(t0+h,x0+k3,v0+l3);
double l4=h*g(t0+h,x0+k3,v0+l3);

t=t0+h;
x= x0+(k1+2*k2+2*k3+k4)/6.0;
v= v0+(l1+2*l2+2*l3+l4)/6.0;
fout<<t<<"   "<<x<<"   "<<v<<endl;
}
int main(){

while(t<=5){
rk4(dt,t,x,v);
}
return 0;
}