// gfg link: https://bit.ly/3glc9kp

class Solution {
  public:
    int maxpoints(vector<vector<int>>& points, int n, vector<vector<int>>& dp,int x)
    {   if(n == 0)
        {
          return points[0][x];
        }
        if(dp[n][x] != -1)
        {
            return dp[n][x];
        }
        int sum =0;
        if(x == 0)
        {
            sum = max(maxpoints(points,n-1,dp,1),maxpoints(points,n-1,dp,2));
        }
        else if(x == 1)
        {
            sum = max(maxpoints(points,n-1,dp,0),maxpoints(points,n-1,dp,2));
        }
        else
        {
            sum = max(maxpoints(points,n-1,dp,1),maxpoints(points,n-1,dp,0));
        }
        return dp[n][x] = sum + points[n][x];
    }
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        vector<vector<int>>dp(n,vector<int>(3,-1));
        int r = maxpoints(points,n-1,dp,0);
        int f = maxpoints(points,n-1,dp,1);
        int lp = maxpoints(points,n-1,dp,2);
        return max(r,max(f,lp));
    }
};