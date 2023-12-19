// Subarray: continuous part of the array
// Number of Sub arrays of an array with n elements is nc2 + n = n(n+1)/2

// Subsequence: A subsequence is a sequence that can be derived an array by selecting zero or more elements,
// without chaning the order  of the remaining elements
// Number of subsequences of an array with n elements = 2^(n)

// Every Subarray is a Subsequence but every Subsequence is not a subaeeay

// Sum of all subarrays
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int curr;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {  curr =0;
        for(int j=i;j<n;j++)
        { curr = curr +arr[j];
        cout<<curr<<endl;

        }
    }
    return 0;
}
*/

// Longest Airthmetic Subarray
// An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal,
// For example [9,10],[3,3,3] and [9,7,5,3] are arithmetic arrays.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pd = arr[1]-arr[0];
    int ans=2;
    int j=2;
    int curr=2;

    while(j<n)
    {
        if(pd==(arr[j]-arr[j-1]))
        { 
            curr++;
        }
        else
        {
            pd = arr[j] - arr[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++ ;
    }
    cout<<ans<<endl;
    return 0;
}





