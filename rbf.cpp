#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double func(double x ){
    return x*x;
}
double rom(double a, double b, double n, int m){
    double h , I,factor, sum,x;
    h=(b-a)/n;
    double TRP[10][10];
    for(int k=0;k<=m;k++){
        sum =0;
    
        for(int i=1;i<=n;i++){

            sum+= func(a+i*h);

        }
        TRP[0][k]=h*0.5 *(func(a)+2*sum+func(b));
            h=h/2;
            n=n*2;

    }
    for(int i=1;i<=m;i++){
        for(int j=m-i;j>=0;j--){
            factor = pow(2,(i+1));
            TRP[i][j]=(factor*TRP[i-1][j+1]-TRP[i-1][j])/(factor-1);

        }
    }
    return TRP[m][0];
}
int main(){
    for(int m=0;m<=5;m++){
        cout<<m<<"  "<<rom(0,2,100,m)<<endl;
    }
    return 0;
}