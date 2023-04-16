// Leetcode link: https://bit.ly/3R2Xhn1
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adjlist[])
    {
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        int sum =0;
        while(!q.empty())
        {
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum = sum + wt;
            for(auto adjnode:adjlist[node])
            {
                if(vis[adjnode[0]] == 0)
                {
                    q.push({adjnode[1],adjnode[0]});
                }
            }
        }
        return sum;
    }
};