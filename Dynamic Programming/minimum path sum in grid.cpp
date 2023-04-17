// leetcodelink: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return minsum(grid,m-1,n-1,0,0,dp);
    }
    int minsum(vector<vector<int>>& grid,int m,int n,int r,int c,vector<vector<int>>& dp)
    {
        if(r>=0 && r<=m && c>=0 && c<=n)
        {
            if(r == m && c == n)
            {
                return grid[r][c];
            }
            if(dp[r][c] != -1)
            {
                return dp[r][c];
            }
return dp[r][c] = min(minsum(grid,m,n,r+1,c,dp),minsum(grid,m,n,r,c+1,dp)) + grid[r][c];
        }
        return INT_MAX;
    }
};