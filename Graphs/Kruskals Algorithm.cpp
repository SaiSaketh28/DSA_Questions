class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int node = i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,adjnode}});
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        int sum = 0;
        for(auto it:edges)
        {
            int u = it.second.first;
            int v = it.second.second;
            int weight = it.first;
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                sum = sum +weight;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
};