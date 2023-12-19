// Selection Sort
// In selection sort irst we have to search for the minimum element in the array
// In selection sort we run two for loops ; 1 st for loop is take the element for comparison, in 2nd for loop we compared the value of arr[i] and arr[j] if the value of arr[j] is less than arr[i] then we swap them and continue the loop 

#include<bits/stdc++.h>
using namespace std;

int main()
{ int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
    
  }
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          if(arr[j]<arr[i]){
              int temp = arr[j];
              arr[j] =arr[i];
              arr[i] = temp;
              

          }
      }
  }
  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";}

return 0;
}



