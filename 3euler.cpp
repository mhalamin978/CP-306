#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout("3euler.dat");
double f1(double t,double y){
    return y-0.5*exp(0.5*t)*sin(5*t)+5*exp(0.5*t)*cos(5*t);
}
void euler(double t,double y , double h){
    for(double t;t<=10;t=t+h){
        y=y+h*f1(t,y);
        fout<<t<<"\t"<<y<<endl;
    }
}

int main(){
    euler(0.0,0.0,0.001);
    return 0;
}