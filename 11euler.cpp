#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//function:
double f(double y,double t){
    return -2*y+2-exp(-4*t);
}

//euler :
void euler(double y,double n){
    double h=0.01;
    for(double t=0.0;t<=5;t+=h){
        y+=h*f(y,t);
        cout<<t<<"    "<<y<<endl;
    }
}

int main(){
    euler(1,10);
    return 0;
}