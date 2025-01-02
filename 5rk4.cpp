#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("5rk4.dat");
double k=150,m=7.2,x=0.5,v=4,t=0.0,h=0.01;

//function for v and l
double g(double x,double t,double v){
    return -(k*x)/m;
}
//function for x and k 
double f( double v){
    return v;
}
void rk4(double x0,double t0,double v0,double h){
    double l1,l2,l3,l4;
    double k1,k2,k3,k4;

    //l function are for v and g
    l1=h*g(x0,t0,v0);
    l2=h*g(x0+k1/2,t0+h/2,v0+l1/2);
    l3=h*g(x0+k2/2,t0+h/2,v0+l2/2);
    l4=h*g(x0+k3,t0+h,v0+l3);

    //k func are for x and f 
    k1=h*f(v0);
    k2=h*f(v0+l1/2);
    k3=h*f(v0+l2/2);
    k4=h*f(v0+l3);
    //
    t=t0+h;
    x=x0+(k1+2*k2+2*k3+k4)/6;
    v=v0+(l1+2*l2+2*l3+l4)/6;
    fout<<t<<"\t"<<x<<"\t"<<v<<endl;
}
int main(){
while(t<=5){
    rk4(x,t,v,h);
}
return 0;
}