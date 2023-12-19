// Function is a piece of code that performs a specific task

/*  Syntax of a Function
  returntype functionName(parameter1,parameter2,-----------------){
   function body
  }
*/

// print all prime numbers between two numbers a and b
/*
#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++)
  {
    if(num%i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{ int a,b;
  cin>>a>>b;
  for(int i=a;i<=b;i++)
  {
    if(isprime(i) == true)
    {
      cout<<i<<endl;
    }
  }
  return 0;
}
*/

// Fibenacci Sequence
/*
#include<iostream>
#include<math.h>
using namespace std;

void fib(int n){
   int t1=0;
   int t2=1;
   int nextTerm;

   for(int i=1;i<=n;i++){
     cout<<t1<<endl;
     nextTerm=t1+t2;
     t1=t2;
     t2=nextTerm;
   }
   return;
}

int main(){
  int n;
  cin>>n;
  fib(n);
  return 0;
}
*/

// Factorial of number n
/*
#include<iostream>
#include<math.h>
using namespace std;

int fact(int n){
  int factorial =1;
  for(int i=2;i<=n;i++){
    factorial = factorial*i;
  }
  return factorial;
}
int main(){
  int n;
  cin>>n;
  int ans= fact(n);
  cout<<ans;
  return 0;
}
*/

// calculation of nCr
/*
#include<iostream>
#include<math.h>
using namespace std;

int fact(int n){
  int factorial =1;
  for(int i=2;i<=n;i++){
    factorial = factorial*i;
  }
  return factorial;
}

int main(){
  int n,r;
  cin>>n>>r;
  int ans= (fact(n)/(fact(r)*fact(n-r)));
  cout<<ans;
  return 0;
}
*/
