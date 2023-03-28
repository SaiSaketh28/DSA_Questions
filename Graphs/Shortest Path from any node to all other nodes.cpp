// GFG link: https://bit.ly/3UVQD4C
// Approach : BFS Traversal from given source node.

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>distance(N,0);
        queue<pair<int,int>>q;
        vector<int>vis(N,0);
        vector<int> graph[N];
        for(int i=0;i<M;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // parent node , parent distance.
        q.push({src,0});
        vis[src] = 1;
        distance[src] = 0;
        while(!q.empty())
        {
            int parent_node = q.front().first;
            int parent_distance = q.front().second;
            q.pop();
            for(auto adj_node:graph[parent_node])
            {
                if(distance[adj_node] == 0 && vis[adj_node] == 0)
                {
                    distance[adj_node] = parent_distance + 1;
                    vis[adj_node] = 1;
                    q.push({adj_node,distance[adj_node]});
                }
                else
                { 
                    int current = parent_distance + 1;
                    int prev = distance[adj_node];
                    distance[adj_node] = min(current,prev);
                    if(current<prev)
                    {
                        q.push({adj_node,distance[adj_node]});
                    }
                }
                
            }
            
        }
        for(int i=0;i<N;i++)
        {
            if(distance[i] == 0 && i != src)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};