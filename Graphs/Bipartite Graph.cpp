// Leetcode link: https://leetcode.com/problems/is-graph-bipartite/
// No two adjacent nodes in graph should have same color 
// If we try to color the graph by two colors for alternative nodes
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);
        queue<pair<int,int>>q;
        // node,color(0/1)
        for(int i=0;i<v;i++)
        {   
            if(color[i] == -1)
            {
                q.push({i,0});
                color[i] = 0;
                while(!q.empty())
                {
                    int node = q.front().first;
                    int parent_color = q.front().second;
                    for(auto it:graph[node])
                    {
                        int temp = parent_color?0:1;
                        if(color[it] == -1)
                        {   
                            color[it] = parent_color?0:1;
                            q.push({it,color[it]});
                        }
                        else if(color[it] == temp)
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    q.pop();
                }
            }    
        }
        return true;
    }
};