
#include<iostream>
#include<cmath>
using namespace std;
double e=0.0001;
double f (double x)
{
    return x*sin(x)+cos(x);
}
void bi(double a, double b)
{
    if ( f(a)* f(b)>0)
    {
        cout<<"no solution"<<endl;
return ;
}
double c;
while(abs(b-a)>=e)
{
    c=(a+b)/2;
    if(f(c)==0)
break;
else if (f(a)*f(b)<0)
{b=c;}
else{a=c;}
}
cout<<c<<endl;}

int main()
{
    bi(-3,2);
    return 0;
}
