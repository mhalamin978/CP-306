#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double g=9.8,l=10,c=2;
double f1(double omega,double theta,double t)
{
    return omega;
}
double f2(double omega,double theta,double t)
{
    return -(g/l)*theta+c*cos(theta)*sin(omega*t);
}
void rk44(double t0,double tf,double n,double theta0,double omega)
{
    ofstream fout ("rk44.dat");
    double theta=theta0;
    double h=(tf-t0)/n;
    double k1,k2,k3,k4;
    double l1,l2,l3,l4;
    for (double t=t0;t<=tf;t+=h)
    {
        k1=h*f1(omega,theta,t);
        l1=h*f2(omega,theta,t);
        k2=h*f1(omega+(l1/2),theta+(k1/2),t+(h/2));
        l2=h*f2(omega+(l1/2),theta+(k1/2),t+(h/2));
        k3=h*f1(omega+(l2/2),theta+(k2/2),t+(h/2));
        l3=h*f2(omega+(l2/2),theta+(k2/2),t+(h/2));
        k4=h*f1(omega+l3,theta+k3,t+h);
        l4=h*f2(omega+l3,theta+k3,t+h);
        theta+=(k1+(2*k2)+(2*k3)+k4)/6;
        omega+=(l1+(2*l2)+(2*l3)+l4)/6;
        fout<<t<<" "<<omega<<" "<<theta<<" "<<endl;
    }
}
int main ()
{
    rk44(0,20,100,5,4);
    return 0;
}