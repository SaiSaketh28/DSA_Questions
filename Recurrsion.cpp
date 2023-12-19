// Recursion
// A function that calls itself is known as a recursive function. And, this technique is known as recursion.

// Factorial of a number throuhg recursion

#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }
    
    else if(n>1){
        return n*fact(n-1); 
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}

