// Leetcode link: https://leetcode.com/problems/alien-dictionary/solution/
// Approach: 1. Considering topological sorting with khans algorithm.

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adjlist[K];
        vector<int>indegree(K,0);
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {   int prev = dict[i][j] - 97;
                    int suc = dict[i+1][j] - 97;
                    adjlist[prev].push_back(suc);
                    indegree[suc]++;
                    break;
                }
            }
        }
        queue<int>q;
        string ans;
        for(int i=0;i<K;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            for(auto it:adjlist[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
            ans = ans + char(node + 97);
            q.pop();
        }
        return ans;
        
    }
}