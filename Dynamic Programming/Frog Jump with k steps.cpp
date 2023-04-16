// gfg link: https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
class Solution {
  public:
    int mincost(vector<int>&height,int n,int k, vector<int>& dp)
    {   if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int cost =  INT_MAX;
        for(int i=1;i<=k;i++)
        {   if(n-i>=0)
            cost = min(cost,abs(height[n]-height[n-i])+mincost(height,n-i,k,dp));
        }
        return dp[n] = cost;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(100001,-1);
        return mincost(height,n-1,k,dp);
    }
};