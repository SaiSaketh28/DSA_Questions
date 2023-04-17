// gfg link: https://bit.ly/3QCCpDQ
// same approach as maximum sum of non adjacent elements
class solution:
{
    public:
    //Function to find the maximum money the thief can get.
    int maxsum(int arr[], int n, vector<int>& dp)
    {   if(n == 0)
        {
            return arr[0];
        }
        if(n <0)
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
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+1,-1);
        return maxsum(arr,n-1,dp);
    }
};