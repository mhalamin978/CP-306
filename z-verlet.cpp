#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
double k=150,m=7.2,t=0.1,x=0.5,v=0.4,h=0.5;
ofstream fout ("z-verlet.dat");
double f1(double x,double t,double v){
    double k=150,m=7.2;
    return -k*x/m;
}
double f2(double x,double t,double v){
    return v;
}
void verlet(double x0,double t0,double v0){

    for(double t=0; t<=10;t=t+0.01){
        double xold =x;
        x=x+h*v+h*(h/2)*f1(x,t,v);
        v=v+h/2*(f1(x,t,v)+f1(xold,t,v));
        fout<<t<<"   "<<x<<"/t"<<v<<endl;
    }
}
int main(){
verlet(x,t,v);
return 0;
}