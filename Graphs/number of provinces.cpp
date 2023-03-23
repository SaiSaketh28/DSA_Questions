// leetcode link: https://leetcode.com/problems/number-of-provinces/description
// approch is toward going traversals

class Solution {

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int>vis(n,0);
        vector<int> adjlist[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1 &&  i!= j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i,adjlist,vis);
                count++;
            }
        }
        return count;
    }
    void dfs(int node,vector<int> adjlist[],vector<int>& vis)
    {
        vis[node] =1;
        for(auto it:adjlist[node])
        {   if(vis[it] == 0)
            dfs(it,adjlist,vis);
        }
    }
};