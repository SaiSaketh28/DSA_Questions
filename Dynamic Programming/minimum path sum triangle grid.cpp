// leetcode link: https://leetcode.com/problems/triangle/description

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return mintotal(triangle,m-1,dp,0,0);
    }
    int mintotal(vector<vector<int>>& triangle,int m,vector<vector<int>>& dp,int r,int c)
    {
        if(r>=0 && r<=m)
        {
            if(r == m)
            {
                return triangle[r][c];
            }
            if(dp[r][c] != -1)
            {
                return dp[r][c];
            }
return dp[r][c] = min(mintotal(triangle,m,dp,r+1,c),mintotal(triangle,m,dp,r+1,c+1)) + triangle[r][c];
        }
        return INT_MAX;

    }
};