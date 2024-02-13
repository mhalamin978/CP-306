#include<iostream>
#include<cmath>

using namespace std;
int main(){
double A[3][3]={1,2,3,4,5,6,7,8,9};
for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){
        cout<<A[i][j]<<'\t';
    }
    cout<<endl;
}


}