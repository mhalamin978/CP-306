#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double f(double x){
    return x*x*x - x*x + 2; 
}
void bisection(double a, double b,double epsilon){
    if(f(a)*f(b)<0){
        double c;
        while(abs(b-a)>epsilon){
            c=(a+b)/2;
            if(abs(f(c))<epsilon){break;}

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
    bisection(-3,10,0.1);
return 0;
}