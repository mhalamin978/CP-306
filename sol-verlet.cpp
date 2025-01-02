# include<iostream>
# include<cmath>
# include<fstream>
using namespace std;
ofstream fout ("verlet.dat");
double k=150.0,m=7.2,t=0.0,x=0.5,v=4.0,h=0.01;
double fn1(double t,double x,double v) {
double F=(-k*x)/m;
return F; }
double fn2(double t,double x,double v)
{ return v; }
void verlet(double h,double t0,double x0,double v0) {
for(double t=t0;t<10;t+=h)
{
double xold=x;
cout<<t<<" "<<x<<" "<<v<<endl;
fout<<t<<" "<<x<<" "<<v<<endl;
x+=h*v+((h*h)/2.0)*fn1(t,x,v);
v+=(h/2.0)*(fn1(t,xold,v)+fn1(t,x,v));
}
}
int main() {
verlet(h,t,x,v);
return 0; }