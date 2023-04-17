// leetcode link: https://leetcode.com/problems/unique-paths-ii/
// Getting TLE error for this code
class Solution {
public:
    int unique(int r,int c,vector<vector<int>>& obg,vector<vector<int>>& dp,int m,int n)
    {
        if(r>=0 && r<=m && c>=0 && c<=n)
        {
            if(r == m && c == n)
            {
                return 1;
            }
            if(obg[r][c] == 1)
            {
                return 0;
            }
            return dp[r][c] = unique(r,c+1,obg,dp,m,n) + unique(r+1,c,obg,dp,m,n);
        }
        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        return unique(0,0,obstacleGrid,dp,m-1,n-1);
    }
};