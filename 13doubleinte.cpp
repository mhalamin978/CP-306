#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double f(double x,double y){
    return sin(x+y);
}
// inner integration over y 
double integration1(double x,double ymin,double ymax,int n){
    double h =(ymax-ymin)/n;
    double sum=0.0;
    for(int i=0;i<=n;i++){
        sum+=f(x,ymin+i*h);
    }
    return h*0.5*(f(x,ymin)+2*sum+f(x,ymax));
}

//outer integration over x
double integration2(double xmin,double xmax,int nx,int ny){
    double hx=(xmax-xmin)/nx;
    double sum=0.0;
    for(int i=0;i<=nx;i++){
        double x=xmin+i*hx;
        double ymax=log(x);
        double ymin=1/(exp(5*x));
        if(i==0||i==nx){
            sum+=integration1(x,ymin,ymax,ny);
        }
        else{
            sum+=2*integration1(x,ymin,ymax,ny);
        }
    }
    return hx*0.5*sum;
}
int main(){
    double x_min = 3.0, x_max = 5.0;
    int n_x = 100, n_y = 100;
    // Number of subintervals for x and y
    double result = integration2(x_min, x_max, n_x, n_y);

    cout << "The result of the double integration is: " << result << endl;
    return 0;
}