#include<iostream>
#include<cmath>
using namespace std;

double f(double t){
    return (2/sqrt(M_PI))*exp(-(t*t));
}

double T (double t ){
double h, A , I=0, J=0, K=0;
double a=0 , b=8/sqrt(t) , n; 
int i;
h =(b-1)/n;
for(int i=0;i<=n;i=i+h){
    I+= f(a+i*h);
}
J =(h/2)*( f(a)+2*I+f(b));
cout<<t<< J <<endl;
return 100*(1-J);
}

int main(){

for(int t=0; t<=10;t++){
    //cout<<t<<"  "<<
     T(t);
}
return 0;
}