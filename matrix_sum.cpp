#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    double C[20][20];
cout<<"Give the matrix order"; cin>>n;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<"give the element name: "; cin>>C[i][j];
    }
}
for(int i =1;i<=n;i++){
    for(int j=1;j<=n; j++){
        cout<<C[i][j]<<"    ";
    }
    cout<<endl;
}
}

