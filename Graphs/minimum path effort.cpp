// Leetcode link: https://leetcode.com/problems/path-with-minimum-effort/
// Approach: 1. Considering Dijkstras Algorithm

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<int>dirc = {-1,0,1,0};
        int n = heights.size();
        int m = heights[0].size();
        pair<int,int>dest = {n-1,m-1};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!q.empty())
        {
            int diff = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            pair<int,int>node = {r,c};
            q.pop();
            if( node == dest)
            {
                return diff;
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    int nr = r + dirc[i];
                    int nc = c + dirc[(i+1)%4];
                    if(nr>=0 && nr<n && nc>=0 && nc<m)
                    {
                    int new_effort = max(abs(heights[nr][nc] - heights[r][c]),diff);
                        if(new_effort < dist[nr][nc])
                        {
                            q.push({new_effort,{nr,nc}});
                            dist[nr][nc] = new_effort;
                        }
                    }
                }
            }
        }
        return 0;
    }
};