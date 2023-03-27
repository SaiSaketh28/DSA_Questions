// Topological sorting using DFS Traversal

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node,vector<int>& vis, vector<int> adj[],stack<int>& st)
	{
	    vis[node] = 1;
	    for(auto it:adj[node])
	    {
	        if(vis[it] == 0)
	        {
	            dfs(it,vis,adj,st);
	            st.push(it);
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    vector<int>ans;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i] == 0)
	        {
	            dfs(i,vis,adj,st);
	            st.push(i);
	        }
	    }
	    while(!st.empty())
	    {
	        auto node = st.top();
	        ans.push_back(node);
	        st.pop();
	    }
	    return ans;
	}
};