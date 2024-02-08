#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout ("euler.dat");
double f(double t, double y){
    return 2-exp(-4*t)-2*y;
}
void euler(double h, double t0, double y0){
    double y = y0;
    for (double t = t0; t <=50; t+=h)
    {
        fout<<t<<"    "<<y<<"    "<<1+.5*exp(-4*t)-0.5*exp(-2*t)<<endl;
        y+= h*f(t,y);
    }
    
}

int main(){
euler(.1,0.0,1.0);
return 0;

}