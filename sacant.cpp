#include<iostream>
#include<cmath>
#define epsilon .0001
using namespace std;

double func(double x){
    return x*x-7*x-12;
}
void sacant(double a, double b){
    double x1, x2,x0;
    x1=a;
    x2=b;
    if((func(a)-func(b)) !=0){
        while (abs(x2-x1)>=epsilon){
            x0=(func(x2)*x1 - func(x1)*x2)/(func(x2)-func(x1));
            x2 =x0;
            x1=x2;
        }
        cout<<x2<<endl;
    }
    else{ cout<<"cant' be solve"<<endl;}
}

int main(){
sacant(-2,4);
return 0;


}