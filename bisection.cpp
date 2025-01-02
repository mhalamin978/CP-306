#include<iostream>
#include<cmath>
#include<fstream>
#define epsilon 0.001;

using namespace std;
double f(double x){
    return x*x*x-x*x+2;
}
void bisection(double a, double b){

    if(f(a)*f(b)<0){
        double c;
        while(abs(b-a)>=0.1){
            c=(a+b)/2;
            if(abs(f(c))<0.1){break;}
            else if(f(a)*f(c)<0){
                b=c;
            }
            else{a=c;}
        }
        cout<<"solution: "<<c<<endl;
    }
    else{cout<<"wrong guess"<<endl;}
}

int main(){
    bisection(-3,5);
    return 0;
}