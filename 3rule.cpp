#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

double f(double x){
float y =3*x*x;
return y; 
}
double simp(double n, double a , double b){
    double even;
    double odd;
    double d = (b-a)/n;
    for(int i=1;i<=n;i=i+2){even +=f(a+i*d);}
    for(int j=1;j<=n;j=j+2){odd +=f(a+j*d);}
    double s = d/3*(f(a)+4*even+2*odd+f(b));
    cout<<s<<endl;
    return s;
}

int main(){
double n=500;
double a = 1;
double b= 2;
simp(n,a,b);
cout<<"simp -> "<<simp(n,a,b)<<endl;
return 0;
}