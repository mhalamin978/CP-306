#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define RAND_MAX 0x7fff
using namespace std;
double f(double x){
    return 1/(1+sin(x)*sin(x));
}
double mc(double func(double),double a,double b,double c,double d,double n){
    double S=0,x,y;
    for(int i=0;i<=n;i++){
        x=a+(b-a)*(double)rand()/RAND_MAX;
        y=c+(d-c)*(double)rand()/RAND_MAX;
        if(y<=f(x)){S++;}
    }
    return (S/n)*(b-a)*(d-c);
}
int main(){
    cout<<mc(f,0,M_PI/2,-.3,.9,10000);
    return 0;
}