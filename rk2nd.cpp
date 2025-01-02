#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double x, double t, double v){
        return v;
}
double f2(double x, double t, double v){
    double k=150, m=5;
        return (-k*x)/m;
}
void rk4(double t0, double tf, double x0, double v0){
    double k1,k2,k3,k4,l1,l2,l3,l4,s1,s2,h;
    ofstream fout("shm.dat");
    s1 = x0;
    s2=v0;
    h=.001;
    for(double t=t0;t<=tf;t+=h){
        k1=h*f1(s1, t , s2 );
        l1=h*f2(s1, t , s2 );
        k2=h*f1(s1+k1/2, t+h/2, s2+l1/2);
        l2=h*f2(s1+k1/2, t+h/2, s2+l1/2);
        k3= h*f1(s1+k2/2, t+h/2, s2+l2/2);
        l3= h*f2(s1+k2/2, t+h/2, s2+l2/2);
        k4=h*f1(s1+k3, t+h, s2+l3);
        l4=h*f2(s1+k3, t+h, s2+l3);


        s1+=(k1+2*k2+2*k3+k4)/6;
        s2+=(l1+2*l2+2*l3+l4)/6;
        fout<<t<<"    "<<s1<<"    "<<s2<<endl;
    }
}

int main(){
rk4(0,100,.5,4);
return 0;

}