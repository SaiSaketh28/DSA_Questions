// Pointers
// Pointers are the variables that stores the address of other variables
// By using variables we can acesse the elemnts and also can modify the elements

/* CODE

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    a=30;
    int *aptr;
    aptr = &a;
    cout<<&a<<endl;
    cout<<*aptr<<endl;
    cout<<aptr<<endl;
    return 0;

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int increment(int *a){
    *a = *a+1;
    return *a;
}
int main()
{  int b;
   cin>>b;
   int *ptr=&b;
   cout<<increment(ptr)<<endl;
   cout<<b;
    return 0;
}
*/
