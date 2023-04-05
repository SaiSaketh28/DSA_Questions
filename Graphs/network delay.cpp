// Leetcode link: https://leetcode.com/problems/network-delay-time/
// Approach: Using BFS Traversal

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int>vis(n+1,0);
        vector<int>total_time(n+1,INT_MAX);
        total_time[k] = 0;
        queue<pair<int,int>>q;
        vector<pair<int,int>> adjlist[n+1];
        for(int i=0;i<times.size();i++)
        {
            adjlist[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        q.push({k,0});
        vis[k] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent_node_time = q.front().second;
            q.pop();
            for(auto adjnode:adjlist[node])
            {   
                if(vis[adjnode.first] == 0)
                {
                    vis[adjnode.first] = 1;
                    int time = adjnode.second + parent_node_time;
                    total_time[adjnode.first] = min(time,total_time[adjnode.first]);
                    q.push({adjnode.first,time});
                }
                else
                {
                    int prev_time = total_time[adjnode.first];
                    int curr_time = adjnode.second + parent_node_time;
                    if(curr_time<prev_time)
                    {
                        total_time[adjnode.first] = curr_time;
                        q.push({adjnode.first,curr_time});
                    }
                }
            }
        }
        int answer = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            answer = max(answer,total_time[i]);
        }
        return answer==INT_MAX ?-1:answer;
    }
};