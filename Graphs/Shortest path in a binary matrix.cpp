// GFG link: https://bit.ly/3ArrkzD
// Approach: 1. BFS Traversal from source node to Destination node and Dijkstras Algorithm.
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>cell_distance_from_source(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        q.push({{source.first,source.second},0});
        cell_distance_from_source[source.first][source.second] = 0;
        vector<int>dirc = {-1,0,1,0};
        int distance = INT_MAX;
        if(source == destination)
        {
            return 0;
        }
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int parent_distance = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + dirc[i];
                int nc = c + dirc[(i+1)%4];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if( grid[nr][nc] == 1)
                    {   if(cell_distance_from_source[nr][nc] == INT_MAX)
                        {
                            cell_distance_from_source[nr][nc] = min(cell_distance_from_source[nr][nc],parent_distance+1);
                            if(nr == destination.first && nc == destination.second)
                            {
                                distance = min(distance,parent_distance+1);
                            }
                            else
                            {
                                q.push({{nr,nc},parent_distance+1});
                            }
                        }
                        else
                        {
                            int prev = cell_distance_from_source[nr][nc];
                            int curr = parent_distance+1;
                            if(curr<prev)
                            {
                                cell_distance_from_source[nr][nc] = curr;
                                q.push({{nr,nc},curr});
                            }
                        }
                    }
                    
                }
            }
            
        }
        if(distance == INT_MAX)
        {
            return -1;
        }
        return distance;
        
    }
};