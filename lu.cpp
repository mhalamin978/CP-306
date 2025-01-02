#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double A[20][20], l[10][10] = {0}, u[10][10] = {0}, b[10], x[10] = {0}, y[10] = {0}, sum;
    int i,j,k,n,p;

    cout<<"Include the order of the matrix: " ;
    cin>> n;
    cout<<"Enter the matrix below"<<endl;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout<<"Enter the"<<i<<j<<" element of the matrix: ";
            cin>>A[i][j];
        }
        cout<<endl;
    }

    cout<<"The matrix you've entered is:"<< endl;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
 
    cout<<"Enter the b matrix\n";
    for(i = 1; i <= n; i++)
    {
        cout<<"Enter the "<< i<< "th element: ";
        cin>> b[i];
    }
    cout<< "The b matrix is\n" ;

    for(i = 1; i <= n; i++)
    {
        cout<<b[i]<<" ";
        cout<<endl;
    }

   
    for(k = 1; k <= n; k++)
    {
        u[k][k] = 1;
        for(i = k; i<= n; i++)
        {
            sum = 0;
            for(p = 1; p <= k - 1; p++)
            {
                sum += l[i][p] * u[p][k];
            }
            l[i][k] = A[i][k] - sum;

        }

        for(j = k + 1; j <=n; j++)
        {
            sum = 0;
            for(p = 1; p <= k - 1; p++)
            {
                sum += l[k][p] * u[p][j];
            }
            u[k][j] = (A[k][j] - sum) /l[k][k];
        }
    } 
  
   

    cout<<"The lower triangular matrix: "<<endl;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The upper triangular matrix is: "<<endl;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i = 1; i <= n; i++)
    {
        sum = 0;
        for(p = 0; p < i; p++)
        {
            sum += l[i][p] * y[p];
        }

        y[i] = (b[i] - sum) / l[i][i];

    }

    cout<< "The y matrix is\n" ;

    for(i = 1; i <= n; i++)
    {
        cout<<y[i]<<" ";
        cout<<endl;
    }

    for(i = n; i>=1; i--)
    {
        sum = 0;
        for(p = n; p > i; p--)
        {
            sum += u[i][p] * x[p];
        }

        x[i] = y[i] - sum;
    }    

    cout<< "The solutions are:\n" ;

    for(i = 1; i <= n; i++)
    {
        cout<<"x"<<i<<" = "<< x[i]<<" ";
        cout<<endl;
    }
}