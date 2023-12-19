// 2D Arrays
// Declaration of 2D Array: <DataType> Namee[n][m]
// n denotes number of rows
// m denotes number of columns

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int x;
    cin>>x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==x)
            {cout<<"The element is found at position:"<<i<<j;}
        }
    }

 return 0;
}





