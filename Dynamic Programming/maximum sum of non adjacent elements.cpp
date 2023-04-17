// Gfg link: https://bit.ly/3QOMRs1
// Top to Bottom Approach
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int maxsum(int *arr,int n, vector<int>& dp)
	{   if(n ==0)
	    {
	        return arr[0];
	    }
	    if(n<0)
	    {
	        return 0;
	    }
	    if(dp[n] != -1)
	    {
	        return dp[n];
	    }
	    int pick = arr[n] + maxsum(arr,n-2,dp);
	    int nopick = 0 + maxsum(arr,n-1,dp);
	    return dp[n] = max(pick,nopick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	    return maxsum(arr,n-1,dp);
	}
};