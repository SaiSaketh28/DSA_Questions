class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {   // first row
            if(grid[0][j] == 1)
            {
                dfs(0,j,vis,grid);
            }
            // last row
            if(grid[m-1][j] == 1)
            {
                dfs(m-1,j,vis,grid);
            }
        }
        for(int i=0;i<m;i++)
        {   // first column
            if(grid[i][0] == 1)
            {
                dfs(i,0,vis,grid);
            }
            // last column
            if(grid[i][n-1] == 1)
            {
                dfs(i,n-1,vis,grid);
            }
        }
        int count =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int row, int column, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        vis[row][column] = 1;
        vector<int>dr = {+1,0,-1,0};
        vector<int>dc = {0,-1,0,+1};
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + dr[i];
            int ncolumn = column + dc[i];
            if(nrow >=0 && nrow<m && ncolumn>=0 && ncolumn<n)
            {
                if(vis[nrow][ncolumn] == 0 && grid[nrow][ncolumn] == 1)
                {
                    dfs(nrow,ncolumn,vis,grid);
                }
            }
        }
    }

};