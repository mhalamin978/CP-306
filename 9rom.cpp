#include<iostream>
#include<cmath>
using namespace std;

double f(double x){
    return x;
}
double romberg(double a , double b ,int n,int m){
    double TRP[10][10]={0};
    double x,sum, factor,h;
    h=(b-a)/n;
    
    //romberg initialization of TRP[0][0],[1][0]..
    for(int k=0;k<=m;k++){
        double sum=0.0;
        for(int i=1;i<=n;i++){
            sum=sum+f(a+i*h);
        }
        TRP[k][0]=h*0.5*(f(a)+2*sum+f(b));
        h=h/2; n=n*2;
    }

    //richardson exterpolation 
    for(int i=1;i<=m;i++){
        for(int j=1;j<=i;j++){
            factor =pow(4,(j));
            TRP[i][j]=(factor*TRP[i][j-1]-TRP[i-1][j-1])/(factor -1);
        }
    }
    return TRP[m][m];
}


int main(){
    cout<<romberg(1,2,10,3)<<endl;
    return 0;
}