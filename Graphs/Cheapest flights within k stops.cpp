// Leetcode link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution
{
    public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int  k) 
    {
        vector<int>vis(n,0);
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        vector<pair<int,int>> adjlist[n];
        for(int i=0;i<flights.size();i++)
        {
            adjlist[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        // {stops,{node,distance}}
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int node = q.front().second.first;
            int cost = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            if(stops >k)
            {
                continue;
            }
            for(auto it:adjlist[node])
            {
                int adjnode = it.first;
                int edge_weight = it.second;
                if(cost + edge_weight < dist[adjnode]  && stops <=k)
                {
                    dist[adjnode] = cost + edge_weight;
                    q.push({stops+1,{adjnode,cost+edge_weight}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};