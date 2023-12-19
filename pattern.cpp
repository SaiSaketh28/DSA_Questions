// Rectangle pattern

#include <iostream>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int rows, columns;
    cin >> rows >> columns;
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "*"<<" ";
            }
            cout << endl;
        }
    }
    return 0;
}


// Hollow rectangle pattern
/*
#include <iostream>
using namespace std;
int main()
{
    int row, column;
    cin>>row>>column;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if (i == 1 || i == row || j==1 || j== column)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout<<endl;
    }
    return 0;
}
*/

// Inverted Half Pyramid
/*
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
*/

// Half Pyramid of right aligned
/*
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        { if( j<=(n-i)){
          cout<<" ";
        }
          else{
          cout<<"*";
          }
        }
        cout<<endl;
    }
    return 0;
}
*/

//Half Pyramid using numbers
/*
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        if(j<=i)
        {cout<<i;
        }
        cout<<endl;

    }
    return 0;
} 
*/

// Floyd's Triangle
/*
#include <iostream>
using namespace std;
int main(){
    int n,a;
    a =1;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<a<<" ";
            a++;
        }
        cout<<endl;

    }
    return 0;
} 
*/

// Butterfly Pattern
/*
#include <iostream>
using namespace std;
int main(){
    int n,space;
    cin>>n;

    for(int i=1;i<=n;i++)
    { int space = (2*n - 2*i);
        for(int j=1;j<=i;j++)
    {
        cout<<"*";
    }
      for(int j=1; j<=space; j++)
      {
          cout<<" ";
      }
      for(int j=1;j<=i;j++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
    for(int i=n;i>=1;i--)
    { int space = (2*n - 2*i);
        for(int j=1;j<=i;j++)
    {
        cout<<"*";
    }
      for(int j=1; j<=space; j++)
      {
          cout<<" ";
      }
      for(int j=1;j<=i;j++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
 return 0;
}
*/

// Inverted pattern
/*
#include<iostream>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n+1-i);j++)
        {
           cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

// 0-1 Pattern
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=i;j++)
    {
        if((i+j)%2 == 0)
        cout<<1<<" ";
        else
        cout<<0<<" ";
    }
    cout<<endl;
    }
    return 0;
    
}
*/

// Rhombus Pttern
/*
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }
  cout<<endl;
    }
  return 0;
}
*/

// Number Pattern
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
          cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

// Palidromic Pattern
/*
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
    for(int i=1;i<=(n);i++)
    {   int j;
        for(  j=1;j<=(n-i);j++)
        { 
            cout<<" ";
        }
        int k=i;
        for(;j<=n;j++)
        {
            cout<<k--<<"";
        }
        k=2;
        for(;j<=n+i-1;j++)
        {
            cout<<k++<<"";
        }
        cout<<endl;
    }
    return 0;
}
*/

// Star pattern
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(2*i -1);j++)
        {
            cout<<"*"; 
        }
        cout<<endl;
    }
     for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(2*i -1);j++)
        {
            cout<<"*"; 
        }
        cout<<endl;
    }
     return 0;
}
*/

// Zig Zag Pattern
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if( (i+j)%4 == 0)
            {
                cout<<"*";
            }
            else if(i==2 && j%4 ==0)
            {
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}
*/



