#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

double func(double x ){
    return sin(x);
}
double monte(double a,double b, double c, double d, int N){
    double N0=0;
    for(int i=1;i<=N;i++){
        double x , y;
        x=a+(b-a)*(double)rand()/RAND_MAX;
        y=c+(d-c)*(double)rand()/RAND_MAX;
        if(y<=func(x))
            N0++;
        
    }
    return (N0/N)*(b-a)*d;

}

int main(){
cout<<monte(0,M_PI/2,0,2,10000)<<endl;
return 0;

}