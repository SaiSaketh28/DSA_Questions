// Khans Algorithm -- Toplogical Sort-- Directed Acyclic Graph -- BFS Traversal
// Indegree of node is the number of Incoming edges for the node.
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // Khans Aalgorithm
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	        q.pop();
	        topo.push_back(node);
	    }
	    return topo;
	}
};