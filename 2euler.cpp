#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout("2euler.dat");
double f1(double t,double y){
    return -2*y+2-exp(-4*t);
}
void euler(double t,double h , double y){
    for(double t=0.0;t<=5;t=t+h){
        y+=h*f1(t,y);
        cout<<t<<"    "<<y<<endl;
        fout<<t<<"    "<<y<<endl;
    }
}
int main(){
    euler(0.0,0.01,1);
    return 0;
}