#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double m=0;
    double A[6]={3,5,6,20,4,2};
    for(int i=0;i<=5;i++){
        if (A[i]>m){m =A[i];}
    }
    cout<<m<<endl;
    return 0;

}