queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(vis[it] == 0)
                {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if(vis[it] == 1 && it != parent)
                {
                    return true;
                }
            }
        }