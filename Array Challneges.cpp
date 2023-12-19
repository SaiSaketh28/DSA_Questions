
#include <bits/stdc++.h>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        temp = max(arr[i],arr[i+1]);
        cout<<temp<<" ";
    }
    return 0;
}

