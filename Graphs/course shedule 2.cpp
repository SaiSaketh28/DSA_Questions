// Leetcode link: https://leetcode.com/problems/course-schedule-ii/
/*  Approach: 1. Considering topological sorting and DAG(Directed Acyclic Graph) properties
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre)
    {
        int v = numCourses;
        vector<int> adj[v];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        if(q.empty())
        {
            return ans;
        }
        else
        {
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it] == 0)
                    {
                        q.push(it);
                    }
                }
                ans.push_back(node);
            }
        }
        if(ans.size() != v)
        {   vector<int>dump;
            return dump;
        }
        return ans;
    }
};