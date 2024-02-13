#include<iostream>
#include<cmath>
using namespace std;


int main(){
/*
///////////////Intro to array ///////////
int d;
 int a[5]={1,2,3,4,5};
cin>>d;
cout<<a[d]<<endl;
return 0; */

////////////////max number ////////////
int A[5]={2,40,5,600,70};
int m = A[0];
for (int i = 0; i < 5; i++){
    if(m > A[i]) {m = A[i];}
    cout<<m<<endl;
}
cout<<m<<endl;
return 0;
}