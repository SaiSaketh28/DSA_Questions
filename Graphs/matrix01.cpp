// Leetcode Link: https://leetcode.com/problems/01-matrix/
// Approach: 1. Considering BFS Traversal

class Solution {
public:
    vector<int>dr = {+1,0,-1,0};
    vector<int>dc = {0,-1,0,+1};
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
                else
                {
                    mat[i][j] =-1;
                }
            }
        }
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] == -1)
                {
                    mat[nr][nc] = mat[r][c] +1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};