// leetcode link: https://leetcode.com/problems/rotting-oranges/
// Approach: 1. considering BFS traversal

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        int fo = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j] =2;
                }
                else
                {   if(grid[i][j] == 1)
                    {
                        fo++;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        vector<int>dr = {-1,0,+1,0};
        vector<int>dc = {0,-1,0,+1};
        int tm = 0;
        int ro =0;
        while(!q.empty())
        {
            auto node = q.front();
            int r = node.first.first;
            int c = node.first.second;
            int t = node.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1 && vis[nr][nc] != 2)
                {
                    q.push({{nr,nc},(t+1)});
                    vis[nr][nc] = 2;
                    ro++;
                }
            }
            tm = max(tm,t);
        }
        if(fo != ro)
        {
            return -1;
        }
        else
        {
            return tm;
        }
    }
};