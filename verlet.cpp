#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
ofstream fout("my_verlet.dat");
double k=150,m=7.2,t=0.0,x=0.5,v=4.0,h=.01;
double f1(double x,double t,double v){
    return -(k*x)/m;
}
void verlet( double x0,double v0,double h){
    for(double t=0.0;t<=10;t=t+h){
        double xold = x;
        cout<<t<<"  "<<x<<"  "<<v<<endl;
        fout<<t<<"  "<<x<<"  "<<v<<endl;
        x+=h*v+h*h*0.5*f1(x,t,v);
        v+=h*0.5*(f1(x,t,v)+f1(xold,t,v));

    }
}
int main(){
verlet(x,v,h);
return 0;
}