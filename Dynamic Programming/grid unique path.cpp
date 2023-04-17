//leetcode link: https://leetcode.com/problems/unique-paths/
// Top to Bottom Approach
class Solution {
public:
    int unique(int r,int c,vector<vector<int>>& dp,int m,int n)
    {   if(r>=0 && r<=m && c>=0 && c<=n)
        {
            if(r == m && c == n)
            {
                return 1;
            }
            if(r == m && c != n)
            {
                return unique(r,c+1,dp,m,n);
            }
            if(c == n && r != m)
            {
                return unique(r+1,c,dp,m,n);
            }
            if(dp[r][c] != -1)
            {
                return dp[r][c];
            }
            return dp[r][c] = unique(r,c+1,dp,m,n) + unique(r+1,c,dp,m,n);
        }
        return 0;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return unique(0,0,dp,m-1,n-1);
    }
};