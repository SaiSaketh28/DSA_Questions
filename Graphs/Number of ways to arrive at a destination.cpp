// Leetcode link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Approach: Using Dijstras Algorithm

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {   vector<pair<long long,long long>> adjlist[n];
        for(int i=0;i<roads.size();i++)
        {
            adjlist[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long >dist(n,LLONG_MAX);
        vector<long long >ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        int M = int(1e9 + 7);    
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});
        // {dist,node};
        while(!q.empty())
        {
            auto it = q.top();
            long long distance = it.first;
            long long  node = it.second;
            q.pop();
            for(auto iter:adjlist[node])
            {
                long long adjnode = iter.first;
                long long  edge_weight = iter.second;
                if((distance + edge_weight)%M < dist[adjnode]%M )
                {
                    dist[adjnode] = (distance + edge_weight)%M;
                    ways[adjnode] = ways[node];
                    q.push({dist[adjnode],adjnode});
                }
                else if(distance + edge_weight == dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};