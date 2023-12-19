#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    temp =0;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            temp = temp +1;
        }

    }
    if(temp == 0){
        cout<<"the number is prime";
    }
    else{
        cout<<"the number is not a prime";
    }
    return 0;
}
