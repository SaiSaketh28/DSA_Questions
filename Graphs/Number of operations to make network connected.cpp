// Leetcode link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description
// Approach: Disjoint union method
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       vector<int>parent(n);
       for(int i=0;i<n;i++)
       {
           parent[i] = i;
       } 
       int total_edges = connections.size();
       int edge_count_used = 0;
       for(auto edge:connections)
       {
           int u = edge[0];
           int v = edge[1];
           if(findUPar(u,parent) != findUPar(v,parent))
           {
               parent[findUPar(v,parent)] = findUPar(u,parent);
               edge_count_used++;
           }
       }
       int vertices_unused = -1;
       for(int i=0;i<n;i++)
       {
           if(parent[i] == i)
           {
               vertices_unused++;
           }
       }
       if(total_edges-edge_count_used >= vertices_unused)
       {
           return vertices_unused;
       }
       return -1;
    }
    int findUPar(int node, vector<int>& parent)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node],parent);
    }
};