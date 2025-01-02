#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("14ode.dat");

//func for x
double f1(double x,double y){
    double alpha=1,beta=0.5;
    return alpha*x-beta*x*y;
}
//func for y 
double f2(double x,double y){
    double gamma =0.5,del =2;
    return gamma*x*y-del*y;
}
void euler(double x,double y,double h){

    for(double t=0;t<=30;t=t+h){
        x=x+h*f1(x,y);
        y=y+h*f2(x,y);
        fout<<t<<"\t"<<x<<"\t"<<y<<endl;
        cout<<t<<"\t"<<x<<"\t"<<y<<endl;
    }

}

int main(){
    euler(2,2,.01);
    return 0;
}