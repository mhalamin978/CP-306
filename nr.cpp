#include<iostream>
#include<cmath>
#define Epsilon .001
using namespace std;

double func(double x){
    return x*x-7*x+12;
}
double diff(double x){
  return  2*x-7;
}
void nr(double x){
    double h = func(x)/diff(x);
    while (abs(h)>= Epsilon ){ 
        h = func(x)/diff(x);
        x =x-h;
    }
    cout<<"   "<< x;
}

int main(){
    nr(20);
}